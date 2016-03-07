#include "langspec/langspec.hpp"
#include "builder/tree-builder.hpp"

#include "util.hpp"

namespace spartsi {
    namespace parser {
        template<typename Str>
        bool node_begin(builder::tree_builder &bld, langspec<Str> spec, const Str &line) {
            using namespace util;
            std::smatch m;

            std::string pattern = spec.node.begin + " " + capture_quoted;

            if(std::regex_match(line, m, weak_reg(pattern))) {
                bld.node(m[1]);
                return true;
            }

            return false;
        }
    }
}