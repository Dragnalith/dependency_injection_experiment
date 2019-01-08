#pragma once

class MyClass_4_0 {
public:
    MyClass_4_0 () {}

private:
    int foo = 0;
};

class MyClass_4_1 {
public:
    MyClass_4_1 () {}

private:
    int foo = 0;
};

class MyClass_4_2 {
public:
    MyClass_4_2 () {}

private:
    int foo = 0;
};

class MyClass_4_3 {
public:
    MyClass_4_3 () {}

private:
    int foo = 0;
};

class MyClass_4_4 {
public:
    MyClass_4_4 () {}

private:
    int foo = 0;
};

class MyClass_4_5 {
public:
    MyClass_4_5 () {}

private:
    int foo = 0;
};

class MyClass_4_6 {
public:
    MyClass_4_6 () {}

private:
    int foo = 0;
};

class MyClass_4_7 {
public:
    MyClass_4_7 () {}

private:
    int foo = 0;
};

class MyClass_4_8 {
public:
    MyClass_4_8 () {}

private:
    int foo = 0;
};

class MyClass_4_9 {
public:
    MyClass_4_9 () {}

private:
    int foo = 0;
};

class MyClass_4_10 {
public:
    MyClass_4_10 () {}

private:
    int foo = 0;
};

class MyClass_4_11 {
public:
    MyClass_4_11 () {}

private:
    int foo = 0;
};

class MyClass_4_12 {
public:
    MyClass_4_12 () {}

private:
    int foo = 0;
};

class MyClass_4_13 {
public:
    MyClass_4_13 () {}

private:
    int foo = 0;
};

class MyClass_4_14 {
public:
    MyClass_4_14 () {}

private:
    int foo = 0;
};

class MyClass_4_15 {
public:
    MyClass_4_15 () {}

private:
    int foo = 0;
};

class MyClass_3_0 {
public:
    MyClass_3_0(MyClass_4_0& depA, MyClass_4_1& depB)
        : m_depA(depA)
        , m_depB(depB)
    {}

private:
    MyClass_4_0& m_depA;
    MyClass_4_1& m_depB;
};

class MyClass_3_1 {
public:
    MyClass_3_1(MyClass_4_2& depA, MyClass_4_3& depB)
        : m_depA(depA)
        , m_depB(depB)
    {}

private:
    MyClass_4_2& m_depA;
    MyClass_4_3& m_depB;
};

class MyClass_3_2 {
public:
    MyClass_3_2(MyClass_4_4& depA, MyClass_4_5& depB)
        : m_depA(depA)
        , m_depB(depB)
    {}

private:
    MyClass_4_4& m_depA;
    MyClass_4_5& m_depB;
};

class MyClass_3_3 {
public:
    MyClass_3_3(MyClass_4_6& depA, MyClass_4_7& depB)
        : m_depA(depA)
        , m_depB(depB)
    {}

private:
    MyClass_4_6& m_depA;
    MyClass_4_7& m_depB;
};

class MyClass_3_4 {
public:
    MyClass_3_4(MyClass_4_8& depA, MyClass_4_9& depB)
        : m_depA(depA)
        , m_depB(depB)
    {}

private:
    MyClass_4_8& m_depA;
    MyClass_4_9& m_depB;
};

class MyClass_3_5 {
public:
    MyClass_3_5(MyClass_4_10& depA, MyClass_4_11& depB)
        : m_depA(depA)
        , m_depB(depB)
    {}

private:
    MyClass_4_10& m_depA;
    MyClass_4_11& m_depB;
};

class MyClass_3_6 {
public:
    MyClass_3_6(MyClass_4_12& depA, MyClass_4_13& depB)
        : m_depA(depA)
        , m_depB(depB)
    {}

private:
    MyClass_4_12& m_depA;
    MyClass_4_13& m_depB;
};

class MyClass_3_7 {
public:
    MyClass_3_7(MyClass_4_14& depA, MyClass_4_15& depB)
        : m_depA(depA)
        , m_depB(depB)
    {}

private:
    MyClass_4_14& m_depA;
    MyClass_4_15& m_depB;
};

class MyClass_2_0 {
public:
    MyClass_2_0(MyClass_3_0& depA, MyClass_3_1& depB)
        : m_depA(depA)
        , m_depB(depB)
    {}

private:
    MyClass_3_0& m_depA;
    MyClass_3_1& m_depB;
};

class MyClass_2_1 {
public:
    MyClass_2_1(MyClass_3_2& depA, MyClass_3_3& depB)
        : m_depA(depA)
        , m_depB(depB)
    {}

private:
    MyClass_3_2& m_depA;
    MyClass_3_3& m_depB;
};

class MyClass_2_2 {
public:
    MyClass_2_2(MyClass_3_4& depA, MyClass_3_5& depB)
        : m_depA(depA)
        , m_depB(depB)
    {}

private:
    MyClass_3_4& m_depA;
    MyClass_3_5& m_depB;
};

class MyClass_2_3 {
public:
    MyClass_2_3(MyClass_3_6& depA, MyClass_3_7& depB)
        : m_depA(depA)
        , m_depB(depB)
    {}

private:
    MyClass_3_6& m_depA;
    MyClass_3_7& m_depB;
};

class MyClass_1_0 {
public:
    MyClass_1_0(MyClass_2_0& depA, MyClass_2_1& depB)
        : m_depA(depA)
        , m_depB(depB)
    {}

private:
    MyClass_2_0& m_depA;
    MyClass_2_1& m_depB;
};

class MyClass_1_1 {
public:
    MyClass_1_1(MyClass_2_2& depA, MyClass_2_3& depB)
        : m_depA(depA)
        , m_depB(depB)
    {}

private:
    MyClass_2_2& m_depA;
    MyClass_2_3& m_depB;
};

class MyClass_0_0 {
public:
    MyClass_0_0(MyClass_1_0& depA, MyClass_1_1& depB)
        : m_depA(depA)
        , m_depB(depB)
    {}

private:
    MyClass_1_0& m_depA;
    MyClass_1_1& m_depB;
};
