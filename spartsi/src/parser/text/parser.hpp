#pragma once

#include <string>
#include <functional>

namespace spartsi{
    template<typename Str>
    using parser_t = std::function<bool(const Str &)>;
}