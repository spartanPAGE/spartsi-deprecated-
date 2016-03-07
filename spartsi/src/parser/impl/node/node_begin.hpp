#include "langspec/langspec.hpp"
#include "builder/tree-builder.hpp"

#include "parser/impl/util.hpp"

namespace spartsi {
    namespace parser {
        template<typename Str>
        bool node_begin(builder::tree_builder &bld, langspec<Str> spec, const Str &line) {
            using namespace util;
            std::smatch m;

            std::string pattern = spec.node.begin + " " + capture;

            if(std::regex_match(line, m, weak_reg(pattern))) {
                Str name = m[1];
                bld.node(Str(name.begin(), name.begin()+1+name.find_last_not_of(whitespaces)));
                return true;
            }

            return false;
        }
    }
}