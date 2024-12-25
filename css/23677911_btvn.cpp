
#include <iostream>
struct Node {
    int data;
    Node* pNext;
};
struct List {
    Node* pHead;
    Node* pTail;
};
void Init(List& l) {
    l.pHead = l.pTail = nullptr;
}

Node* GetNode(int x) {
    Node* new_node = new Node;
    new_node->data = x;
    new_node->pNext = nullptr;
    return new_node;
}
void AddLast(List& L, Node* new_ele) {
    new_ele->pNext = nullptr;
    if (L.pHead == nullptr) {
        L.pHead = L.pTail = new_ele;
    } else {
        L.pTail->pNext = new_ele;
        L.pTail = new_ele;
    }
}
void InsertLast(List& L, int x) {
    Node* new_ele = GetNode(x);
    if (new_ele != nullptr) {
        AddLast(L, new_ele);
    }
}
void ShowLast(const List& L) {
    if (L.pTail != nullptr) {
        std::cout << L.pTail->data << std::endl;
    } else {
        std::cout << "The list is empty." << std::endl;
    }
}
int main (){
int x = 5;
List sll;
Init(sll);
InsertLast(sll,x);
ShowLast(sll);
}