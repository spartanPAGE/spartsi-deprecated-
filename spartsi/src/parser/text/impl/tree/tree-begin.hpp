#pragma once


#include "langspec/langspec.hpp"
#include "builder/tree-builder.hpp"

#include "parser/text/impl/util.hpp"

namespace spartsi {
    namespace parser {
        template<typename Str>
        bool tree_begin(builder::tree_builder &bld, langspec<Str> spec, const Str &line) {
            using namespace util;
            std::smatch m;

            std::string nameless = spec.tree.begin + " " + capture_quoted;
            std::string nameful  = nameless + " " + spec.tree.name + " " + capture_quoted;

            if(std::regex_match(line, m, weak_reg(nameful))) {
                bld.treestructinfo(m[1]);
                bld.name(m[2]);
                return true;
            }

            if(std::regex_match(line, m, weak_reg(nameless))) {
                bld.treestructinfo(m[1]);
                return true;
            }

            return false;
        }
    }
}