#pragma once

#include <unordered_map>
#include <string>
#include <functional>

#include "core/view_of.hpp"

namespace spartsi{

    using regular_expression_t = std::string;
    using parsing_func_t = std::function<void(view_of<std::string>)>;

    using parsers_t = std::unordered_map<
        regular_expression_t,
        parsing_func_t
    >;
}