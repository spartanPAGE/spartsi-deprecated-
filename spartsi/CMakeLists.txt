cmake_minimum_required(VERSION 3.4)
project(spartsi)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

include_directories(dep)
include_directories(src)

set(SOURCE_FILES test/main.cpp test/node/node-basic-test.cpp test/node/node-children-test.cpp src/langspec/default.cpp src/builder/tree-builder.cpp test/builder/sample.cpp test/builder/ref-attrs.cpp test/builder/ref-nodes.cpp test/builder/simplified-sample-from-treestructinfo-website.cpp test/builder/linked-trees.cpp test/parser/impl/tree/tree-begin.cpp src/parser/impl/util.cpp test/parser/impl/comment/comment.cpp test/parser/impl/integration/commented-tree.cpp test/parser/impl/integration/tree-with-nodes.cpp test/parser/impl/tree/tree-end.cpp test/parser/impl/node/node-end.cpp test/parser/impl/node/node-begin.cpp test/parser/impl/attr/attr.cpp test/parser/impl/integration/attrs.cpp test/parser/impl/ref-attr/attr-declare.cpp test/parser/impl/ref-attr/attr-define.cpp)
add_executable(spartsi ${SOURCE_FILES})

