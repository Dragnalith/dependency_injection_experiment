#include <boost/di.hpp>

#include <test/gen_test.h>

int main() {
    auto injector = boost::di::make_injector(boost::di::bind<MyClass_0_0>().in(boost::di::singleton));

    MyClass_0_0& instanceA = injector.create<MyClass_0_0&>();
    MyClass_0_0& instanceB = injector.create<MyClass_0_0&>();
    
    auto injector2 = boost::di::make_injector(boost::di::bind<MyClass_0_0>().in(boost::di::singleton));

    MyClass_0_0& instanceA2 = injector2.create<MyClass_0_0&>();
    MyClass_0_0& instanceB2 = injector2.create<MyClass_0_0&>();
    
    return 0;
}
