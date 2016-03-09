#include "catch/catch.hpp"

#include "langspec/default.hpp"
#include "core/strf.hpp"

#include "parser/text/parse.hpp"

using namespace std;

TEST_CASE("ref nodes", "[spartsi::parser::*general*") {
    SECTION("sample") {

        std::string source = SPARTSI_STRF('#',
            treestructinfo "2.0" name "ref nodes" #
              ref node First                      #
              node Inline                         #
                ref node Second                   #
              end node                            #
            end tree                              #

            ref node First                        #
              attr Foo "foo"                      #
            end ref node                          #

            ref node Second                       #
              attr Bar "bar"                      #
              ref node Third                      #
            end ref node                          #

            ref node Third                        #
              attr Eggs "eggs"                    #
            end ref node                          #
        );

        auto tree = spartsi::parse(source);


        REQUIRE(tree->children.count("First"));
        REQUIRE(tree->children.at("First")->attributes.at("Foo").first == "foo");

        REQUIRE(tree->children.at("Inline")->children.count("Second"));
        REQUIRE(tree->children.at("Inline")->children.at("Second")->attributes.at("Bar").first == "bar");

        REQUIRE(tree->children.at("Inline")->children.at("Second")->children.count("Third"));
        REQUIRE(tree->children.at("Inline")->children.at("Second")->children.at("Third")->attributes.at("Eggs").first == "eggs");
    }
}