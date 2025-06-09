#include <iostream>
#include "Huffman.h"
using namespace std;

int main() {
    const int n = 26;
    double freq[n] = {64, 13, 22, 32, 103, 21, 15, 47, 57, 1, 5, 32, 20, 57, 63, 15, 1, 48, 51, 80, 23, 8, 18, 1, 16, 1};
    // 创建霍夫曼编码对象
    HuffmanCode huffman_code(n, freq);
    huffman_code.PrintCodes();
    string toCode;
    cout << "input the string: " << endl;
    cin >> toCode;
    cout << endl;
    cout<<toCode<<"  code result:" << huffman_code.Encode(toCode) << endl;
    string decode = huffman_code.Encode(toCode);
    cout << decode <<"decode result:" << huffman_code.Decode(decode) << endl;
    return 0;
}