#include "binarysearchtree.h"
#include <iostream>
#include <fstream>
using namespace std;
Iscluchenia::Iscluchenia(char* _err) : err(_err){}
char* Iscluchenia::what() { return err; }
Uzhe_est::Uzhe_est() : Iscluchenia("ERROR: etot element uzhe dobavlen!") {}
File_Not_Open::File_Not_Open() : Iscluchenia("ERROR: file not open!") {}
Pustoe_derevo::Pustoe_derevo() : Iscluchenia("ERROR: derevo pusto!") {}

template <class Z>
BinarySearchTree<Z>::der::der(Z x) : D(x), l(nullptr), r(nullptr){}
template <class Z>
void BinarySearchTree<Z>::der::add(Z x){
	if (x < D){
		if (l != nullptr) l->add(x);
		if (l == nullptr) l = new der(x);
	}
	if (x>D){
		if (r != nullptr) r->add(x);
		if (r == nullptr) r = new der(x);
	}
}
template <class Z>
bool BinarySearchTree<Z>::der::search(Z x){
	if (x == D) { return true; }
	if (x > D) if (r != nullptr) return(r->search(x));
	if (x < D) if (l != nullptr) return(l->search(x));
	return false;
}
template <class Z>
void BinarySearchTree<Z>::der::print_console(){
	if (l != nullptr) l->print_console();
	cout << D << " ";
	if (r != nullptr) r->print_console();
}
template <class Z>
void BinarySearchTree<Z>::der::print_file(char* b){
	ofstream fout;
	fout.open(b, ios::app);
	if (fout.is_open()){
		if (l != nullptr) l->print_file(b);
		fout << D << " "; fout.close();
		if (r != nullptr) r->print_file(b);
	}
	fout.close();
}

template <class Z>
BinarySearchTree<Z>::BinarySearchTree() : root(nullptr){}
template <class Z>
bool BinarySearchTree<Z>::add(Z x){
	if (root != nullptr) if (search(x)) throw Uzhe_est();
	if (root == nullptr) { root = new der(x); return true; }
	else { root->add(x); return true; }
	return false;
}
template <class Z>
bool BinarySearchTree<Z>::search(Z x){
	if (root == nullptr) throw Pustoe_derevo();
	return(root->search(x));
}
template <class Z>
bool BinarySearchTree<Z>::read_file(char* a){
	ifstream fin; Z x;
	fin.open(a);
	if (fin.is_open()){
		while (!fin.eof()){
			fin >> x;
			this->add(x);
		}
		fin.close();
		return true;
	}
	throw File_Not_Open();
}
template <class Z>
void BinarySearchTree<Z>::print_file(char* b){
	if (root == nullptr) throw Pustoe_derevo();
	root->print_file(b);
}
template <class Z>
void BinarySearchTree<Z>::print_console(){
	if (root == nullptr) throw Pustoe_derevo();
	root->print_console();
}
