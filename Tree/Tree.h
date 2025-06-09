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
    // 递归销毁树的辅助函数
    void destroyTree(TreeNode<T>* node);
    // 递归遍历的辅助函数
    void preOrderTraversal(TreeNode<T>* node) const;
    void inOrderTraversal(TreeNode<T>* node) const;
    void postOrderTraversal(TreeNode<T>* node) const;
    // 创建树的递归辅助函数
    TreeNode<T>* createTreeHelper();

public:
    BinaryTree() :root(nullptr) {}
    ~BinaryTree() { destroyTree(root); }

    void createTree();
    void preOrderTraverse() const;
    void inOrderTraverse() const;
    void postOrderTraverse() const;

    // 3. 非递归统计功能
    int countNodes() const;       // 统计节点个数
    int countDegree1Nodes() const; // 统计度为1的节点个数
    int countDegree2Nodes() const; // 统计度为2的节点个数
    int countLeafNodes() const;    // 统计叶子节点个数
    T findMax() const;            // 查找最大值
    T findMin() const;            // 查找最小值

    // 4. 层次遍历（选作内容）
    void levelOrderTraverse() const;
};

template<typename T>
TreeNode<T>* BinaryTree<T>::createTreeHelper() {
    T value;
    cout << "请输入节点值(-1表示空节点)" << endl;
    cin >> value;
    if (value == -1) {
        return nullptr;
    }
    TreeNode<T>* node = new TreeNode<T>(value);
    cout << "创建节点值为:" << value << "的左子树" << endl;
    node->left = createTreeHelper();
    cout << "创建节点值为:" << value << "的右子树" << endl;
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
    cout << "先序遍历的结果：" << endl;
    preOrderTraversal(root);
    cout << endl;
}

template<typename T>
void BinaryTree<T>::inOrderTraverse() const {
    cout << "中序遍历的结果：" << endl;
    inOrderTraversal(root);
    cout << endl;
}

template<typename T>
void BinaryTree<T>::postOrderTraverse() const {
    cout << "后序遍历的结果：" << endl;
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
        throw std::runtime_error("树为空，无法找到最大值");
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
        throw std::runtime_error("树为空，无法找到最小值");
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
        cout << "二叉树为空！" << endl; 
        return;
    }

    cout << "层次遍历结果: ";
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
