#pragma once

#include "node.hpp"

namespace spartsi {

    template <typename Node, class... Args>
    Node create_node(const Node &parent, Args &&... args) {
        auto result = Node{std::forward<Args>(args)...};
        result.version = parent.version;
        return result;
    };

}