#include "catch/catch.hpp"
#include "builder/tree-builder.hpp"

TEST_CASE("Ref attrs", "[spartsi::builder]") {
    using namespace spartsi::builder;

    auto tree = build()
        .treestructinfo("2.0").name("ref attrs")
            ("foo")
            .ref_attr("1")

            .node("1st node")
                .ref_attr("2")
            .end_node()

            .node("2nd node")
                .ref_attr("3")

                .node("2nd 1st node")
                    .ref_attr("4")
                .end_node()
            .end_node()
        .end_tree()

        ("bar")
        .ref_attr("1", "one")
        .ref_attr("2", "two")
        .ref_attr("3", "three")
        .ref_attr("4", "four")

        .get();


    SECTION("asserts") {
        SECTION("1st ref attr") {
            REQUIRE((tree->attributes.at("1").first == "one"));
            REQUIRE((tree->attributes.at("1").second == "foo\nbar"));
        }

        SECTION("2nd ref attr") {
            REQUIRE((tree->children.at("1st node")->attributes.at("2").first == "two"));
        }

        SECTION("3rd ref attr") {
            REQUIRE((tree->children.at("2nd node")->attributes.at("3").first == "three"));
        }

        SECTION("4th ref attr") {
            REQUIRE((tree->children.at("2nd node")->children.at("2nd 1st node")->attributes.at("4").first == "four"));
        }
    }
}