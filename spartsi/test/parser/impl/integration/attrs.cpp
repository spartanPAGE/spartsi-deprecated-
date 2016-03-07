#include "catch/catch.hpp"

#include "langspec/default.hpp"
#include "core/strf.hpp"

#include "parser/parse.hpp"

using namespace std;

TEST_CASE("attrs", "[spartsi::parser::*general*") {
    SECTION("sample") {

        std::string source = SPARTSI_STRF('#',
            treestructinfo "2.0" name "attrs"             #
              attr secret "honey"                         #
              node first                                  #
                attr data "foo"                           #
              end node                                    #
              node second                                 #
                attr data "bar"                           #
              end node                                    #
            end tree                                      #
        );

        auto tree = spartsi::parse(source);

        SECTION("inline") {
            REQUIRE(tree->attributes.at("secret").first == "honey");
        }

        SECTION("nested") {
            REQUIRE(tree->children.at("first")->attributes.at("data").first == "foo");
            REQUIRE(tree->children.at("second")->attributes.at("data").first == "bar");
        }
    }
}