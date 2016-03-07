#pragma once

#include <vector>
#include <functional>

#include "parser/impl/comment/comment.hpp"
#include "parser/impl/tree/tree_begin.hpp"
#include "parser/impl/tree/tree_end.hpp"
#include "parser/impl/node/node_begin.hpp"
#include "parser/impl/node/node_end.hpp"

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