#include <test/gen_test.manual.h>
#include <type_traits>
#include <utility>
#include <vector>
//template<class TParent>
//struct AnyType {
//    template<class T, class = std::enable_if_t<!std::is_same<TParent, T>{}> >
//    constexpr operator T();
//};

template<size_t>
using any_type_t = int;

template<size_t ...Ns>
std::vector<int> foo(std::index_sequence<Ns...>)
{
    return { any_type_t<Ns>(3)... };
}

int main()
{
    auto a = foo(std::make_index_sequence<4>{});
    auto b = foo(std::make_index_sequence<10>{});
    MyClass_0_0* instance = create_manually();

    return 0;
}