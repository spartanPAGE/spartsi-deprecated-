#include "catch/catch.hpp"
#include "builder/tree-builder.hpp"

TEST_CASE("http://treestruct.info/pl/format/2.0.htm#idSampleFile", "[spartsi::builder]") {
    using namespace spartsi::builder;

    auto tree = build()

        ("This is a sample TreeStructInfo tree")
        ("")
        ("one may comment any element of the tree")
        ("and make single and multi line comments")
        .treestructinfo("2.0").name("Sample Tree")

             ("bunch of infos about the TreeStructInfo author")
            .node("Owner")
                ("whitespace separated name? Pff, go on")
                .attr("Real Name", "Jarosław Baran")
                .attr("Know As", "furious programming")
                ("Restrictions on data format? Pff, whatever")
                .attr("DoB", "monday, 25.10.2011, 19:20")
                .attr("Profile", "http://4programmers.net/Profile/49548")
            .end_node()

             ("Some primitives")
            .node("Data Types")
                ("Booleans")
                .node("Boolean")
                    .attr("First", "True")
                    .attr("Turned", "Off")
                .end_node()

                ("Integers, floats or money")
                .node("Numbers")
                    .attr("Integer", "0xC0FFEE")
                    .attr("Float", "3,1415926535")
                    .attr("Cigarettes Price", "12,80 zł")
                .end_node()

                ("Strings and chars")
                .node("Characters")
                    ("Single char or seq of chars")
                    .attr("Char Value", "√")
                    .attr("Single String", "Informácie o stromová štruktúra")
                    ("or multiline value - we are pulling attribute from tree body")
                    .req_attr("Multiline String")
                .end_node()

                ("Other data types - node is defined outside of the tree body")
                .req_node("Other Data Types")
            .end_node()

        .end_tree()

        ("multiline string")
        ("well, terminators preparation is a job for the parser")
        .ref_attr("Multiline String",
                  "Tree Structure Inormation\n"
                  "Text and binary config format")

        ("Other data types")
        .ref_node("Other Data Types")
            ("point, resolution or whatever")
            .attr("Resolution", "0o2000,0o1400")
            ("binary data - pulled out, again")
            .req_node("Binary Buffers")
        .end_ref_node()

        ("Content of streams or other buffer data")
        .ref_node("Binary Buffers")
            ("Ref forever! Becouse of why not?")
            .req_attr("Some Stream Data")
            .req_attr("Any Buffer Data")
        .end_ref_node()

        ("Some stream data")
        .ref_attr("Some Stream Data", "123123123123123")

        ("Any bytes in any line!")
        .ref_attr("Any Buffer Data", "121212\n131313\n1313131313")

        .get();


    /* no assertions; whatever */
}