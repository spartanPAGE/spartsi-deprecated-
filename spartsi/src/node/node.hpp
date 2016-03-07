#pragma once

#include <unordered_map>
#include <memory>

#include "core/view-of.hpp"

namespace spartsi {

    template<typename Str>
    class node {
    public:
        using shared = std::shared_ptr<node<Str>>;
        using str_t = Str;
        using attribute_t = std::pair<str_t, str_t>;
        using attributes_t = std::unordered_map<str_t, attribute_t>;
        using children_t = std::unordered_map<str_t, node::shared>;
        using children_alternative_comment_t = std::unordered_map<str_t, str_t>;
    private:
        node(
            view_of<str_t> name,
            view_of<str_t> version,
            view_of<str_t> comment
        ): name(name), version(version), comment(comment)
        {}

        node(
            view_of<str_t> name,
            view_of<str_t> version,
            view_of<str_t> comment,
            view_of<attributes_t> attrs
        ): name(name), version(version), comment(comment), attributes(attrs)
        {}

        node(
            const node *parent,
            view_of<str_t> name,
            view_of<str_t> comment
        ):
            parent(parent),
            name(name),
            version(parent->version),
            comment(comment)
        {}

        node(
            const node *parent,
            view_of<str_t> name,
            view_of<str_t> comment,
            view_of<attributes_t> attrs
        ):
            parent(parent),
            name(name),
            version(parent->version),
            comment(comment),
            attributes(attrs)
        {}

    public:
        const node *parent;

        str_t name, version, comment;
        attributes_t attributes;
        children_t children;
        children_alternative_comment_t alternative_comments;

        node::shared spawn_child(
            view_of<str_t> name,
            view_of<str_t> comment
        ){
            auto result = shared(new node<Str>(this, name, comment));
            this->children[name] = result;
            return result;
        }

        node::shared spawn_child(
            view_of<str_t> name,
            view_of<str_t> comment,
            view_of<attributes_t> attrs
        ){
            auto result = shared(new node<Str>(this, name, comment, attrs));
            this->children[name] = result;
            return result;
        }



        static node::shared spawn_root(
            view_of<str_t> name,
            view_of<str_t> version,
            view_of<str_t> comment
        ){
            return shared(new node<Str>(name, version, comment));
        }

        static node::shared spawn_root(
            view_of<str_t> name,
            view_of<str_t> version,
            view_of<str_t> comment,
            view_of<attributes_t> attrs
        ){
            return shared(new node<Str>(name, version, comment, attrs));
        }
    };
}