#pragma once
#include "gen_test.h"

MyClass_0_0* create_manually() {
    MyClass_2_0* instance_2_0 = new MyClass_2_0();
    MyClass_2_1* instance_2_1 = new MyClass_2_1();
    MyClass_2_2* instance_2_2 = new MyClass_2_2();
    MyClass_1_0* instance_1_0 = new MyClass_1_0(*instance_2_0,*instance_2_1);
    MyClass_1_1* instance_1_1 = new MyClass_1_1(*instance_2_1,*instance_2_2);
    MyClass_0_0* instance_0_0 = new MyClass_0_0(*instance_1_0,*instance_1_1);
    return instance_0_0;
}
