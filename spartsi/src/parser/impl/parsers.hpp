#pragma once

#include <vector>
#include <functional>

#include "comment.hpp"
#include "tree_begin.hpp"
#include "tree_end.hpp"
#include "node_begin.hpp"
#include "node_end.hpp"

namespace spartsi {
    namespace parser {
        template<typename Str>
        std::vector<std::function<bool(builder::tree_builder &bld, langspec<Str> spec, const Str &line)>> get_parsers() {

            return {
                &comment<Str>,
                &tree_begin<Str>,
                &tree_end<Str>,
                &node_begin<Str>,
                &node_end<Str>
            };
        }
    }
}