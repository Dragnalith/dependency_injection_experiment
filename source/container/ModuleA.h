#pragma once

#include "Result.h"

class ModuleA {
public:
    drgn::Result Initialize() {
        return drgn::ResultSuccess();
    }
    int m_value = 42;
};
