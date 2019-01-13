#pragma once

#include "ModuleA.h"

class ModuleB
{
public:
    ModuleB(ModuleA& moduleA)
        : m_moduleA(moduleA)
    {}

private:
    ModuleA& m_moduleA;
};