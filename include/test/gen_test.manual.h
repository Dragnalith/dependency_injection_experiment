#pragma once
#include "gen_test.h"

MyClass_0_0* create_manually() {
    MyClass_4_0* instance_4_0 = new MyClass_4_0();
    MyClass_4_1* instance_4_1 = new MyClass_4_1();
    MyClass_4_2* instance_4_2 = new MyClass_4_2();
    MyClass_4_3* instance_4_3 = new MyClass_4_3();
    MyClass_4_4* instance_4_4 = new MyClass_4_4();
    MyClass_4_5* instance_4_5 = new MyClass_4_5();
    MyClass_4_6* instance_4_6 = new MyClass_4_6();
    MyClass_4_7* instance_4_7 = new MyClass_4_7();
    MyClass_4_8* instance_4_8 = new MyClass_4_8();
    MyClass_4_9* instance_4_9 = new MyClass_4_9();
    MyClass_4_10* instance_4_10 = new MyClass_4_10();
    MyClass_4_11* instance_4_11 = new MyClass_4_11();
    MyClass_4_12* instance_4_12 = new MyClass_4_12();
    MyClass_4_13* instance_4_13 = new MyClass_4_13();
    MyClass_4_14* instance_4_14 = new MyClass_4_14();
    MyClass_4_15* instance_4_15 = new MyClass_4_15();
    MyClass_3_0* instance_3_0 = new MyClass_3_0(*instance_4_0, *instance_4_1);
    MyClass_3_1* instance_3_1 = new MyClass_3_1(*instance_4_2, *instance_4_3);
    MyClass_3_2* instance_3_2 = new MyClass_3_2(*instance_4_4, *instance_4_5);
    MyClass_3_3* instance_3_3 = new MyClass_3_3(*instance_4_6, *instance_4_7);
    MyClass_3_4* instance_3_4 = new MyClass_3_4(*instance_4_8, *instance_4_9);
    MyClass_3_5* instance_3_5 = new MyClass_3_5(*instance_4_10, *instance_4_11);
    MyClass_3_6* instance_3_6 = new MyClass_3_6(*instance_4_12, *instance_4_13);
    MyClass_3_7* instance_3_7 = new MyClass_3_7(*instance_4_14, *instance_4_15);
    MyClass_2_0* instance_2_0 = new MyClass_2_0(*instance_3_0, *instance_3_1);
    MyClass_2_1* instance_2_1 = new MyClass_2_1(*instance_3_2, *instance_3_3);
    MyClass_2_2* instance_2_2 = new MyClass_2_2(*instance_3_4, *instance_3_5);
    MyClass_2_3* instance_2_3 = new MyClass_2_3(*instance_3_6, *instance_3_7);
    MyClass_1_0* instance_1_0 = new MyClass_1_0(*instance_2_0, *instance_2_1);
    MyClass_1_1* instance_1_1 = new MyClass_1_1(*instance_2_2, *instance_2_3);
    MyClass_0_0* instance_0_0 = new MyClass_0_0(*instance_1_0, *instance_1_1);
    return instance_0_0;
}
