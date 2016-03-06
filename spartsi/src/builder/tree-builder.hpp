#pragma once

#include <string>

#include "core/view_of.hpp"
#include <string>

#include <node/node.hpp>
#include <stack>
#include <deque>
#include <functional>

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

            std::deque<std::reference_wrapper<node_t::attribute_t>> ref_attrs;
            std::deque<node_t::shared> ref_nodes;

            tree_builder &operator()(view_of<str_t> str);

            tree_builder &treestructinfo(view_of<str_t> version);

            tree_builder &name(view_of<str_t> name);

            tree_builder &end_tree();

            node_t::shared get();

            tree_builder &node(view_of<str_t> name);

            tree_builder &end_node();

            tree_builder &attr(view_of<str_t> name, view_of<str_t> value);

            tree_builder &req_attr(view_of<str_t> name);

            tree_builder &ref_attr(view_of<str_t> name, view_of<str_t> value);

            tree_builder &req_node(view_of<str_t> name);

            tree_builder &ref_node(view_of<str_t> name);

            tree_builder &end_ref_node();
        };

        tree_builder build();
    }

}