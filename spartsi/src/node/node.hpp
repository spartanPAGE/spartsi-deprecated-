#pragma once

#include <unordered_map>
#include <memory>

namespace spartsi {

    template <typename Str>
    struct node {
        using str_t = Str;

        str_t name, version, comment;

        std::unordered_map<str_t, str_t> attributes;
        std::unordered_map<str_t, std::unique_ptr<node<Str>>> nodes;
    };

}