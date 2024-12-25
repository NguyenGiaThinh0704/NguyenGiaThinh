#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	Node *link;
};

struct List{
	Node *first,*last;
};

void Init(List &l){
	l.first = l.last = NULL;
}

Node *GetNode(int x){
	Node *p;
	p = new Node;
	if (p == NULL){
		return NULL;
	}
	p->data = x;
	p->link =  NULL;
	return p;
}

void InsestFirst (List &l,int data){
	Node *p = GetNode(data);
	if (l.first == NULL){
		l.first=l.last = p;
	}
	else{
		p->link = l.first;
		l.first = p;
	}
}

void CreateListFirst(List &l){
	int data;
	do{
	printf("Nhap vao cac so nguyen, Nhap -1 de ket thuc: ");
	scanf("%d",&data);
	if (data == -1){
		break;
	}
	InsestFirst(l,data);
	}while(data != -1);
	printf("Da nhap xong du lieu\n");
}

void PrintList(List &l){
	Node *p = l.first;
	while(p != NULL){
		printf("%d ",p->data);
		p= p->link;
	}
}

long SumEvenNumber(List L) {
    long sum = 0;
    Node* p = L.first;
    if(L.first == NULL){
    	return 0;
	}
    while (p != NULL) {
        if (p->data % 2 == 0) {
            sum += p->data;
        }
        p = p->link;
    }
    return sum;
}
Node* FindElement(List L, int x) {
    Node* p = L.first;
    while (p != NULL) {
        if (p->data == x) {
            return p;
        }
        p = p->link;
    }
    return NULL;
}


int main(){
	int x;
	List l;
	Init(l);
	CreateListFirst(l);
	PrintList(l);
	long sum = SumEvenNumber(l);
	printf("\n");
	printf("Tong cua cac gia tri chan: %d\n",sum);
	printf("Nhap vao gia tri x can tim: ");
	scanf("%d",&x);
	printf("Con tro Node: %d ",FindElement(l,x));
