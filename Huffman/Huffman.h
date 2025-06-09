#pragma once

#include <iostream>
#include <string>
using namespace std;

class HuffmanCode {
    int n; 
    int size; 
    double* word; 
    int* parent;
    int* left;
    int* right; 
    string* result;

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
    // 构造函数：用传入数组构造
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

    // 构造霍夫曼树
    void FinishArray() {
        // 对于 i = n 到 size-1 依次构造内部节点
        for (int i = n; i < size; i++) {
            int s1 = -1, s2 = -1;
            for (int j = 0; j < i; j++) {
                if (parent[j] == -1) {
                    if (s1 == -1 || word[j] < word[s1]){
                        s2 = s1;
                        s1 = j;
                    }
                    else if (s2 == -1 || word[j] < word[s2]){
                        s2 = j;
                    }
                }
            }
            parent[s1] = i;
            parent[s2] = i;
            word[i] = word[s1] + word[s2];
            left[i] = s1;
            right[i] = s2;
        }
    }
    void GenerateCodes() {
        for (int i = 0; i < n; i++) {
            string code = "";
            int current = i;
            int p = parent[current];
            while (p != -1) {
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
            cout << char('a' + i) << ": " << result[i] << endl;
        }
    }

	// 编码函数
    string Encode(const string &input) {
        string encoded = "";
        for (char ch : input) {
            if (ch < 'a' || ch > 'z') continue;
            encoded += result[ch - 'a'];
        }
        return encoded;
    }

    // 解码函数
    string Decode(const string &encoded) {
        string decoded = "";
        int root = size - 1;
        int current = root;
        for (char bit : encoded) {
            if (bit == '0') {
                current = left[current];
            } else if (bit == '1') {
                current = right[current];
            }
            if (current < n) {
                decoded += char('a' + current);
                current = root;
            }
        }
        return decoded;
    }
};