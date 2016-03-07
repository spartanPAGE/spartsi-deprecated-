cmake_minimum_required(VERSION 3.4)
project(spartsi)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

include_directories(dep)
include_directories(src)

set(SOURCE_FILES test/main.cpp test/node/node-basic-test.cpp test/node/node-children-test.cpp src/langspec/default.cpp src/builder/tree-builder.cpp test/builder/sample.cpp test/builder/ref_attrs.cpp test/builder/ref_nodes.cpp test/builder/simplified_sample_from_treestructinfo_website.cpp test/builder/linked_trees.cpp test/parser/impl/tree_begin.cpp src/parser/impl/util.cpp test/parser/impl/comment.cpp test/parser/impl/integration/commented_tree.cpp test/parser/impl/integration/tree_with_nodes.cpp)
add_executable(spartsi ${SOURCE_FILES})

