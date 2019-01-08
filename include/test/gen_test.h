#pragma once

class MyClass_10_0 {
public:
    MyClass_10_0 () {}

private:
    int foo = 0;
};

class MyClass_10_1 {
public:
    MyClass_10_1 () {}

private:
    int foo = 0;
};

class MyClass_10_2 {
public:
    MyClass_10_2 () {}

private:
    int foo = 0;
};

class MyClass_10_3 {
public:
    MyClass_10_3 () {}

private:
    int foo = 0;
};

class MyClass_10_4 {
public:
    MyClass_10_4 () {}

private:
    int foo = 0;
};

class MyClass_10_5 {
public:
    MyClass_10_5 () {}

private:
    int foo = 0;
};

class MyClass_10_6 {
public:
    MyClass_10_6 () {}

private:
    int foo = 0;
};

class MyClass_10_7 {
public:
    MyClass_10_7 () {}

private:
    int foo = 0;
};

class MyClass_10_8 {
public:
    MyClass_10_8 () {}

private:
    int foo = 0;
};

class MyClass_10_9 {
public:
    MyClass_10_9 () {}

private:
    int foo = 0;
};

class MyClass_10_10 {
public:
    MyClass_10_10 () {}

private:
    int foo = 0;
};

class MyClass_9_0 {
public:
    MyClass_9_0(MyClass_10_0& depA, MyClass_10_1& depB)
        : m_depA(depA)
        , m_depB(depB)
    {}

private:
    MyClass_10_0& m_depA;
    MyClass_10_1& m_depB;
};

class MyClass_9_1 {
public:
    MyClass_9_1(MyClass_10_1& depA, MyClass_10_2& depB)
        : m_depA(depA)
        , m_depB(depB)
    {}

private:
    MyClass_10_1& m_depA;
    MyClass_10_2& m_depB;
};

class MyClass_9_2 {
public:
    MyClass_9_2(MyClass_10_2& depA, MyClass_10_3& depB)
        : m_depA(depA)
        , m_depB(depB)
    {}

private:
    MyClass_10_2& m_depA;
    MyClass_10_3& m_depB;
};

class MyClass_9_3 {
public:
    MyClass_9_3(MyClass_10_3& depA, MyClass_10_4& depB)
        : m_depA(depA)
        , m_depB(depB)
    {}

private:
    MyClass_10_3& m_depA;
    MyClass_10_4& m_depB;
};

class MyClass_9_4 {
public:
    MyClass_9_4(MyClass_10_4& depA, MyClass_10_5& depB)
        : m_depA(depA)
        , m_depB(depB)
    {}

private:
    MyClass_10_4& m_depA;
    MyClass_10_5& m_depB;
};

class MyClass_9_5 {
public:
    MyClass_9_5(MyClass_10_5& depA, MyClass_10_6& depB)
        : m_depA(depA)
        , m_depB(depB)
    {}

private:
    MyClass_10_5& m_depA;
    MyClass_10_6& m_depB;
};

class MyClass_9_6 {
public:
    MyClass_9_6(MyClass_10_6& depA, MyClass_10_7& depB)
        : m_depA(depA)
        , m_depB(depB)
    {}

private:
    MyClass_10_6& m_depA;
    MyClass_10_7& m_depB;
};

class MyClass_9_7 {
public:
    MyClass_9_7(MyClass_10_7& depA, MyClass_10_8& depB)
        : m_depA(depA)
        , m_depB(depB)
    {}

private:
    MyClass_10_7& m_depA;
    MyClass_10_8& m_depB;
};

class MyClass_9_8 {
public:
    MyClass_9_8(MyClass_10_8& depA, MyClass_10_9& depB)
        : m_depA(depA)
        , m_depB(depB)
    {}

private:
    MyClass_10_8& m_depA;
    MyClass_10_9& m_depB;
};

class MyClass_9_9 {
public:
    MyClass_9_9(MyClass_10_9& depA, MyClass_10_10& depB)
        : m_depA(depA)
        , m_depB(depB)
    {}

private:
    MyClass_10_9& m_depA;
    MyClass_10_10& m_depB;
};

class MyClass_8_0 {
public:
    MyClass_8_0(MyClass_9_0& depA, MyClass_9_1& depB)
        : m_depA(depA)
        , m_depB(depB)
    {}

private:
    MyClass_9_0& m_depA;
    MyClass_9_1& m_depB;
};

class MyClass_8_1 {
public:
    MyClass_8_1(MyClass_9_1& depA, MyClass_9_2& depB)
        : m_depA(depA)
        , m_depB(depB)
    {}

private:
    MyClass_9_1& m_depA;
    MyClass_9_2& m_depB;
};

class MyClass_8_2 {
public:
    MyClass_8_2(MyClass_9_2& depA, MyClass_9_3& depB)
        : m_depA(depA)
        , m_depB(depB)
    {}

private:
    MyClass_9_2& m_depA;
    MyClass_9_3& m_depB;
};

class MyClass_8_3 {
public:
    MyClass_8_3(MyClass_9_3& depA, MyClass_9_4& depB)
        : m_depA(depA)
        , m_depB(depB)
    {}

private:
    MyClass_9_3& m_depA;
    MyClass_9_4& m_depB;
};

class MyClass_8_4 {
public:
    MyClass_8_4(MyClass_9_4& depA, MyClass_9_5& depB)
        : m_depA(depA)
        , m_depB(depB)
    {}

private:
    MyClass_9_4& m_depA;
    MyClass_9_5& m_depB;
};

class MyClass_8_5 {
public:
    MyClass_8_5(MyClass_9_5& depA, MyClass_9_6& depB)
        : m_depA(depA)
        , m_depB(depB)
    {}

private:
    MyClass_9_5& m_depA;
    MyClass_9_6& m_depB;
};

class MyClass_8_6 {
public:
    MyClass_8_6(MyClass_9_6& depA, MyClass_9_7& depB)
        : m_depA(depA)
        , m_depB(depB)
    {}

private:
    MyClass_9_6& m_depA;
    MyClass_9_7& m_depB;
};

class MyClass_8_7 {
public:
    MyClass_8_7(MyClass_9_7& depA, MyClass_9_8& depB)
        : m_depA(depA)
        , m_depB(depB)
    {}

private:
    MyClass_9_7& m_depA;
    MyClass_9_8& m_depB;
};

class MyClass_8_8 {
public:
    MyClass_8_8(MyClass_9_8& depA, MyClass_9_9& depB)
        : m_depA(depA)
        , m_depB(depB)
    {}

private:
    MyClass_9_8& m_depA;
    MyClass_9_9& m_depB;
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
