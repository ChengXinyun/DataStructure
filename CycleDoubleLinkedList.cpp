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

// 头插法建立带头结点的双链表
DNode* headInsert(DNode *head){
	DNode *s;
	int x;
	head = new DNode(); // 创建头节点 
	head->next = head;
	head->prior = head;
	cin >> x;
	while(x != 9999){ // 输入9999结束插入 
		s = new DNode();
		s->data = x;
		s->next = head->next;
		s->prior = head;
		head->next = s;
		if(head->prior == head){   // 插入第一个元素的时候，需要将 head 的前驱指针指向新插入的结点，之后在头插入时无须改变头结点的 prior; 
			head->prior = s;
		}
		cin >> x;
	}
	return head; 
}

int main(){
	DNode* head;
	head = headInsert(head);
	cout << isEmpty(head) << endl;
	traverseLinkedList(head);
	return 0;
}

