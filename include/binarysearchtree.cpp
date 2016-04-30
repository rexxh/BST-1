#ifndef BinarySearchTree_cpp
#define BinarySearchTree_cpp
#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Isclucheniya {
	char* err;
public:
	Isclucheniya(char* _err) : err(_err) {}
	char* what() { return err; }
};

class Uzhe_est : public Isclucheniya{
	char* err;
public:
	Uzhe_est() : Isclucheniya("ERROR: etot element uzhe dobavlen") {};
};

class FileNotOpen : public Isclucheniya{
	char* err;
public:
	FileNotOpen() : Isclucheniya("ERROR: file not open!") {};
};

class Pustoe_derevo : public Isclucheniya{
	char* err;
public:
	Pustoe_derevo() : Isclucheniya("ERROR: derevo pusto!") {};
};

template <class Z>
class BinarySearchTree{
public:
	BinarySearchTree() :root(nullptr){}
	bool add(Z x){
		if(root!=nullptr) if (search(x)) throw Uzhe_est();
		if (root == nullptr) { root = new der(x); return true; }
		else { root->add(x); return true; }
		return false;
	}
	bool search(Z x){ if (root == nullptr) throw Pustoe_derevo();
		return(root->search(x)); }
	bool read_file(char* a){
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
		throw FileNotOpen();
	}
	void print_file(char* b){
		if (root == nullptr) throw Pustoe_derevo();
		root->print_file(b);
	}
	void print_console(){
		if (root == nullptr) throw Pustoe_derevo();
		root->print_console();
	}
private:
	class der{
	public:
		der(Z x) :D(x), l(nullptr), r(nullptr){}
		void add(Z x){
			if (x < D){ 
				if (l != nullptr) l->add(x);
				if (l == nullptr) l = new der(x); 
			}
			if (x>D){
				if (r != nullptr) r->add(x);
				if (r == nullptr) r = new der(x);
			}
		}
		bool search(Z x){
			if (x == D) { return true; }
			if (x > D) if (r != nullptr) return(r->search(x));
			if (x < D) if (l != nullptr) return(l->search(x));
			return false;
		}

		void print_console(){
			if (l != nullptr) l->print_console();  
			cout << D << " ";
			if (r != nullptr) r->print_console();  
		}
		void print_file(char *b){
			ofstream fout;
			fout.open(b, ios::app);
			if (fout.is_open()){
				if (l != nullptr) l->print_file(b);
				fout << D << " "; fout.close();
				if (r != nullptr) r->print_file(b);
			}
			fout.close();
		}
	private:
		Z D;
		der *l;
		der *r;
	};
	der* root;
};


#define TAHK double

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
			catch (FileNotOpen &e) { cout << e.what() << endl; }
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
}
#endif
