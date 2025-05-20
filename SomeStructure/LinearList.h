#pragma once

using namespace std;

const int MaxSize = 100;
template <class T>
class LinearList
{
public:
    LinearList() { length = 0; }            //无参数构造方法
    LinearList(T a[], int n);    //有参数构造方法
    ~LinearList() {}                    //析构函数
    int Length() { return length; }    //线性表长度
    T Get(int i);            //按位查找
    int Locate(T x);         //按值查找
    void Insert(int i, T x);  //插入
    T Delete(int i);         //删除
    void PrintList();               //遍历
private:
    T data[MaxSize];         //顺序表使用数组实现
    int length;                     //存储顺序表的长度
};

template <class T>
T LinearList<T>::Get(int i)
{
    if (i<1 && i>length) throw "wrong Location";
    else return data[i - 1];
}

template <class T>
int LinearList<T>::Locate(T x)
{
    for (int i = 0; i < length; i++)
        if (data[i] == x) return i + 1;
    return 0;
}

template <class T>
void LinearList<T>::Insert(int i, T x)
{
    if (length >= MaxSize) throw "Overflow";
    if (i<1 || i>length + 1) throw "Location";
    for (int j = length; j >= i; j--)
        data[j] = data[j - 1];
    data[i - 1] = x;
    length++;
}

template <class T>
T LinearList<T>::Delete(int i)
{
    int x;
    if (length == 0) throw "Underflow";
    if (i<1 || i>length) throw "Location";
    x = data[i - 1];
    for (int j = i; j < length; j++)
        data[j - 1] = data[j];
    length--;
    return x;
}

template <class T>
void LinearList<T>::PrintList()
{
    for (int i = 0; i < length; i++)
        cout << data[i] << endl;
}


template<class T>
struct Node
{
    T data;
    Node<T>* next;
};

template<class T>
class LinkList
{
public:
    LinkList();
    LinkList(T a[], int n);
    ~LinkList();
    int Length();
    T Get(int i);
    int Locate(T x);
    void Insert(int i, T x);
    T Delete(int i);
    void PrintList();
    void changeNode(int i);
private:
    Node<T>* first;
};
    //    1   2   3   4 
template<class T>
void LinkList<T>::changeNode(int i) {
    if (i == 0) {
        first = &Get(i);
        Get(i + 1).next = &Get(i);
        Get(i).next2 = &Get(i + 2);
    }
    else if (i == Length() - 2) {
        Get(i - 1).next = &Get(i + 1);
        Get(i + 1).next = &Get(i);
    }
    else {
        Get(i).next = &Get(i + 2);
        Get(i + 1).next = &Get(i);
        Get(i - 1).next = &Get(i + 1);
    }
}




template<class T>
LinkList<T>::LinkList()
{
    first = new Node<T>;
    first->next = NULL;
}

template<class T>
LinkList<T>::LinkList(T a[], int n)
{
    first = new Node<T>;
    first->next = NULL;
    for (int i = 0; i < n; i++)
    {
        Node<T>* s = new Node<T>;
        s->data = a[i];
        s->next = first->next;
        first->next = s;
    }
}

template<class T>
LinkList<T>::~LinkList()
{
    while (first != NULL)
    {
        Node<T>* q = first;
        first = first->next;
        delete q;
    }
}

template<class T>
int LinkList<T>::Length()
{
    Node<T>* p = first->next;
    int count = 0;
    while (p != NULL)
    {
        p = p->next;
        count++;
    }
    return count;
}

template<class T>
T LinkList<T>::Get(int i)
{
    Node<T>* p = first->next;
    int count = 1;
    while (p != NULL && count < i)
    {
        p = p->next;
        count++;
    }
    if (p == NULL) throw "Location";
    else return p->data;
}

template<class T>
int LinkList<T>::Locate(T x)
{
    Node<T>* p = first->next;
    int count = 1;
    while (p != NULL)
    {
        if (p->data == x) return count;
        p = p->next;
        count++;
    }
    return 0;
}

template<class T>
void LinkList<T>::Insert(int i, T x)
{
    Node<T>* p = first;
    int count = 0;
    while (p != NULL && count < i - 1)
    {
        p = p->next;
        count++;
    }
    if (p == NULL) throw "Location";
    else {
        Node<T>* s = new Node<T>;
        s->data = x;
        s->next = p->next;
        p->next = s;
    }
}

template<class T>
T LinkList<T>::Delete(int i)
{
    Node<T>* p = first;
    int count = 0;
    while (p != NULL && count < i - 1)
    {
        p = p->next;
        count++;
    }
    if (p == NULL || p->next == NULL) throw "Location";
    else {
        Node<T>* q = p->next;
        int x = q->data;
        p->next = q->next;
        return x;
    }
}

template<class T>
void LinkList<T>::PrintList()
{
    Node<T>* p = first->next;
    while (p != NULL)
    {
        cout << p->data << endl;
        p = p->next;
    }
}

// 链表的定义
//typedef struct ListNode {
//	int val;
//	struct ListNode* next;
//	ListNode(int x) :
//		val(x), next(NULL) {
//	}
//};
struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

ListNode* insertNode(ListNode* head, int data);

//  插入节点
ListNode* insertNode(ListNode* head, int data) {
    ListNode* newNode = new ListNode(data);
    ListNode* p = head;
    if (p == nullptr) {
        head = newNode;
    }
    else {
        while (p->next != nullptr) {
            p = p->next;
        }
        p->next = newNode;
    }
    return head;
}



/* 删除节点*/
ListNode* deleteNode(ListNode* head, int data) {
    ListNode* p = head;
    //首先判断是不是空链表
    if (p == nullptr) {
        return head;
    }
    else {
        //判断是不是删除头节点
        if (p->val == data) {
            head = p->next;
            delete p;
            return head;
        }
        else {
            //如果有该结点，遍历到待删除节点的前一节点
            while (p->next != nullptr && p->next->val != data) {
                p = p->next;
            }
            //遍历完整个链表都没有待删除节点
            if (p->next == nullptr) {
                return head;
            }
            else {
                ListNode* deleteNode = p->next;
                p->next = deleteNode->next;
                delete deleteNode;
                return head;
            }
        }
    }
}


//反转链表
ListNode* reverse(ListNode* head) {
    ListNode* pPrev = nullptr;
    ListNode* p = head;
    ListNode* pReverseHead = nullptr;
    while (p != nullptr) {
        ListNode* pNext = p->next;
        if (pNext == nullptr) {
            pReverseHead = p;
        }
        p->next = pPrev;
        pPrev = p;
        p = pNext;
    }
    return pReverseHead;
}

