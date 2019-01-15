#include <boost/di.hpp>
#include <boost/di/extension/scopes/shared.hpp>

#include <test/gen_test.h>

#include <assert.h>

int main()
{
    auto injector = boost::di::make_injector(boost::di::bind<MyClass_0_0>().in(boost::di::extension::shared));
    //auto injector = boost::di::make_injector<boost::di::extension::shared_config>();

    MyClass_0_0* instance1 = &injector.create<MyClass_0_0&>();
    MyClass_0_0* instance2 = &injector.create<MyClass_0_0&>();

    assert(instance1 == instance2);

    auto injector2 = boost::di::make_injector(boost::di::bind<MyClass_0_0>().in(boost::di::extension::shared));
    //auto injector2 = boost::di::make_injector<boost::di::extension::shared_config>();

    MyClass_0_0* instance3 = &injector2.create<MyClass_0_0&>();
    MyClass_0_0* instance4 = &injector2.create<MyClass_0_0&>();

    assert(instance3 == instance4);

    assert(instance1 != instance4);

    return 0;
}
