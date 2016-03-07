#pragma once

namespace spartsi {

    template <typename Str>
    struct langspec {
        using str_t = Str;

        struct tree_t {
            str_t begin, name, end;
        } tree;

        struct attr_t {
            str_t name;
        } attr;

        struct ref_attr_t {
            str_t name;
        } ref_attr;

        struct node_t {
            str_t begin, end;
        } node;

        struct ref_node_t {
            str_t begin, end;
        } ref_node;

        struct comment_t {
            str_t begin;
        } comment;

        //todo: handle linked-trees-related thing like {tree, as node, in mode}
    };

}