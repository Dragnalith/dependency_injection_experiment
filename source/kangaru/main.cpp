#include <test/gen_test.kangaru.h>

#include <assert.h>

int main()
{
    kgr::container container;

    MyClass_0_0* instance1 = &container.service<MyClass_0_0Service>();
    MyClass_0_0* instance2 = &container.service<MyClass_0_0Service>();

    assert(instance1 == instance2);

    kgr::container container2;
    MyClass_0_0* instance3 = &container2.service<MyClass_0_0Service>();
    MyClass_0_0* instance4 = &container2.service<MyClass_0_0Service>();

    assert(instance3 == instance4);

    assert(instance1 != instance4);

    return 0;
}
