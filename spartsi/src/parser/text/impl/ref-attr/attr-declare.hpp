#pragma once

#include "langspec/langspec.hpp"
#include "builder/tree-builder.hpp"

#include "parser/text/impl/util.hpp"

namespace spartsi {
    namespace parser {
        template<typename Str>
        bool attr_declare(builder::tree_builder &bld, langspec<Str> spec, const Str &line) {
            using namespace util;
            std::smatch m;

            std::string pattern = spec.ref_attr.name + " " + capture;

            if(std::regex_match(line, m, weak_reg(pattern))) {
                bld.req_attr(extract_captured(m[1]));
                return true;
            }

            return false;
        }
    }
}