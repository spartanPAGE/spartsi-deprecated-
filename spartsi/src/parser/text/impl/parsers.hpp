#pragma once

#include <vector>
#include <functional>

#include <parser/text/impl/attr/attr.hpp>
#include <parser/text/impl/ref-attr/attr-declare.hpp>
#include <parser/text/impl/ref-attr/attr-define.hpp>
#include <parser/text/impl/ref-node/node-decl-def.hpp>
#include <parser/text/impl/ref-node/ref-node-end.hpp>

#include "parser/text/impl/comment/comment.hpp"
#include "parser/text/impl/tree/tree-begin.hpp"
#include "parser/text/impl/tree/tree-end.hpp"
#include "parser/text/impl/node/node-begin.hpp"
#include "parser/text/impl/node/node-end.hpp"

namespace spartsi {
    namespace parser {
        template<typename Str>
        using raw_parser_t = std::function<bool(builder::tree_builder &bld, langspec<Str> spec, const Str &line)>;

        template<typename Str>
        std::vector<raw_parser_t<Str>> get_parsers() {

            return {
                &comment<Str>,
                &tree_begin<Str>,
                &tree_end<Str>,
                &node_begin<Str>,
                &node_end<Str>,
                &attr<Str>,
                &attr_define<Str>,
                &attr_declare<Str>,
                &node_decl_def<Str>,
                &ref_node_end<Str>
            };
        }
    }
}