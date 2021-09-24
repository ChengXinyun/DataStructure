#include <iostream>

using namespace std;

struct DNode{
	int data;		// 数据
	DNode* prior;	// 前驱 
	DNode* next;	// 后继 
	int freq;		// 访问频度
};

// 遍历链表
void traverseLinkedList(DNode *head){
	DNode *temp = head;
	while(temp->next != NULL){
		cout << temp->next->data << endl;
		temp = temp->next; 
	}
}

// 头插法
DNode* headInsert(DNode *head){
	DNode *s;
	int x;
	head = new DNode(); // 头结点 
	head->next = NULL;
	head->prior = NULL;
	cin >> x;
	while(x != 9999){ //  
		s = new DNode();
		s->freq = 0;
		s->data = x;
		s->next = head->next;
		s->prior = head;
		if(head->next != nullptr)	head->next->prior = s;
		head->next = s;
		cin >> x;
	}
	return head; 
}

// 双向链表的插入
void insertDNodeAfter(DNode* p, DNode* q){
	q->next = p->next;
	q->next->prior = p;
	q->next = p;
	p->prior = q;
} 

// 双向链表的删除
void deleteDNodeAfter(DNode* p){
	DNode* q = p->next;
	if(q){
		q->next->prior = p;
		p->next = q->next;
		delete q; 
	}
} 

/*
 * 20. 设头指针为 L 的带头结点的非循环双向链表，Locate(L, x)增加访问频度freq,按照freq非增的顺序排列，调整链表；
 */
DNode* Locate(DNode* &L, int x){
	DNode* p = L->next;
	while(p != nullptr){
		if(p->data == x)	break;
		p = p->next;
	}
	if(p == nullptr){
		cout << "不存在值为 "<< x <<" 的结点" << endl;
		return L;
	}
	p->freq++;
	if(p->next != nullptr)	p->next->prior = p->prior;
	p->prior->next = p->next;
	DNode* q = p->prior;
	while(q != L){
		if(q->freq > p->freq)	break;
		q = q->prior;	
	}
	q->next->prior = p;
	p->next = q->next;
	q->next = p;
	p->prior = q;
	return p;
}

int main(){
	DNode* head;
	head = headInsert(head);
	traverseLinkedList(head);
	DNode* p = Locate(head, 3);
	DNode* p1 = Locate(head, 3);
	DNode* p2 = Locate(head, 4);
	traverseLinkedList(head);
	return 0;
}

