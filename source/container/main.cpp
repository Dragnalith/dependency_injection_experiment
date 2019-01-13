#include "ServiceContainer.h"

#include "ModuleA.h"
#include "ModuleB.h"

ModuleA* InitModuleA(drgn::ServiceContainer& container)
{
    return new ModuleA();
}

void FinalizeModuleA(ModuleA* ptr)
{
    delete ptr;
}

ModuleB* InitModuleB(drgn::ServiceContainer& container)
{
    return new ModuleB(container.Get<ModuleA>());
}

void FinalizeModuleB(ModuleB* ptr)
{
    delete ptr;
}

int main()
{
    drgn::ServiceContainer container;
    container.Register<ModuleA>(InitModuleA, FinalizeModuleA);
    container.Register<ModuleB>(InitModuleB, FinalizeModuleB);

    container.Initialize();

    ModuleA& a0 = container.Get<ModuleA>();
    ModuleB& b0 = container.Get<ModuleB>();
    ModuleA& a1 = container.Get<ModuleA>();
    ModuleB& b1 = container.Get<ModuleB>();


    return 0;
}