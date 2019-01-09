#pragma once

class MyClass_2_0 {
public:
    MyClass_2_0 () {}

private:
    int foo = 0;
};

class MyClass_2_1 {
public:
    MyClass_2_1 () {}

private:
    int foo = 0;
};

class MyClass_2_2 {
public:
    MyClass_2_2 () {}

private:
    int foo = 0;
};

class MyClass_1_0 {
public:
    MyClass_1_0(MyClass_2_0& dep2_0,MyClass_2_1& dep2_1)
        : foo(0)
        , m_dep2_0(dep2_0)
        , m_dep2_1(dep2_1)
    {}

private:
    int foo;
    MyClass_2_0& m_dep2_0;
    MyClass_2_1& m_dep2_1;
};

class MyClass_1_1 {
public:
    MyClass_1_1(MyClass_2_1& dep2_1,MyClass_2_2& dep2_2)
        : foo(0)
        , m_dep2_1(dep2_1)
        , m_dep2_2(dep2_2)
    {}

private:
    int foo;
    MyClass_2_1& m_dep2_1;
    MyClass_2_2& m_dep2_2;
};

class MyClass_0_0 {
public:
    MyClass_0_0(MyClass_1_0& dep1_0,MyClass_1_1& dep1_1)
        : foo(0)
        , m_dep1_0(dep1_0)
        , m_dep1_1(dep1_1)
    {}

private:
    int foo;
    MyClass_1_0& m_dep1_0;
    MyClass_1_1& m_dep1_1;
};
