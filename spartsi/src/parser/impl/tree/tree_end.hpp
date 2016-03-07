#include "langspec/langspec.hpp"
#include "builder/tree-builder.hpp"

#include "parser/impl/util.hpp"

namespace spartsi {
    namespace parser {
        template<typename Str>
        bool tree_end(builder::tree_builder &bld, langspec<Str> spec, const Str &line) {
            using namespace util;
            std::smatch m;

            std::string pattern = spec.tree.end;

            if(std::regex_match(line, m, weak_reg(pattern))) {
                bld.end_tree();
                return true;
            }

            return false;
        }
    }
}