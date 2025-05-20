#include <iostream>
#include "Huffman.h"
using namespace std;

int main() {
    // 字母a-z，频率数据（请根据实际频率表调整，此处给出示例数据）
    const int n = 26;
    double freq[n] = {64, 13, 22, 32, 103, 21, 15, 47, 57, 1, 5, 32, 20, 57, 63, 15, 1, 48, 51, 80, 23, 8, 18, 1, 16, 1};

    // 创建霍夫曼编码对象
    HuffmanCode huffman_code(n, freq);
    huffman_code.PrintCodes();
    string encode = "ffgjkl";
    string decode = "0001100011110001000001000000001111111";
    cout<<"ffgjkl code result:" << huffman_code.Encode(encode) << endl;
    cout<<"0001100011110001000001000000001111111 decode result:" << huffman_code.Decode(decode) << endl;
    // ffgjkl
    //  0001100011110001000001000000001111111


    return 0;
}