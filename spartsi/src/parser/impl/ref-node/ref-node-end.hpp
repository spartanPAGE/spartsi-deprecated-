#pragma once

#include "langspec/langspec.hpp"
#include "builder/tree-builder.hpp"

#include "parser/impl/util.hpp"

namespace spartsi {
    namespace parser {
        template<typename Str>
        bool ref_node_end(builder::tree_builder &bld, langspec<Str> spec, const Str &line) {
            using namespace util;
            std::smatch m;

            std::string pattern = spec.ref_node.end;

            if(std::regex_match(line, m, weak_reg(pattern))) {
                bld.end_ref_node();
                return true;
            }

            return false;
        }
    }
}