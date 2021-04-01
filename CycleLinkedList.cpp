#include <iostream>

using namespace std;

// 单链表节点类型 
struct LNode{
	int data;
	LNode *next;
};

// 遍历输出
void traverseLinkedList(LNode *head){
	LNode *temp = head;
	while(temp->next != head){			// 循环链表中判空操作改为是否为头指针; 
		cout << temp->next->data << endl;
		temp = temp->next; 
	}
}

// 头插法建立带头结点的循环单链表
LNode* headInsert(LNode *head){
	LNode *s;
	int x;
	head = new LNode(); // 创建头节点 
	head->next = head;
	cin >> x;
	while(x != 9999){ // 输入9999结束插入 
		s = new LNode();
		s->data = x;
		s->next = head->next;
		head->next = s;
		cin >> x;
	}
	return head; 
}

// 循环单链表的增删改查操作和单链表基本相同，只有一点：最后一个结点的 next 指向 head; 

int main(){
	LNode* head;
	head = headInsert(head);
	traverseLinkedList(head);
}
