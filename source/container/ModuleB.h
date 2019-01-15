#pragma once

#include "ModuleA.h"

class ModuleB
{
public:
    ModuleB(ModuleA& moduleA, ModuleA* ptrModuleA)
        : m_moduleA(moduleA)
    {}

    void Change() {
        m_moduleA.m_value = 34;
    }
    ModuleA& m_moduleA;
};