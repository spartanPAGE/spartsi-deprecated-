#pragma once

#include <string>

#include "core/view_of.hpp"
#include <string>

#include <node/node.hpp>
#include <stack>

namespace spartsi {

    namespace builder {

        using str_t = std::string;

        struct comment_buffer{
            str_t data;
            void operator+=(view_of<str_t> str);
            str_t pull();
        };

        struct tree_builder {
            using node_t = spartsi::node<str_t>;

            comment_buffer comment;
            node_t::shared root = node_t::spawn_root("", "", "");
            std::stack<node_t::shared> nodes;

            tree_builder &operator()(view_of<str_t> str);

            tree_builder &treestructinfo(view_of<str_t> version);

            tree_builder &name(view_of<str_t> name);

            node_t::shared end_tree();

            tree_builder &node(view_of<str_t> name);

            tree_builder &end_node();

            tree_builder &attr(view_of<str_t> name, view_of<str_t> value);


        };

        tree_builder build();
    }

}