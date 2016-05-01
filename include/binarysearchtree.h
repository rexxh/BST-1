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
