#pragma once

class MyClass_8_0 {
public:
    MyClass_8_0 () {}

private:
    int foo = 0;
};

class MyClass_8_1 {
public:
    MyClass_8_1 () {}

private:
    int foo = 0;
};

class MyClass_8_2 {
public:
    MyClass_8_2 () {}

private:
    int foo = 0;
};

class MyClass_8_3 {
public:
    MyClass_8_3 () {}

private:
    int foo = 0;
};

class MyClass_8_4 {
public:
    MyClass_8_4 () {}

private:
    int foo = 0;
};

class MyClass_8_5 {
public:
    MyClass_8_5 () {}

private:
    int foo = 0;
};

class MyClass_8_6 {
public:
    MyClass_8_6 () {}

private:
    int foo = 0;
};

class MyClass_8_7 {
public:
    MyClass_8_7 () {}

private:
    int foo = 0;
};

class MyClass_8_8 {
public:
    MyClass_8_8 () {}

private:
    int foo = 0;
};

class MyClass_7_0 {
public:
    MyClass_7_0(MyClass_8_0& depA, MyClass_8_1& depB)
        : m_depA(depA)
        , m_depB(depB)
    {}

private:
    MyClass_8_0& m_depA;
    MyClass_8_1& m_depB;
};

class MyClass_7_1 {
public:
    MyClass_7_1(MyClass_8_1& depA, MyClass_8_2& depB)
        : m_depA(depA)
        , m_depB(depB)
    {}

private:
    MyClass_8_1& m_depA;
    MyClass_8_2& m_depB;
};

class MyClass_7_2 {
public:
    MyClass_7_2(MyClass_8_2& depA, MyClass_8_3& depB)
        : m_depA(depA)
        , m_depB(depB)
    {}

private:
    MyClass_8_2& m_depA;
    MyClass_8_3& m_depB;
};

class MyClass_7_3 {
public:
    MyClass_7_3(MyClass_8_3& depA, MyClass_8_4& depB)
        : m_depA(depA)
        , m_depB(depB)
    {}

private:
    MyClass_8_3& m_depA;
    MyClass_8_4& m_depB;
};

class MyClass_7_4 {
public:
    MyClass_7_4(MyClass_8_4& depA, MyClass_8_5& depB)
        : m_depA(depA)
        , m_depB(depB)
    {}

private:
    MyClass_8_4& m_depA;
    MyClass_8_5& m_depB;
};

class MyClass_7_5 {
public:
    MyClass_7_5(MyClass_8_5& depA, MyClass_8_6& depB)
        : m_depA(depA)
        , m_depB(depB)
    {}

private:
    MyClass_8_5& m_depA;
    MyClass_8_6& m_depB;
};

class MyClass_7_6 {
public:
    MyClass_7_6(MyClass_8_6& depA, MyClass_8_7& depB)
        : m_depA(depA)
        , m_depB(depB)
    {}

private:
    MyClass_8_6& m_depA;
    MyClass_8_7& m_depB;
};

class MyClass_7_7 {
public:
    MyClass_7_7(MyClass_8_7& depA, MyClass_8_8& depB)
        : m_depA(depA)
        , m_depB(depB)
    {}

private:
    MyClass_8_7& m_depA;
    MyClass_8_8& m_depB;
};

class MyClass_6_0 {
public:
    MyClass_6_0(MyClass_7_0& depA, MyClass_7_1& depB)
        : m_depA(depA)
        , m_depB(depB)
    {}

private:
    MyClass_7_0& m_depA;
    MyClass_7_1& m_depB;
};

class MyClass_6_1 {
public:
    MyClass_6_1(MyClass_7_1& depA, MyClass_7_2& depB)
        : m_depA(depA)
        , m_depB(depB)
    {}

private:
    MyClass_7_1& m_depA;
    MyClass_7_2& m_depB;
};

class MyClass_6_2 {
public:
    MyClass_6_2(MyClass_7_2& depA, MyClass_7_3& depB)
        : m_depA(depA)
        , m_depB(depB)
    {}

private:
    MyClass_7_2& m_depA;
    MyClass_7_3& m_depB;
};

class MyClass_6_3 {
public:
    MyClass_6_3(MyClass_7_3& depA, MyClass_7_4& depB)
        : m_depA(depA)
        , m_depB(depB)
    {}

private:
    MyClass_7_3& m_depA;
    MyClass_7_4& m_depB;
};

class MyClass_6_4 {
public:
    MyClass_6_4(MyClass_7_4& depA, MyClass_7_5& depB)
        : m_depA(depA)
        , m_depB(depB)
    {}

private:
    MyClass_7_4& m_depA;
    MyClass_7_5& m_depB;
};

class MyClass_6_5 {
public:
    MyClass_6_5(MyClass_7_5& depA, MyClass_7_6& depB)
        : m_depA(depA)
        , m_depB(depB)
    {}

private:
    MyClass_7_5& m_depA;
    MyClass_7_6& m_depB;
};

class MyClass_6_6 {
public:
    MyClass_6_6(MyClass_7_6& depA, MyClass_7_7& depB)
        : m_depA(depA)
        , m_depB(depB)
    {}

private:
    MyClass_7_6& m_depA;
    MyClass_7_7& m_depB;
};

class MyClass_5_0 {
public:
    MyClass_5_0(MyClass_6_0& depA, MyClass_6_1& depB)
        : m_depA(depA)
        , m_depB(depB)
    {}

private:
    MyClass_6_0& m_depA;
    MyClass_6_1& m_depB;
};

class MyClass_5_1 {
public:
    MyClass_5_1(MyClass_6_1& depA, MyClass_6_2& depB)
        : m_depA(depA)
        , m_depB(depB)
    {}

private:
    MyClass_6_1& m_depA;
    MyClass_6_2& m_depB;
};

class MyClass_5_2 {
public:
    MyClass_5_2(MyClass_6_2& depA, MyClass_6_3& depB)
        : m_depA(depA)
        , m_depB(depB)
    {}

private:
    MyClass_6_2& m_depA;
    MyClass_6_3& m_depB;
};

class MyClass_5_3 {
public:
    MyClass_5_3(MyClass_6_3& depA, MyClass_6_4& depB)
        : m_depA(depA)
        , m_depB(depB)
    {}

private:
    MyClass_6_3& m_depA;
    MyClass_6_4& m_depB;
};

class MyClass_5_4 {
public:
    MyClass_5_4(MyClass_6_4& depA, MyClass_6_5& depB)
        : m_depA(depA)
        , m_depB(depB)
    {}

private:
    MyClass_6_4& m_depA;
    MyClass_6_5& m_depB;
};

class MyClass_5_5 {
public:
    MyClass_5_5(MyClass_6_5& depA, MyClass_6_6& depB)
        : m_depA(depA)
        , m_depB(depB)
    {}

private:
    MyClass_6_5& m_depA;
    MyClass_6_6& m_depB;
};

class MyClass_4_0 {
public:
    MyClass_4_0(MyClass_5_0& depA, MyClass_5_1& depB)
        : m_depA(depA)
        , m_depB(depB)
    {}

private:
    MyClass_5_0& m_depA;
    MyClass_5_1& m_depB;
};

class MyClass_4_1 {
public:
    MyClass_4_1(MyClass_5_1& depA, MyClass_5_2& depB)
        : m_depA(depA)
        , m_depB(depB)
    {}

private:
    MyClass_5_1& m_depA;
    MyClass_5_2& m_depB;
};

class MyClass_4_2 {
public:
    MyClass_4_2(MyClass_5_2& depA, MyClass_5_3& depB)
        : m_depA(depA)
        , m_depB(depB)
    {}

private:
    MyClass_5_2& m_depA;
    MyClass_5_3& m_depB;
};

class MyClass_4_3 {
public:
    MyClass_4_3(MyClass_5_3& depA, MyClass_5_4& depB)
        : m_depA(depA)
        , m_depB(depB)
    {}

private:
    MyClass_5_3& m_depA;
    MyClass_5_4& m_depB;
};

class MyClass_4_4 {
public:
    MyClass_4_4(MyClass_5_4& depA, MyClass_5_5& depB)
        : m_depA(depA)
        , m_depB(depB)
    {}

private:
    MyClass_5_4& m_depA;
    MyClass_5_5& m_depB;
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
    MyClass_3_1(MyClass_4_1& depA, MyClass_4_2& depB)
        : m_depA(depA)
        , m_depB(depB)
    {}

private:
    MyClass_4_1& m_depA;
    MyClass_4_2& m_depB;
};

class MyClass_3_2 {
public:
    MyClass_3_2(MyClass_4_2& depA, MyClass_4_3& depB)
        : m_depA(depA)
        , m_depB(depB)
    {}

private:
    MyClass_4_2& m_depA;
    MyClass_4_3& m_depB;
};

class MyClass_3_3 {
public:
    MyClass_3_3(MyClass_4_3& depA, MyClass_4_4& depB)
        : m_depA(depA)
        , m_depB(depB)
    {}

private:
    MyClass_4_3& m_depA;
    MyClass_4_4& m_depB;
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
    MyClass_2_1(MyClass_3_1& depA, MyClass_3_2& depB)
        : m_depA(depA)
        , m_depB(depB)
    {}

private:
    MyClass_3_1& m_depA;
    MyClass_3_2& m_depB;
};

class MyClass_2_2 {
public:
    MyClass_2_2(MyClass_3_2& depA, MyClass_3_3& depB)
        : m_depA(depA)
        , m_depB(depB)
    {}

private:
    MyClass_3_2& m_depA;
    MyClass_3_3& m_depB;
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
    MyClass_1_1(MyClass_2_1& depA, MyClass_2_2& depB)
        : m_depA(depA)
        , m_depB(depB)
    {}

private:
    MyClass_2_1& m_depA;
    MyClass_2_2& m_depB;
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
