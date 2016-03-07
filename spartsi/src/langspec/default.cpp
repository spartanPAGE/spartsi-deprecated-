#include "default.hpp"

namespace spartsi {
    namespace default_ {
        using langspec_t = spartsi::langspec<std::string>;

        const langspec_t langspec = {
            langspec_t::tree_t{
                "treestructinfo",
                "name",
                "end tree"
            },

            langspec_t::attr_t{
                "attr"
            },

            langspec_t::ref_attr_t{
                "ref attr"
            },

            langspec_t::node_t{
                "node",
                "end node"
            },

            langspec_t::ref_node_t{
                "ref node",
                "end ref node"
            },

            langspec_t::comment_t{
                "::"
            }
        };
    }
}