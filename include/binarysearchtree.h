#ifndef binarysearchtree_h
#define binarysearchtree_h
#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Iscluchenia {
	char* err;
public:
	Iscluchenia(char* _err);
	char* what();
};

class Uzhe_est : public Iscluchenia{
public:
	Uzhe_est();
};

class File_Not_Open : public Iscluchenia{
public:
	File_Not_Open();
};

class Pustoe_derevo : public Iscluchenia{
public:
	Pustoe_derevo();
};

template <class Z>
class BinarySearchTree{
public:
	BinarySearchTree();
	bool add(Z x);
	bool search(Z x);
	bool read_file(char* a);
	void print_file(char* b);
	void print_console();
private:
	class der; 
	der* root;
};

template <class Z>
class BinarySearchTree<Z>::der{
public:
	der(Z x);
	void add(Z x);
	bool search(Z x);
	void print_console();
	void print_file(char *b);
private:
	Z D;
	der *l;
	der *r;
};


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


/*#define TAHK double

int main(){
	BinarySearchTree<TAHK> tree; int J;
	cout << "add-1, search-2, read_f-3, print_f-4, print_c-5, exit-0\n";
	do{
		cout << "J="; cin >> J;
		if (J == 1){
			TAHK x;
			cout << "x="; cin >> x;
			try{ if (tree.add(x))cout << "done\n"; }
			catch (Uzhe_est &e){ cout << e.what() << endl; }
		}
		if (J == 2){
			TAHK x;
			cout << "x="; cin >> x;
			try{ if (tree.search(x)) cout << "founded\n"; else cout << "not founded\n"; }
			catch (Pustoe_derevo &e) { cout << e.what() << endl; } 
		}
		if (J == 3){
			char a[20];
			cout << "name of file: "; cin >> a;
			try{ if (tree.read_file(a)) cout << "done\n"; }
			catch (File_Not_Open &e) { cout << e.what() << endl; }
		}
		if (J == 4){
			char b[20];
			cout << "name of file: "; cin >> b;
			try{ tree.print_file(b); }
			catch (Pustoe_derevo &e) { cout << e.what() << endl; }
		}
		if (J == 5){
			try{ tree.print_console(); cout << endl; }
			catch (Pustoe_derevo &e) { cout << e.what() << endl; }
		}
	} while (J);
	system("pause");
}*/
#endif
