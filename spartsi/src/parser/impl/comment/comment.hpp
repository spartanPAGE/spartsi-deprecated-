#pragma once

#include "langspec/langspec.hpp"
#include "builder/tree-builder.hpp"

#include "parser/impl/util.hpp"

namespace spartsi {
    namespace parser {
        template<typename Str>
        bool comment(builder::tree_builder &bld, langspec<Str> spec, const Str &line) {
            using namespace util;
            std::smatch m;

            std::string pattern = spec.comment.begin + ws+"*"+ "(.*)" +ws+"*";

            if(std::regex_match(line, m, weak_reg(pattern))) {
                std::string beg = whitespaces+spec.comment.begin;

                auto beg_pos = line.find_first_not_of(beg);
                auto end_pos = line.find_last_not_of(whitespaces);

                if(beg_pos == Str::npos || end_pos == Str::npos) {
                    bld.operator()("");
                    return true;
                }

                Str result = Str(line.begin()+beg_pos, line.begin()+end_pos+1);
                bld.operator()(result);
                return true;
            }

            return false;
        }
    }
}