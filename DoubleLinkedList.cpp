#include <iostream>

using namespace std;

struct DNode{
	int data;		// 数据域 
	DNode* prior;	// 前驱指针 
	DNode* next;	// 后继指针 
};

// 顺序遍历输出
void traverseLinkedList(DNode *head){
	DNode *temp = head;
	while(temp->next != NULL){
		cout << temp->next->data << endl;
		temp = temp->next; 
	}
}

// 头插法建立带头结点的双链表
DNode* headInsert(DNode *head){
	DNode *s;
	int x;
	head = new DNode(); // 创建头节点 
	head->next = NULL;
	head->prior = NULL;
	cin >> x;
	while(x != 9999){ // 输入9999结束插入 
		s = new DNode();
		s->data = x;
		s->next = head->next;
		s->prior = head;
		head->next = s;
		cin >> x;
	}
	return head; 
}

// 在给定结点 p 之后插入新结点 q
void insertDNodeAfter(DNode* p, DNode* q){
	q->next = p->next;
	q->next->prior = p;
	q->next = p;
	p->prior = q;
} 

// 删除给定结点 p 的后继结点
void deleteDNodeAfter(DNode* p){
	DNode* q = p->next;
	if(q){
		q->next->prior = p;
		p->next = q->next;
		delete q; 
	}
} 


int main(){
	DNode* head;
	head = headInsert(head);
	traverseLinkedList(head);
	return 0;
}

