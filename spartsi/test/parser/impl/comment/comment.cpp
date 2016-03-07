#include "catch/catch.hpp"

#include "parser/impl/comment/comment.hpp"
#include "langspec/default.hpp"
using namespace std;

TEST_CASE("comment", "[spartsi::parser::comment") {
    auto spec = spartsi::default_::langspec;

    auto bld = spartsi::builder::build();

    SECTION("good nonempty") {
        std::string line = ":: Hello World! ";
        bld.comment.pull();
        REQUIRE(spartsi::parser::comment(bld, spec, line));
        REQUIRE(bld.comment.pull() == "Hello World!");
    }

    SECTION("good empty") {
        std::string line = "::";
        REQUIRE(spartsi::parser::comment(bld, spec, line));
        REQUIRE(bld.comment.pull() == "");
    }

    SECTION("bad") {
        std::string line = "blahblah";
        REQUIRE_FALSE(spartsi::parser::comment(bld, spec, line));
        REQUIRE(bld.comment.pull() == "");
    }
}