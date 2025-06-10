#include <iostream>
#include <vector>
#include <stack>
#include <algorithm> // 用于 std::reverse

// 定义二叉树结点
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// --- 辅助函数：打印结果 ---
void printVector(const std::string& title, const std::vector<int>& vec) {
    std::cout << title << ":\t";
    for (int val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}


// ===================================
// 前序遍历 (Pre-order: 根-左-右)
// ===================================

// 递归辅助函数
void preorderHelper(TreeNode* node, std::vector<int>& result) {
    if (node == nullptr) {
        return;
    }
    result.push_back(node->val); // 1. 访问根结点
    preorderHelper(node->left, result);  // 2. 递归遍历左子树
    preorderHelper(node->right, result); // 3. 递归遍历右子树
}

// 1. 前序遍历 - 递归版
std::vector<int> preorderRecursive(TreeNode* root) {
    std::vector<int> result;
    preorderHelper(root, result);
    return result;
}

// 2. 前序遍历 - 非递归版 (使用栈)
std::vector<int> preorderIterative(TreeNode* root) {
    std::vector<int> result;
    if (root == nullptr) {
        return result;
    }
    std::stack<TreeNode*> s;
    s.push(root);

    while (!s.empty()) {
        TreeNode* node = s.top();
        s.pop();
        result.push_back(node->val); // 访问根

        // 注意：先压入右子结点，再压入左子结点，保证左子结点先被访问
        if (node->right) {
            s.push(node->right);
        }
        if (node->left) {
            s.push(node->left);
        }
    }
    return result;
}

// ===================================
// 中序遍历 (In-order: 左-根-右)
// ===================================

// 递归辅助函数
void inorderHelper(TreeNode* node, std::vector<int>& result) {
    if (node == nullptr) {
        return;
    }
    inorderHelper(node->left, result);  // 1. 递归遍历左子树
    result.push_back(node->val); // 2. 访问根结点
    inorderHelper(node->right, result); // 3. 递归遍历右子树
}

// 3. 中序遍历 - 递归版
std::vector<int> inorderRecursive(TreeNode* root) {
    std::vector<int> result;
    inorderHelper(root, result);
    return result;
}

// 4. 中序遍历 - 非递归版 (使用栈)
std::vector<int> inorderIterative(TreeNode* root) {
    std::vector<int> result;
    std::stack<TreeNode*> s;
    TreeNode* curr = root;

    while (curr != nullptr || !s.empty()) {
        // 将所有左子结点压入栈
        while (curr != nullptr) {
            s.push(curr);
            curr = curr->left;
        }

        // 弹出栈顶元素并访问
        curr = s.top();
        s.pop();
        result.push_back(curr->val);

        // 转向右子树
        curr = curr->right;
    }
    return result;
}

// ===================================
// 后序遍历 (Post-order: 左-右-根)
// ===================================

// 递归辅助函数
void postorderHelper(TreeNode* node, std::vector<int>& result) {
    if (node == nullptr) {
        return;
    }
    postorderHelper(node->left, result);  // 1. 递归遍历左子树
    postorderHelper(node->right, result); // 2. 递归遍历右子树
    result.push_back(node->val); // 3. 访问根结点
}

// 5. 后序遍历 - 递归版
std::vector<int> postorderRecursive(TreeNode* root) {
    std::vector<int> result;
    postorderHelper(root, result);
    return result;
}

// 6. 后序遍历 - 非递归版 (巧妙方法)
// 思路：后序是“左-右-根”，它的逆序是“根-右-左”。
// “根-右-左”的遍历顺序与前序“根-左-右”非常类似，只需交换左右子树的入栈顺序即可。
// 所以我们可以先按“根-右-左”的顺序遍历，最后将结果向量反转。
std::vector<int> postorderIterative(TreeNode* root) {
    std::vector<int> result;
    if (root == nullptr) {
        return result;
    }
    std::stack<TreeNode*> s;
    s.push(root);

    while (!s.empty()) {
        TreeNode* node = s.top();
        s.pop();
        result.push_back(node->val);

        // 与前序相反，先压入左子结点，再压入右子结点
        if (node->left) {
            s.push(node->left);
        }
        if (node->right) {
            s.push(node->right);
        }
    }

    // 将结果反转，从“根-右-左”变为“左-右-根”
    std::reverse(result.begin(), result.end());
    return result;
}


// ===================================
// 主函数 - 测试
// ===================================
int main() {
    // 构建一个测试用的二叉树:
    //      1
    //     / \
    //    2   3
    //   / \
    //  4   5
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    std::cout << "--- 前序遍历 (Pre-order) ---" << std::endl;
    printVector("递归", preorderRecursive(root));
    printVector("非递归", preorderIterative(root));
    // 预期输出: 1 2 4 5 3

    std::cout << "\n--- 中序遍历 (In-order) ---" << std::endl;
    printVector("递归", inorderRecursive(root));
    printVector("非递归", inorderIterative(root));
    // 预期输出: 4 2 5 1 3

    std::cout << "\n--- 后序遍历 (Post-order) ---" << std::endl;
    printVector("递归", postorderRecursive(root));
    printVector("非递归", postorderIterative(root));
    // 预期输出: 4 5 2 3 1
    
    // 清理内存 (简单示例，实际项目应使用智能指针或更完善的清理机制)
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
