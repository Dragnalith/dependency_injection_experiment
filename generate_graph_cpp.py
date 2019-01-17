import sys;
import os;

class Node:
    def __init__(self, layer, index, depth):
        self.depth = depth
        self.layer = layer
        self.index = index

    def has_dependency(self):
        return self.depth != self.layer + 1

def instance_name(node):
    return "instance_{}_{}".format(node.layer,node.index)

def class_name(node):
    return "MyClass_{}_{}".format(node.layer,node.index)

def get_dependency(node, setting):
    return [Node(node.layer + 1, (setting.shift) * node.index + i, node.depth) for i in range(0, setting.width)]

def dependencyA(node):
    if node.has_dependency():
        return Node(node.layer + 1, node.index, node.depth)
    else:
        return None

def dependencyB(node):
    if node.has_dependency():
        return Node(node.layer + 1, node.index + 1, node.depth)
    else:
        return None

def class_code(node, setting):
    if node.has_dependency():
        dep1 = "\n".join(["        , m_dep{l}_{i}(dep{l}_{i})".format(l=d.layer, i=d.index) for d in get_dependency(node, setting)])
        dep2 = "\n".join(["    {}& m_dep{}_{};".format(class_name(d), d.layer, d.index) for d in get_dependency(node, setting)])
        dep3 = ",".join(["{}& dep{}_{}".format(class_name(d), d.layer, d.index) for d in get_dependency(node, setting)])
        return """
class {class_name} {{
public:
    {class_name}({dep3})
        : foo(0)
{dep1}
    {{}}

public:
    int foo;
{dep2}
}};""".format(class_name=class_name(node), dep1=dep1, dep2=dep2, dep3=dep3)
    else:
        return """
class {class_name} {{
public:
    {class_name} () {{}}

public:
    int foo = 0;
}};""".format(class_name=class_name(node))

def layer_size(layer, setting):
    assert(setting)
    a = setting.shift
    b = setting.width - setting.shift
    n = setting.depth - layer - 1

    assert(b >= 0)

    if a == 0:
        if n == 0:
            return 1
        else:
            return setting.width
    elif a == 1:
        return 1 + n * b
    else:
        an = a**n
        return an + b * (1 - an) // (1 - a)

def iterate_node(setting, func):
    for layer in range(0, setting.depth):

        for index in range(0, layer_size(layer, setting)):
            func(Node(setting.depth - layer - 1, index, setting.depth))

class Setting:
    def __init__(self, depth, width, shared):
        self.depth = depth
        self.width = width
        self.shift = width - shared

    def shared(self):
        return self.width - self.shift

def main():
    setting = Setting(int(sys.argv[1]), int(sys.argv[2]), int(sys.argv[3]))

    print("depth: {}, width: {}, shared: {}".format(setting.depth, setting.width, setting.shared()))

    count = 0
    for i in range(0, setting.depth):
        count += layer_size(i, setting)

    print("generated class count: {}".format(count))

    source_path = os.path.dirname(os.path.abspath(__file__))
    dest_folder = source_path + "/include/test/"
    output_path = dest_folder + "gen_test.h"
    output_path_kangaru = dest_folder + "gen_test.kangaru.h"
    output_path_kangaru2 = dest_folder + "gen_test.kangaru.2.h"
    output_path_manual = dest_folder + "gen_test.manual.h"
    output_path_container = dest_folder + "gen_test.container.h"

    with open(output_path, 'w+') as output_file:
        output_file.write("#pragma once\n")

        output_file.write("\n// {} classes has been generated.\n".format(count))
        def write_class(node):
            output_file.write(class_code(node, setting))
            output_file.write("\n")

        iterate_node(setting, write_class)

    with open(output_path_manual, 'w+') as output_file:
        output_file.write("#pragma once\n")

        output_file.write("#include \"gen_test.h\"\n")

        output_file.write("\nMyClass_0_0* create_manually() {\n")
        
        def write_create_manually(node):
            cname=class_name(node)
            iname=instance_name(node)
            if node.has_dependency():
                dA=instance_name(dependencyA(node))
                dB=instance_name(dependencyB(node))
                dep = ",".join(["*{}".format(instance_name(d)) for d in get_dependency(node, setting)])

                output_file.write("    {class_name}* {instance_name} = new {class_name}({dep});\n".format(class_name=cname, instance_name=iname,dep=dep))
            else:
                pass
                output_file.write("    {class_name}* {instance_name} = new {class_name}();\n".format(class_name=cname, instance_name=iname))

        iterate_node(setting, write_create_manually)

        output_file.write("    return instance_0_0;\n")
        output_file.write("}\n")

    
    with open(output_path_container, 'w+') as output_file:
        output_file.write("#pragma once\n")

        output_file.write("#include \"gen_test.h\"\n")
        output_file.write("#include <source/container/ServiceContainer.h>\n")

        output_file.write("\nvoid init_container(drgn::ServiceContainer& container) {\n")

        def write_container_register(node):
            output_file.write("    container.Register<{class_name}>();\n".format(class_name=class_name(node)))
        iterate_node(setting, write_container_register)

        output_file.write("\n}\n")


    with open(output_path_kangaru, 'w+') as output_file:
        output_file.write("#pragma once\n")

        output_file.write("#include \"gen_test.h\"\n")
        output_file.write("#include <kangaru/kangaru.hpp>\n")

        def write_kangaru_service(node):
            output_file.write("struct {class_name}Service : kgr::single_service<{class_name}, kgr::autowire> {{}};\n".format(class_name=class_name(node)))
            output_file.write("auto service_map({class_name} const&) -> {class_name}Service;\n".format(class_name=class_name(node)))
        iterate_node(setting, write_kangaru_service)

    with open(output_path_kangaru2, 'w+') as output_file:
        output_file.write("#pragma once\n")

        output_file.write("#include \"gen_test.h\"\n")
        output_file.write("#include <kangaru/kangaru.hpp>\n")

        def write_kangaru_service2(node):
            if node.has_dependency():
                dep = ",".join(["{}Service".format(class_name(d)) for d in get_dependency(node, setting)])

                output_file.write("struct {class_name}Service : kgr::single_service<{class_name}, kgr::dependency<{dep}>> {{}};\n".format(class_name=class_name(node),dep=dep))
            else:
                output_file.write("struct {class_name}Service : kgr::single_service<{class_name}> {{}};\n".format(class_name=class_name(node)))
            output_file.write("auto service_map({class_name} const&) -> {class_name}Service;\n".format(class_name=class_name(node)))
        iterate_node(setting, write_kangaru_service2)

if __name__ == "__main__":
    main()