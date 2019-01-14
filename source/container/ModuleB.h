#pragma once

#include "ModuleA.h"

class ModuleB
{
public:
    ModuleB(ModuleA& moduleA)
        : m_moduleA(moduleA)
    {}

    ModuleA& m_moduleA;
};