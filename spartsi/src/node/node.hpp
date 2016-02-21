#pragma once

#include <unordered_map>
#include <memory>

#include "core/view_of.hpp"

namespace spartsi {

    template<typename Str>
    struct node {
        using shared = std::shared_ptr<node<Str>>;
        using str_t = Str;

        const node *parent;

        str_t name, version, comment;
        std::unordered_map<str_t, str_t> attributes;
        std::unordered_map<str_t, node::shared> children;
    };

    template<typename Str, typename StrView = view_of<Str>>
    typename node<Str>::shared create_node(StrView name, StrView version, StrView comment = ""){
        using node_t = node<Str>:
        auto result = std::shared_ptr<node_t>(new node_t{ nullptr, name, version, comment });
        return std::make_shared<node<Str>>(nullptr, name, version, comment);
    }

    template<typename Node, typename StrView = view_of<typename Node::str_t>>
    Node create_node(view_of<Node> parent, StrView name, StrView comment){
        using node_t = Node;
        return std::make_shared<Node>(&parent, name, parent.version, comment);
    }


}