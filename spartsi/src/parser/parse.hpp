#pragma once

#include "langspec/default.hpp"
#include "builder/tree-builder.hpp"

#include "parser.hpp"

#include <vector>
#include <iterator>
#include <algorithm>
#include <regex>
#include <string>

namespace spartsi{

    /*std::string ws() {
        return "\\s*";
    }

    std::string quoted_val() {
        return "\""+ws()+"(.*)"+ws()+"\"";
    }*/

    /*complete_parser_t tree_begin_parser(view_of<langspec> lang){
        return { {
            {std::regex{"^"+ws()+lang.tree.begin+quoted_val()+ws()+"$"}, 2},
            {std::regex{"^"+ws()+lang.tree.begin+quoted_val()+ws()+lang.tree.name+whitespaces()+quoted_val()+ws()+"$"}, 3} },
            [](){}
        };
    }*/

    /*parsers_t get_parsers(spartsi::builder::tree_builder &builder, view_of<langspec> lang){
        parsers_t result;
        return result;
    }*/

    template<typename Str>
    typename node<Str>::shared parse(Str lines_source, langspec<Str> lang = default_::langspec) {
        std::vector<Str> lines;
        std::copy(lines_source.begin(), lines_source.end(), std::ostream_iterator<Str>(std::back_inserter(lines), "\n"));

        auto builder = spartsi::builder::build();

        /*parsers_t parsers = get_parsers(builder);
        for(auto line: lines) {
            for(auto &parser: parsers){

            }
        }*/
        return node<Str>::spawn_root("", "", "");
    }
}