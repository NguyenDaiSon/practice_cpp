#include <cassert>
#include <iostream>
#include <memory>
#include <tuple>
#include <utility> // std::index_sequence<I...>

/// reset -> replaces the managed object

using point3d = std::tuple<double, double, double>;

/// https://stackoverflow.com/questions/6245735/pretty-print-stdtuple
template <typename AnyTuple, size_t... Index>
void print(AnyTuple const& aTuple, std::index_sequence<Index...>)
{
    std::cout << "(";
    (..., (std::cout << (Index == 0 ? "" : ",") << std::get<Index>(aTuple)));
    std::cout << ")\n";
}

template <typename... T>
void print(std::tuple<T...> const& aTuple)
{
    print(aTuple, std::make_index_sequence<sizeof...(T)>());
}

int main()
{
    auto uptrPoint3d = std::make_unique<point3d>(10.0, 20.0, 30.0);
    assert(uptrPoint3d != nullptr);
    print(*uptrPoint3d);

    auto* pPoint3d = uptrPoint3d.get();
    print(*pPoint3d);

    uptrPoint3d.reset(new point3d { -10.0, -20.0, -30.0 });
    print(*uptrPoint3d);

    /// DANGEROUS
    {
        // !!!
        // print(*pPoint3d);
        // ///
    }

    uptrPoint3d.reset(nullptr);
}
