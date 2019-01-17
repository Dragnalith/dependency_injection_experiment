#include "ConstructorTraits.h"
#include "ServiceContainer.h"

#include "ModuleA.h"
#include "ModuleB.h"

#include <assert.h>

#if 1
#include <test/gen_test.container.h>

void benchmark_test()
{
    drgn::ServiceContainer container;
    init_container(container);
    container.Initialize();

    MyClass_0_0& a = container.Get<MyClass_0_0>();
    MyClass_1_0& b = container.Get<MyClass_1_0>();

    assert(&a.m_dep1_0 == &b);
}
#endif

void FinalizeModuleA(ModuleA* ptr)
{
    delete ptr;
}

void FinalizeModuleB(ModuleB* ptr)
{
    delete ptr;
}

ModuleA* CreateModuleA()
{
    return new ModuleA();
}

ModuleB* CreateModuleB(ModuleA& moduleA)
{
    return new ModuleB(moduleA, &moduleA, moduleA);
}

void simple_test()
{
    drgn::ServiceContainer container;
    container.Register<ModuleA>();
    container.Register<ModuleB>();

    container.Initialize();

    ModuleA& a0 = container.Get<ModuleA>();
    ModuleB& b0 = container.Get<ModuleB>();
    ModuleA& a1 = container.Get<ModuleA>();
    ModuleB& b1 = container.Get<ModuleB>();

    assert(&a0 == &a1);
    assert(&b0 == &b1);
    assert(&a0 == &b0.m_moduleA);
}

int main()
{
    simple_test();
    benchmark_test();
    return 0;
}

