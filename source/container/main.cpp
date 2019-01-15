#include "ServiceContainer.h"
#include "ConstructorTraits.h"

#include "ModuleA.h"
#include "ModuleB.h"

#include <assert.h>

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
    return new ModuleB(moduleA, &moduleA);
}

int main()
{
    drgn::ServiceContainer container;
    container.Register<ModuleA>(CreateModuleA, FinalizeModuleA);
    container.Register<ModuleB>();

    container.Initialize();

    ModuleA& a0 = container.Get<ModuleA>();
    ModuleB& b0 = container.Get<ModuleB>();
    ModuleA& a1 = container.Get<ModuleA>();
    ModuleB& b1 = container.Get<ModuleB>();

    assert(&a0 == &a1);
    assert(&b0 == &b1);
    assert(&a0 == &b0.m_moduleA);

    return 0;
}