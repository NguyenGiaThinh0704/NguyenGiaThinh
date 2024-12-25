#include<iostream>

struct Node{
	float heSo;
	int soMu;
	Node *link;
};

struct List{
	Node* pHead;
	Node* pTail;
};

void Init(List &l){
	l.pHead=l.pTail=NULL;
}

Node *GetNode(float heSo,int soMu){
	Node *p = new Node;
	if(p == NULL) return 0;
	p->heSo = heSo;
	p->soMu = soMu;
	p->link = NULL;
	return p;
}

void InsertLast(List &l,float heSo,int soMu){
	Node *p = GetNode(heSo,soMu);
	if(p == NULL) return;
	if(l.pHead == NULL){
		l.pHead=l.pTail=p;
	}
	else{
		l.pTail->link = p;
		l.pTail = p;	
	}
}

void NhapDaThuc(List &l){
	float heSo;
	int soMu;
	printf("Bat dau nhap da thuc(Nhap he so  bang 0 de ket thuc):\n");
	do{
		printf("Nhap vao he so: ");
		scanf("%f",&heSo);
		if(heSo == 0) break;
		printf("Nhap vao so mu: ");
		scanf("%d",&soMu);
		InsertLast(l,heSo,soMu);
	}while(heSo!=0);
	printf("Da nhap da thuc xong\n");
}

void XuatDanhSach(List &l){
	Node *p=l.pHead;
	while(p!=NULL){
		if(p->heSo<0){
			printf("%.0f*x^%d",p->heSo,p->soMu);
		}
		else if (p->heSo>0){
			printf("+%.0f*x^%d",p->heSo,p->soMu);
		}
		p=p->link;
	}
}

int main(){
	List l;
	Init(l);
	NhapDaThuc(l);
	XuatDanhSach(l);
}
