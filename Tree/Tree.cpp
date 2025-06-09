#include <iostream>
#include "Tree.h"

int main() {
    BinaryTree<double> tree;

    // 1. 创建二叉树
    cout << "请按照提示创建二叉树：" << endl;
    tree.createTree();

    // 2. 遍历二叉树
    tree.preOrderTraverse();
    tree.inOrderTraverse();
    tree.postOrderTraverse();

    // 3. 统计节点信息
    cout << "\n统计信息：" << endl;
    cout << "节点总数: " << tree.countNodes() << endl;
    std::cout << "度为1的节点数: " << tree.countDegree1Nodes() << std::endl;
    std::cout << "度为2的节点数: " << tree.countDegree2Nodes() << std::endl;
    std::cout << "叶子节点数: " << tree.countLeafNodes() << std::endl;

    try {
        std::cout << "最大值: " << tree.findMax() << std::endl;
        std::cout << "最小值: " << tree.findMin() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    // // 4. 层次遍历
    tree.levelOrderTraverse();

    return 0;
}



