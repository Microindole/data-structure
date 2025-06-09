#pragma once

#include<iostream>
#include"stack.h"
#include"queue.h"

template<typename T>
struct TreeNode {
	T* data;
	TreeNode* left;
	TreeNode* right;
	TreeNode(T* value) : data(value), left(nullptr), right(nullptr) {}
};

template<typename T>
class BinaryTree {
private:
	TreeNode<T>* root;
public:
	BinaryTree() : root(nullptr) {}

	~BinaryTree() {
		clear(root);
	}

	TreeNode<T> *  createHelper() {
		T value;
		std::cout << "root: " << std::endl;
		cin >> value;
		if (value == -1) {
			return nullptr;
		}
		TreeNode<T>* node = new TreeNode<T>(value);
		std::cout << "left: " << std::endl;
		node->left = createHelper();
		std::cout << "right: " << std::endl;
		node->right = createHelper();
		return node;
	}

	void create() {
		root = createHelper();
	}



	void clear(TreeNode<T>* node) {
		if (node) {
			clear(node->left);
			clear(node->right);
			delete node;
		}
	}

	void predg(TreeNode<T> node, stack<T>* result) {
		if (root == nullptr) return;
		result->push(node->data);
		predg(node->left, result);
		predg(node->right, result);
	}



	void indg(TreeNode<T> node, stack<T>* result) {
		if (root == nullptr) return;
		indg(node->left, result);
		result->push(node->data);
		indg(node->right, result);
	}

	void indd(TreeNode<T> node, stack<T>* result) {
		if (root == nullptr) return;
		result->push(node->data);
		stack<T> s;
		TreeNode<T>* current = node;
		while (current != nullptr || !s.isEmpty()) {
			while (current != nullptr) {
				s.push(current);
				current = current->left;
			}
			current = s.top();
			s.pop();
			result.push_back(current->data);

			// ת��������
			current = current->right;
		}
		delete[] s;

	}

	void postdg(TreeNode<T> node, stack<T>* result) {
		if (root == nullptr) return;
		postdg(node->left, result);
		postdg(node->right, result);
		result->push(node->data);
	}

};
