#ifndef Classes_h
#define Classes_h
#pragma once
#include <iostream>
#include <fstream>

using namespace std;

ofstream fout;
ifstream fin;

class Exceptions {
	char* err;
public:
	Exceptions(char*_err) : err(_err){};
	char* what() { return err; };
};

class Element_not_found : public Exceptions{
public:
	Element_not_found() :Exceptions("The element wasn't found!"){};
};

class File_Not_Open : public Exceptions{
public:
	File_Not_Open() :Exceptions("The file wasn't opened!"){};
};

template<typename T>
struct Node { 
	int key;
	T data;
	Node* left;
	Node* right;
};

template<class T>
class BST {
private:
	Node<T> *root;
public:
	BST();

        BST(int key, T data);

	void Insert(Node<T> *&tmp, int key, T data);

	Node<T>* Search(int K);

	bool Delete(Node<T> *&tmp, int key);
	void Delete_tmp(Node<T> *&tmp);

	template<class U>
	friend ostream &operator<<(ostream &os, const BST<U> &tmp);

	template<class U>
	friend fstream &operator<<(std::fstream &file, BST<U> &tmp);

	template<class U>
	friend fstream &operator>>(std::fstream &file, BST<U> &tmp);

	void Print(Node<T> *tmp) const;

	void PrintInFile(ostream &os, Node<T> *tmp);

	void WriteInFile(ostream &os);

	void ReadFromFile(string text);

	Node<T>* get_root() { return root; };
};


#endif
