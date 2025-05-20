// Queue.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "CircleQueue.h"

int main()
{
    CircleQueue<int> queue;
    queue.in_queue(10);
    queue.in_queue(20);
    queue.in_queue(30);
    queue.in_queue(40);
    queue.in_queue(50);
    queue.in_queue(60);
    queue.print_queue();
    cout << queue.get_head() << endl;
    queue.out_queue();
    queue.out_queue();
    cout << queue.get_head() << endl;
    queue.out_queue();
    queue.out_queue();
    queue.in_queue(70);
    queue.print_queue();
}

