import sys;

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

def dependencyA(node):
    if node.has_dependency():
        return Node(node.layer + 1, int(node.index / 2), node.depth)
    else:
        return None

def dependencyB(node):
    if node.has_dependency():
        return Node(node.layer + 1, int(node.index / 2) + 1, node.depth)
    else:
        return None

def class_code(node):
    if node.has_dependency():
        return """
class {class_name} {{
public:
    {class_name}({depA_class}& depA, {depB_class}& depB)
        : m_depA(depA)
        , m_depB(depB)
    {{}}

private:
    {depA_class}& m_depA;
    {depB_class}& m_depB;
}};""".format(class_name=class_name(node), depA_class=class_name(dependencyA(node)), depB_class=class_name(dependencyB(node)))
    else:
        return """
class {class_name} {{
public:
    {class_name} () {{}}

private:
    int foo = 0;
}};""".format(class_name=class_name(node))

def layer_size(layer, depth):
    inverse_layer = depth - layer - 1
    return 1 << inverse_layer

def iterate_node(depth, func):
    for layer in range(0, depth):
        for index in range(0, layer_size(layer, depth)):
            func(Node(depth - layer - 1, index, depth))

def main():
    depth = int(sys.argv[1])
    output_path = sys.argv[2] + "/gen_test.h"
    output_path_kangaru = sys.argv[2] + "/gen_test.kangaru.h"
    output_path_manual = sys.argv[2] + "/gen_test.manual.h"

    with open(output_path, 'w+') as output_file:
        output_file.write("#pragma once\n")

        def write_class(node):
            output_file.write(class_code(node))
            output_file.write("\n")

        iterate_node(depth, write_class)

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
                output_file.write("    {class_name}* {instance_name} = new {class_name}(*{depA}, *{depB});\n".format(class_name=cname, instance_name=iname,depA=dA,depB=dB))
            else:
                pass
                output_file.write("    {class_name}* {instance_name} = new {class_name}();\n".format(class_name=cname, instance_name=iname))

        iterate_node(depth, write_create_manually)

        output_file.write("    return instance_0_0;\n")
        output_file.write("}\n")

    
    with open(output_path_kangaru, 'w+') as output_file:
        output_file.write("#pragma once\n")

        output_file.write("#include \"gen_test.h\"\n")
        output_file.write("#include <kangaru/kangaru.hpp>\n")

        def write_kangaru_service(node):
            output_file.write("struct {class_name}Service : kgr::single_service<{class_name}, kgr::autowire> {{}};\n".format(class_name=class_name(node)))
            output_file.write("auto service_map({class_name} const&) -> {class_name}Service;\n".format(class_name=class_name(node)))
        iterate_node(depth, write_kangaru_service)

if __name__ == "__main__":
    main()