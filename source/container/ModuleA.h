#pragma once

#include "Result.h"

struct Setting {
    int Value;
    bool IsEnabled;
};

class ModuleA {
public:
    ModuleA(const Setting& setting)
        : m_setting(setting)
    {
    }

    drgn::Result Initialize()
    {
        return drgn::ResultSuccess();
    }
    int m_value = 42;
    const Setting& m_setting;
};
