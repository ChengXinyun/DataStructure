#include <iostream>

using namespace std;

struct DNode{
	int data;		// 数据 
	DNode* prior;	// 前驱 
	DNode* next;	// 后继 
};

// 遍历链表
void traverseLinkedList(DNode *head){
	DNode *temp = head;
	while(temp->next != head){
		cout << temp->next->data << endl;
		temp = temp->next; 
	}
}

// 判空
bool isEmpty(DNode* head){
	if(head->next == head || head->prior == head){
		return true;
	}
	return false;
} 

// 头插法构造循环双链表
DNode* headInsert(DNode *head){
	DNode *s;
	int x;
	head = new DNode();
	head->next = head;
	head->prior = head;
	cin >> x;
	while(x != 9999){ 
		s = new DNode();
		s->data = x;
		s->next = head->next;
		s->prior = head;
		head->next->prior = s;
		head->next = s;
		if(head->prior == head){
			head->prior = s;
		}
		cin >> x;
	}
	return head; 
}

/*
 * 17. 设计一个算法判断带头结点的循环双链表是否对称；
 */
bool isParellar(DNode* &head){
	DNode* p = head->next;
	DNode* q = head->prior;
	while(p != q && q->next != p){ 
		if(p->data != q->data){
			return false;
		} else {
			p = p->next;
			q = q->prior;
		}
	}
	return true;
}

int main(){
	DNode* head;
	head = headInsert(head);
	cout << isEmpty(head) << endl;
	traverseLinkedList(head);
	cout << isParellar(head);
	return 0;
}

