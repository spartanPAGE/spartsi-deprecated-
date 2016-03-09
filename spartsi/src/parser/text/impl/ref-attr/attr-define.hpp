#pragma once

#include "langspec/langspec.hpp"
#include "builder/tree-builder.hpp"

#include "parser/text/impl/util.hpp"

namespace spartsi {
    namespace parser {
        template<typename Str>
        bool attr_define(builder::tree_builder &bld, langspec<Str> spec, const Str &line) {
            using namespace util;
            std::smatch m;

            std::string pattern = spec.ref_attr.name + " " + capture + " " + capture_quoted + "";

            if(std::regex_match(line, m, weak_reg(pattern))) {
                bld.ref_attr(extract_captured(m[1]), extract_captured(m[2]));
                return true;
            }

            return false;
        }
    }
}