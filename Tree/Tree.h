#pragma once



#include<iostream>
#include"Stack.h"
#include"Queue.h"
using namespace std;


template<typename T>
struct TreeNode {
    T data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(T value) {
        this->data = value;
        this->left = nullptr;
        this->right = nullptr;
    }
};

template<typename T>
class BinaryTree {
    TreeNode<T>* root;
    // �ݹ��������ĸ�������
    void destroyTree(TreeNode<T>* node);
    // �ݹ�����ĸ�������
    void preOrderTraversal(TreeNode<T>* node) const;
    void inOrderTraversal(TreeNode<T>* node) const;
    void postOrderTraversal(TreeNode<T>* node) const;
    // �������ĵݹ鸨������
    TreeNode<T>* createTreeHelper();

public:
    BinaryTree() :root(nullptr) {}
    ~BinaryTree() { destroyTree(root); }

    void createTree();
    void preOrderTraverse() const;
    void inOrderTraverse() const;
    void postOrderTraverse() const;

    // 3. �ǵݹ�ͳ�ƹ���
    int countNodes() const;       // ͳ�ƽڵ����
    int countDegree1Nodes() const; // ͳ�ƶ�Ϊ1�Ľڵ����
    int countDegree2Nodes() const; // ͳ�ƶ�Ϊ2�Ľڵ����
    int countLeafNodes() const;    // ͳ��Ҷ�ӽڵ����
    T findMax() const;            // �������ֵ
    T findMin() const;            // ������Сֵ

    // 4. ��α�����ѡ�����ݣ�
    void levelOrderTraverse() const;
};

template<typename T>
TreeNode<T>* BinaryTree<T>::createTreeHelper() {
    T value;
    cout << "������ڵ�ֵ(-1��ʾ�սڵ�)" << endl;
    cin >> value;
    if (value == -1) {
        return nullptr;
    }
    TreeNode<T>* node = new TreeNode<T>(value);
    cout << "�����ڵ�ֵΪ:" << value << "��������" << endl;
    node->left = createTreeHelper();
    cout << "�����ڵ�ֵΪ:" << value << "��������" << endl;
    node->right = createTreeHelper();
    return node;
}

template<typename T>
void BinaryTree<T>::destroyTree(TreeNode<T>* node) {
    if (node == nullptr) return;
    destroyTree(node->left);
    destroyTree(node->right);
    delete node;
}

template<typename T>
void BinaryTree<T>::preOrderTraversal(TreeNode<T>* node) const {
    if (node == nullptr) return;
    cout << node->data << " ";
    preOrderTraversal(node->left);
    preOrderTraversal(node->right);
}

template<typename T>
void BinaryTree<T>::inOrderTraversal(TreeNode<T>* node) const {
    if (node == nullptr) return;
    inOrderTraversal(node->left);
    cout << node->data << " ";
    inOrderTraversal(node->right);
}

template<typename T>
void BinaryTree<T>::postOrderTraversal(TreeNode<T>* node) const {
    if (node == nullptr) return;
    postOrderTraversal(node->left);
    postOrderTraversal(node->right);
    cout << node->data << " ";
}


template<typename T>
void BinaryTree<T>::createTree() {
    root = createTreeHelper();
}

template<typename T>
void BinaryTree<T>::preOrderTraverse() const {
    cout << "��������Ľ����" << endl;
    preOrderTraversal(root);
    cout << endl;
}

template<typename T>
void BinaryTree<T>::inOrderTraverse() const {
    cout << "��������Ľ����" << endl;
    inOrderTraversal(root);
    cout << endl;
}

template<typename T>
void BinaryTree<T>::postOrderTraverse() const {
    cout << "��������Ľ����" << endl;
    postOrderTraversal(root);
    cout << endl;
}

template<typename T>
int BinaryTree<T>::countNodes() const {
    int count = 0;
    Stack<TreeNode<T>*> q;
    if (root == nullptr) return count;
    q.push(root);
    while (!q.empty()) {
        TreeNode<T>* current = q.peek();
        q.pop();
        count++;
        if (current->right != nullptr) {
            q.push(current->left);
        }
        if (current->left != nullptr) {
            q.push(current->right);
        }
    }
    return count;
}

template<typename T>
int BinaryTree<T>::countDegree1Nodes() const {
    int count = 0;
    Stack<TreeNode<T>*> q;
    if (root == nullptr) return count;
    q.push(root);
    while (!q.empty()) {
        TreeNode<T>* current = q.peek();
        q.pop();
        if ((current->left && !current->right) || (!current->left && current->right)) count++;
        if (current->right != nullptr) {
            q.push(current->left);
        }
        if (current->left != nullptr) {
            q.push(current->right);
        }
    }
    return count;
}

template<typename T>
int BinaryTree<T>::countDegree2Nodes() const {
    int count = 0;
    Stack<TreeNode<T>*> q;
    if (root == nullptr) return count;
    q.push(root);
    while (!q.empty()) {
        TreeNode<T>* current = q.peek();
        q.pop();
        if (current->left && current->right) count++;
        if (current->right != nullptr) {
            q.push(current->left);
        }
        if (current->left != nullptr) {
            q.push(current->right);
        }
    }
    return count;
}

template<typename T>
int BinaryTree<T>::countLeafNodes() const {
    int count = 0;
    Stack<TreeNode<T>*> q;
    if (root == nullptr) return count;
    q.push(root);
    while (!q.empty()) {
        TreeNode<T>* current = q.peek();
        q.pop();
        if (!current->left && !current->right) count++;
        if (current->right != nullptr) {
            q.push(current->left);
        }
        if (current->left != nullptr) {
            q.push(current->right);
        }
    }
    return count;
}

template<typename T>
T BinaryTree<T>::findMax() const {
    T maxValue = root->data;
    Stack<TreeNode<T>*> q;
    if (root == nullptr) {
        throw std::runtime_error("��Ϊ�գ��޷��ҵ����ֵ");
    }
    q.push(root);
    while (!q.empty()) {
        TreeNode<T>* current = q.peek();
        q.pop();
        if (current->data > maxValue) maxValue = current->data;
        if (current->right != nullptr) {
            q.push(current->left);
        }
        if (current->left != nullptr) {
            q.push(current->right);
        }
    }
    return maxValue;
}

template<typename T>
T BinaryTree<T>::findMin() const {
    T minValue = root->data;
    Stack<TreeNode<T>*> q;
    if (root == nullptr) {
        throw std::runtime_error("��Ϊ�գ��޷��ҵ���Сֵ");
    }
    q.push(root);
    while (!q.empty()) {
        TreeNode<T>* current = q.peek();
        q.pop();
        if (current->data < minValue) minValue = current->data;
        if (current->right != nullptr) {
            q.push(current->left);
        }
        if (current->left != nullptr) {
            q.push(current->right);
        }
    }
    return minValue;
}

template <typename T>
void BinaryTree<T>::levelOrderTraverse() const {
    if (root == nullptr) {
        cout << "������Ϊ�գ�" << endl; 
        return;
    }

    cout << "��α������: ";
    Queue<TreeNode<T>*> q;
    q.in_queue(root);

    while (!q.queue_empty()) {
        TreeNode<T>* current = q.out_queue(); 

        if (current != nullptr) { 
            cout << current->data << " ";

            if (current->left) {
                q.in_queue(current->left);
            }
            if (current->right) {
                q.in_queue(current->right);
            }
        }
    }
    cout << endl;
}
