#include "catch/catch.hpp"

#include "langspec/default.hpp"
#include "core/strf.hpp"

#include "parser/parse.hpp"

using namespace std;

TEST_CASE("tree with nodes", "[spartsi::parser::*general*") {
    SECTION("sample") {
        auto lang = spartsi::default_::langspec;

        std::string source = SPARTSI_STRF('#',
            :: Sample comment    #
            treestructinfo "2.0" #
                :: 1             #
                node first       #
                end node         #

                :: 2             #
                node second      #
                end node         #
            end tree             #
        );

        auto tree = spartsi::parse(source, lang);

        REQUIRE(tree->comment == "Sample comment");
        REQUIRE(tree->children.size() == 2);
        
        REQUIRE(tree->children.at("first")->comment == "1");
        REQUIRE(tree->children.at("second")->comment == "2");
    }
}