
#include <BST.cpp>
#include <catch.hpp>
#include <fstream>
#include <iostream>
using namespace std;

SCENARIO("Search init", "[init]") {
BST<int> tree;
Node<int>* tmp;
Node<int>* Root = tree.get_root();
tree.Insert(Root, 6, 100);
tree.Insert(Root, 0, 200);
tree.Insert(Root, -5, 800);
tree.Insert(Root, 12, 44);
REQUIRE(tmp = tree.Search(6));
REQUIRE(tmp =tree.Search(0));
REQUIRE(tmp =tree.Search(-5));
REQUIRE(tmp =tree.Search(12));
REQUIRE
(tree.Search(11);
catch(Element_not_found errorrr););
REQUIRE(tree.Search(1);
catch(Element_not_found errorrr););
}
