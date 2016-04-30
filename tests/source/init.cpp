
#include <BinarySearchTree.cpp>
#include <catch.hpp>
#include <fstream>
#include <iostream>
using namespace std;

SCENARIO("Search init", "[init]") {
BinarySearchTree<int> tree;
tree.add(7);
tree.add(5);
tree.add(1);
tree.add(9);
tree.add(3);
REQUIRE(tree.search(7);
REQUIRE(tree.search(9);
REQUIRE(tree.search(5);
REQUIRE(tree.search(1);
REQUIRE(tree.search(3);
REQUIRE(!tree.search(0);
REQUIRE(!tree.search(8);
REQUIRE(!tree.search(6);
REQUIRE(!tree.search(4);
REQUIRE(!tree.search(2);
}
