module;
// ALL includes must be at the top in between a 'module; and 'export module X;' statement, this is called the "Global Module Fragment"

#include <EASTL/span.h> // for eastl::dynamic_extent internal symbol

export module Common.Demo;

import Common.eastl;

// export everything inside namespace
export namespace demo
{
    template<typename T> using vector = eastl::vector<T>;
    template<typename T, size_t N> using array = eastl::array<T, N>;
    template<typename T> using list = eastl::list<T>;
    template <size_t NumWords, typename WordType> using bitset = eastl::bitset<NumWords, WordType>;

    using string = eastl::string;
    using string_view = eastl::string_view;

    constexpr size_t dynamic_extent = eastl::dynamic_extent; // from #include
    template <typename T, size_t Extent = dynamic_extent> using span = eastl::span<T, Extent>;

    template <typename... Variants> using variant = eastl::variant<Variants...>;
    using eastl::get; // re-export specific functions
    using eastl::holds_alternative;
}

// export individual things
namespace demo
{
    export template<typename T> using set = eastl::set<T>;
    export template<typename T> using unordered_set = eastl::unordered_set<T>;
    export template<typename K, typename V> using map = eastl::map<K, V>;
    export template<typename K, typename V> using unordered_map = eastl::unordered_map<K, V>;

     // re-export specific functions
    export using eastl::find;
    export using eastl::find_if;
}