#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
#include "Classes.h"

template<class T>
BST<T>::BST(int key, T data)
{
	root = new Node<T>;
	root->key = key;
	root->data = data;
	root->left = nullptr;
	root->right = nullptr;
};

template<class T>
BST<T>::BST() 
{
	root = new Node<T>;
	std::cin >> root->key >> root->data;
	root->left = nullptr;
	root->right = nullptr;
};

template<class T>
Node<T>* BST<T>:: Search(int K) //Поиск элемента
{
	Node<T>* next;
	next = root;
	while (K != next->key)
	{
		if (K > next->key)
		{
			if (next->right == nullptr) {
				Element_not_found errorrr;
				throw errorrr; 
			}
			else
			{
				next = next->right;
			}
		}
		else
		{
			if (next->left == nullptr){
				Element_not_found errorrr;
				throw errorrr; 
			}
			else
			{
				next = next->left;
			}
		}
	};
	return next;
}

template<class T>
void BST<T>::Insert(Node<T> *&tmp, int key, T data) {
	if (tmp == NULL) {
		tmp = new Node<T>;
		tmp->right = nullptr;
		tmp->left = nullptr;
		tmp->key = key;
		tmp->data = data;
		return;
	}
	if (tmp->key > key) {
		Insert(tmp->left, key, data);
	}
	else {
		Insert(tmp->right, key, data);
	}
}

template<class T>
bool BST<T>::Delete(Node<T> *&tmp, int key) {
	if (tmp == NULL) {
		return false;
	}
	if (tmp->data == value) {
		Delete_tmp(tmp);
		return true;
	}
	return Delete(tmp->data > key ? tmp->left : tmp->right, key);
}

template<class T>
void BST<T>::Delete_tmp(Node<T> *&tmp) {
	if (tmp->left == NULL) {
		Node<T> *right = tmp->right;
		delete tmp;
		tmp = right;
	}
	else if (tmp->right == NULL) {
		Node<T> *left = tmp->left;
		delete tmp;
		tmp = left;
	}
	else {
		Node<T> *minParent = tmp;
		Node<T> *min = tmp->right;
		while (min->left != NULL) {
			minParent = min;
			min = min->left;
		}
		(minParent->left == min ? minParent->left : minParent->right) = min->right;
		tmp->key = min->key;
		tmp->data = min->data;
		delete min;
	}
}

template<class T>
void BST<T>::WriteInFile(ostream &os) {
	PrintInFile(os, root);
}

template<class T>
void BST<T>::PrintInFile(ostream &os, Node<T> *tmp) {

	if (tmp->left == NULL && tmp->right == NULL) {
		os << tmp->key << " "<< tmp->data <<"    ";
		return;
	}
	if (tmp->left != NULL) {
		PrintInFile(os, tmp->left);

	}

	if (tmp = root)
	{
		os << "260198 "; // Обозначение корневого элемента
	}
	os << tmp->key << " " << tmp->data << "    ";

	if (tmp->right != NULL) {
		PrintInFile(os, tmp->right);
	}
}

template<class T>
void BST<T>::ReadFromFile(string text) {
	try{
		ifstream file(text);
		if (!fout.is_open()) {
			throw File_Not_Open()
		}
		int key;
		T data;
		while (!file.eof()) {
			file >> key;
			if (key == 260198)
			{
				Node tmp;
				tmp.key = root->key;
				tmp.data = root->data;
				file >> key;
				file >> data;
				root->key = key;
				root->data = data;
				Insert(root, tmp.key, tmp.data);
			}
			else
			{
				file >> data;
				Insert(root, key, data);
			}
		}
		file.close();
	}
	catch (File_Not_Open i)
	{
		cout << i.what();
	}
}

template<class T>
void BST<T>::Print(Node<T> *tmp) const {

	if (tmp->left == NULL && tmp->right == NULL) {
		cout <<tmp->key << " " << tmp->data << "    ";
		return;
	}
	if (tmp->left != NULL) {
		Print(tmp->left);
	}

	cout << tmp->key << " " << tmp->data << "    ";

	if (tmp->right != NULL) {
		Print(tmp->right);
	}
};

template<class U>
fstream &operator<<(std::fstream &file, BST<U> &tmp) {
	tmp.PrintInFile(file, tmp.root);
	return file;
}

template<class U>
ostream &operator<<(ostream &os, const BST<U> &tmp) {
	tmp.Print(tmp.root);
	return os;
}

template<class U>
fstream &operator>>(std::fstream &file, BST<U> &tmp) {
	int key;
	U data;
	while(!file.eof()) {
		file >> key;
		file >> data;
		tmp.Insert(tmp.root, key, data);
	}
	return file;
}

