#pragma once
#include "gen_test.h"

MyClass_0_0* create_manually() {
    MyClass_8_0* instance_8_0 = new MyClass_8_0();
    MyClass_8_1* instance_8_1 = new MyClass_8_1();
    MyClass_8_2* instance_8_2 = new MyClass_8_2();
    MyClass_8_3* instance_8_3 = new MyClass_8_3();
    MyClass_8_4* instance_8_4 = new MyClass_8_4();
    MyClass_8_5* instance_8_5 = new MyClass_8_5();
    MyClass_8_6* instance_8_6 = new MyClass_8_6();
    MyClass_8_7* instance_8_7 = new MyClass_8_7();
    MyClass_8_8* instance_8_8 = new MyClass_8_8();
    MyClass_7_0* instance_7_0 = new MyClass_7_0(*instance_8_0, *instance_8_1);
    MyClass_7_1* instance_7_1 = new MyClass_7_1(*instance_8_1, *instance_8_2);
    MyClass_7_2* instance_7_2 = new MyClass_7_2(*instance_8_2, *instance_8_3);
    MyClass_7_3* instance_7_3 = new MyClass_7_3(*instance_8_3, *instance_8_4);
    MyClass_7_4* instance_7_4 = new MyClass_7_4(*instance_8_4, *instance_8_5);
    MyClass_7_5* instance_7_5 = new MyClass_7_5(*instance_8_5, *instance_8_6);
    MyClass_7_6* instance_7_6 = new MyClass_7_6(*instance_8_6, *instance_8_7);
    MyClass_7_7* instance_7_7 = new MyClass_7_7(*instance_8_7, *instance_8_8);
    MyClass_6_0* instance_6_0 = new MyClass_6_0(*instance_7_0, *instance_7_1);
    MyClass_6_1* instance_6_1 = new MyClass_6_1(*instance_7_1, *instance_7_2);
    MyClass_6_2* instance_6_2 = new MyClass_6_2(*instance_7_2, *instance_7_3);
    MyClass_6_3* instance_6_3 = new MyClass_6_3(*instance_7_3, *instance_7_4);
    MyClass_6_4* instance_6_4 = new MyClass_6_4(*instance_7_4, *instance_7_5);
    MyClass_6_5* instance_6_5 = new MyClass_6_5(*instance_7_5, *instance_7_6);
    MyClass_6_6* instance_6_6 = new MyClass_6_6(*instance_7_6, *instance_7_7);
    MyClass_5_0* instance_5_0 = new MyClass_5_0(*instance_6_0, *instance_6_1);
    MyClass_5_1* instance_5_1 = new MyClass_5_1(*instance_6_1, *instance_6_2);
    MyClass_5_2* instance_5_2 = new MyClass_5_2(*instance_6_2, *instance_6_3);
    MyClass_5_3* instance_5_3 = new MyClass_5_3(*instance_6_3, *instance_6_4);
    MyClass_5_4* instance_5_4 = new MyClass_5_4(*instance_6_4, *instance_6_5);
    MyClass_5_5* instance_5_5 = new MyClass_5_5(*instance_6_5, *instance_6_6);
    MyClass_4_0* instance_4_0 = new MyClass_4_0(*instance_5_0, *instance_5_1);
    MyClass_4_1* instance_4_1 = new MyClass_4_1(*instance_5_1, *instance_5_2);
    MyClass_4_2* instance_4_2 = new MyClass_4_2(*instance_5_2, *instance_5_3);
    MyClass_4_3* instance_4_3 = new MyClass_4_3(*instance_5_3, *instance_5_4);
    MyClass_4_4* instance_4_4 = new MyClass_4_4(*instance_5_4, *instance_5_5);
    MyClass_3_0* instance_3_0 = new MyClass_3_0(*instance_4_0, *instance_4_1);
    MyClass_3_1* instance_3_1 = new MyClass_3_1(*instance_4_1, *instance_4_2);
    MyClass_3_2* instance_3_2 = new MyClass_3_2(*instance_4_2, *instance_4_3);
    MyClass_3_3* instance_3_3 = new MyClass_3_3(*instance_4_3, *instance_4_4);
    MyClass_2_0* instance_2_0 = new MyClass_2_0(*instance_3_0, *instance_3_1);
    MyClass_2_1* instance_2_1 = new MyClass_2_1(*instance_3_1, *instance_3_2);
    MyClass_2_2* instance_2_2 = new MyClass_2_2(*instance_3_2, *instance_3_3);
    MyClass_1_0* instance_1_0 = new MyClass_1_0(*instance_2_0, *instance_2_1);
    MyClass_1_1* instance_1_1 = new MyClass_1_1(*instance_2_1, *instance_2_2);
    MyClass_0_0* instance_0_0 = new MyClass_0_0(*instance_1_0, *instance_1_1);
    return instance_0_0;
}
