#pragma once

#include <iostream>
#include <string>
using namespace std;

class HuffmanCode {
    int n;        // 叶子节点数（即字母数，26）
    int size;     // 总节点数 = 2*n - 1
    double* word;   // 存储每个节点的频率（前 n 个为叶节点，其余为合并节点）
    int* parent;  // 存储每个节点的父节点索引，若为-1表示无父节点
    int* left;    // 存储每个节点的左孩子索引，若为-1表示无
    int* right;   // 存储每个节点的右孩子索引，若为-1表示无
    string* result; // 存储每个叶节点的霍夫曼编码，对应字母从 'a' 开始

public:
    // 构造函数：叶节点数为 n
    HuffmanCode(int num) {
        n = num;
        size = 2 * n - 1;
        word = new double[size];
        parent = new int[size];
        left = new int[size];
        right = new int[size];
        result = new string[n];

        // 初始化前 n 个叶节点，后面内部节点初值置为0
        for (int i = 0; i < n; i++) {
            parent[i] = -1;
            left[i] = -1;
            right[i] = -1;
            word[i] = 0;
        }
        for (int i = n; i < size; i++) {
            parent[i] = -1;
            left[i] = -1;
            right[i] = -1;
            word[i] = 0;
        }
    }
    // 构造函数：直接用传入的频率数组构造（数组长度为 n）
    HuffmanCode(int num, double words[]) : HuffmanCode(num) {
        for (int i = 0; i < n; i++) {
            word[i] = words[i];
        }
        FinishArray();
        GenerateCodes();
        //PrintCodes();
    }
    ~HuffmanCode() {
        delete[] word;
        delete[] parent;
        delete[] left;
        delete[] right;
        delete[] result;
    }

    // 构造霍夫曼树（用静态数组实现）
    void FinishArray() {
        // 对于 i = n 到 size-1 依次构造内部节点
        for (int i = n; i < size; i++) {
            int s1 = -1, s2 = -1;
            // 遍历0到 i-1中，选择未被选取（parent==-1）的两个最小值
            for (int j = 0; j < i; j++) {
                if (parent[j] == -1) {
                    if (s1 == -1 || word[j] < word[s1])
                    {
                        s2 = s1;
                        s1 = j;
                    }
                    else if (s2 == -1 || word[j] < word[s2])
                    {
                        s2 = j;
                    }
                }
            }
            // 构造新节点 i
            parent[s1] = i;
            parent[s2] = i;
            word[i] = word[s1] + word[s2];
            left[i] = s1;
            right[i] = s2;
        }
    }

    // 生成霍夫曼编码，并保存在 result 数组中（叶节点 0 ~ n-1 分别对应 'a'...'z'）
    void GenerateCodes() {
        // 对每个叶节点从 0 到 n-1回溯到根，每走一步记录编码 ('0'代表左，'1'代表右)
        for (int i = 0; i < n; i++) {
            string code = "";
            int current = i;
            int p = parent[current];
            while (p != -1) {
                // 若当前节点是父节点的左孩子，则编码为 '0'
                if (left[p] == current)
                    code = "0" + code;
                else
                    code = "1" + code;
                current = p;
                p = parent[current];
            }
            result[i] = code;
        }
    }

    // 输出霍夫曼编码
    void PrintCodes() {
        cout << "Huffman Codes:" << endl;
        for (int i = 0; i < n; i++) {
            // 第 i 个叶节点对应的字符为 'a' + i
            cout << char('a' + i) << ": " << result[i] << endl;
        }
    }

	    // 编码函数：将输入字符串中每个字符替换为其霍夫曼编码，要求字符必须是 'a'~'z'
    string Encode(const string &input) {
        string encoded = "";
        for (char ch : input) {
            // 仅处理小写字母
            if (ch < 'a' || ch > 'z') continue;
            encoded += result[ch - 'a'];
        }
        return encoded;
    }

    // 解码函数：根据霍夫曼树将编码串还原为原始的字母序列
    string Decode(const string &encoded) {
        string decoded = "";
        // 霍夫曼树的根节点索引为 size - 1
        int root = size - 1;
        int current = root;
        for (char bit : encoded) {
            if (bit == '0') {
                current = left[current];
            } else if (bit == '1') {
                current = right[current];
            }
            // 到达叶节点
            if (current < n) {
                decoded += char('a' + current);
                current = root;
            }
        }
        return decoded;
    }
};