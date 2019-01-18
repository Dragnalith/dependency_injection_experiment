#include "ConstructorTraits.h"
#include "ServiceContainer.h"

#include "ModuleA.h"
#include "ModuleB.h"

#include <fstream>
#include <assert.h>

#if 1
#include <test/gen_test.container.h>

void benchmark_test()
{
    drgn::ServiceContainer container;
    init_container(container);
    
    drgn::Result r = container.Initialize();
    assert(r.IsSuccess());

    std::ofstream file("benchmark.gv");
    container.RenderGraph(file);
    file.close();

    MyClass_0_0& a = container.Get<MyClass_0_0>();
    MyClass_1_0& b = container.Get<MyClass_1_0>();

    assert(&a.m_dep1_0 == &b);
}
#endif

void DestroyModuleA(ModuleA* ptr)
{
    delete ptr;
}

void DestroyModuleB(ModuleB* ptr)
{
    delete ptr;
}

ModuleA* CreateModuleA(const Setting& setting)
{
    return new ModuleA(setting);
}

ModuleB* CreateModuleB(ModuleA& moduleA, Setting& setting)
{
    return new ModuleB(moduleA, setting);
}

void simple_test()
{
    Setting setting;
    setting.IsEnabled = true;
    setting.Value = 666;

    drgn::ServiceContainer container;
    container.RegisterExternal<Setting>(&setting);
    container.Register<ModuleB>(CreateModuleB, DestroyModuleB);
    container.Register<ModuleA>(CreateModuleA, DestroyModuleA);

    drgn::Result r = container.Initialize();
    assert(r.IsSuccess());

    std::ofstream file("simple.gv");
    container.RenderGraph(file);
    file.close();

    ModuleB& b0 = container.Get<ModuleB>();
    ModuleA& a0 = container.Get<ModuleA>();
    ModuleA& a1 = container.Get<ModuleA>();
    ModuleB& b1 = container.Get<ModuleB>();

    assert(&a0 == &a1);
    assert(&b0 == &b1);
    assert(&a0 == &b0.m_moduleA);
    assert(&a0.m_setting == &setting);
}

int main()
{
    simple_test();
    benchmark_test();
    return 0;
}

