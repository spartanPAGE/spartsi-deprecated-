#pragma once

#include "langspec/langspec.hpp"
#include "builder/tree-builder.hpp"

#include "parser/impl/util.hpp"

namespace spartsi {
    namespace parser {
        template<typename Str>
        bool node_decl_def(builder::tree_builder &bld, langspec<Str> spec, const Str &line) {
            using namespace util;
            std::smatch m;

            std::string pattern = spec.ref_node.begin + " " + capture;

            if(std::regex_match(line, m, weak_reg(pattern))) {
                auto name = extract_captured(m[1]);

                if(bld.nodes.empty()) {
                    bld.ref_node(name);
                } else {
                    bld.req_node(name);
                }

                return true;
            }

            return false;
        }
    }
}