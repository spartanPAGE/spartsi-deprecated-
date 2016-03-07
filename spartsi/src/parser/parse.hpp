#pragma once

#include "langspec/default.hpp"
#include "builder/tree-builder.hpp"

#include "parser.hpp"
#include "impl/parsers.hpp"

#include <vector>
#include <iterator>
#include <algorithm>
#include <string>
#include <sstream>

namespace spartsi{

    template<typename Str>
    auto get_parsers(spartsi::builder::tree_builder &builder, view_of<langspec<Str>> lang) {
        auto raw_parsers = parser::get_parsers<Str>();
        std::vector<parser_t<Str>> result;

        for(auto rp: raw_parsers) {
            result.push_back([&builder, &lang, rp](const Str &line){ return rp(builder, lang, line); });
        }

        return result;
    }

    template<typename Str>
    typename node<Str>::shared parse(Str lines_raw, langspec<Str> lang = default_::langspec) {
        std::vector<Str> lines = {""};
        for(char c: lines_raw) {
            if(c == '\n') lines.emplace_back();
            else lines.back() += c;
        }

        auto builder = spartsi::builder::build();

        auto parsers = get_parsers(builder, lang);

        for(auto line: lines) {
            if(line.find_first_not_of(spartsi::parser::util::whitespaces) == std::string::npos) continue;

            bool result = false;

            for(auto &parser: parsers){
                result = parser(line);
                if(result) break;
            }

            if(!result) {
                throw std::runtime_error("Weird line: " + line);
            }
        }
        return builder.get();
    }
}