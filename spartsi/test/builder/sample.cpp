#include "catch/catch.hpp"
#include "builder/tree-builder.hpp"

TEST_CASE("Sample builded tree", "[spartsi::builder]") {
    using namespace spartsi::builder;

    auto tree = build()

        ("This is a sample tree")
        ("which contains nodes, attributes and {single/multi}line comments")
        .treestructinfo("2.0").name("hello world!")
            ("keep it secret!")
            .attr("secret", "marshmallows")

            ("some foo")
            .node("foo")
                ("bla bla bla")
                ("bla bla bla")
                .attr("name", "Harold")
            .end_node()

            ("some bar")
            .node("bar")
                .attr("name", "Walter")
            .end_node()
        .end_tree();


    SECTION("asserts") {
        SECTION("Header") {
            REQUIRE((tree->name == "hello world!"));
            REQUIRE((tree->version == "2.0"));
            REQUIRE((tree->comment == "This is a sample tree\nwhich contains nodes, attributes and {single/multi}line comments"));
        }

        SECTION("Inline attribute") {
            auto &secret = tree->attributes.at("secret");
            REQUIRE((secret.first == "marshmallows"));
            REQUIRE((secret.second == "keep it secret!"));
        }

        SECTION("1st node: foo") {
            auto &foo = tree->children.at("foo");
            REQUIRE((foo->comment == "some foo"));
            auto &foo_name = foo->attributes.at("name");
            REQUIRE((foo_name.first == "Harold"));
            REQUIRE((foo_name.second == "bla bla bla\nbla bla bla"));
        }

    }
}