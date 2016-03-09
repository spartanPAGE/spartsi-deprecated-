#include "catch/catch.hpp"

#include "langspec/default.hpp"
#include "core/strf.hpp"

#include "parser/text/parse.hpp"

using namespace std;

TEST_CASE("commented tree", "[spartsi::parser::*general*") {
    SECTION("sample") {
        auto lang = spartsi::default_::langspec;

        std::string source = SPARTSI_STRF('#',
            :: Sample comment                             #
            treestructinfo "2.0" name "commented tree"    #
            end tree                                      #
        );

        INFO(source);

        auto tree = spartsi::parse(source, lang);

        REQUIRE(tree->version == "2.0");
        REQUIRE(tree->name == "commented tree");
        REQUIRE(tree->comment == "Sample comment");
    }
}