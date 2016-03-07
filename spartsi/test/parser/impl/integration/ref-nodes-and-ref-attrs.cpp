#include "catch/catch.hpp"

#include "langspec/default.hpp"
#include "core/strf.hpp"

#include "parser/parse.hpp"

using namespace std;

TEST_CASE("ref nodes and ref attrs", "[spartsi::parser::*general*") {
    SECTION("sample") {

        std::string source = SPARTSI_STRF('#',
            treestructinfo "2.0"    #
              attr normal "1"       #

              node normal           #
                attr normal "2"     #
                ref attr ref        #
              end node              #

              ref node ref          #
            end tree                #

            ref attr ref "3"        #

            ref node ref            #
              ref attr ref          #
            end ref node            #

            ref attr ref "4"        #
        );

        auto tree = spartsi::parse(source);

        REQUIRE(tree->attributes.at("normal").first == "1");
        REQUIRE(tree->children.at("normal")->attributes.at("normal").first == "2");

        REQUIRE(tree->children.at("normal")->attributes.at("ref").first == "3");

        REQUIRE(tree->children.at("ref")->attributes.count("ref"));
        REQUIRE(tree->children.at("ref")->attributes.at("ref").first == "4");
    }
}