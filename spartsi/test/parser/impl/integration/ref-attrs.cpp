#include "catch/catch.hpp"

#include "langspec/default.hpp"
#include "core/strf.hpp"

#include "parser/text/parse.hpp"

using namespace std;

TEST_CASE("ref attrs", "[spartsi::parser::*general*") {
    SECTION("sample") {

        std::string source = SPARTSI_STRF('#',
            treestructinfo "2.0" name "ref attrs"  #
              ref attr secret                      #
              node first                           #
                ref attr data                      #
              end node                             #
              node second                          #
                ref attr data                      #
              end node                             #
            end tree                               #
            ref attr secret "honey"                #
            ref attr data "1st data"               #
            ref attr data "2nd data"               #
        );

        auto tree = spartsi::parse(source);

        REQUIRE(tree->attributes.at("secret").first == "honey");
        REQUIRE(tree->children.at("first")->attributes.at("data").first == "1st data");
        REQUIRE(tree->children.at("second")->attributes.at("data").first == "2nd data");
    }
}