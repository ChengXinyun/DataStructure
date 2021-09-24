#include <iostream>

using namespace std;

struct LNode{
	int data;
	LNode *next;
};

// 遍历链表
void traverseLinkedList(LNode *head){
	LNode *temp = head;
	while(temp->next != head){			// 循环终止条件
		cout << temp->next->data << endl;
		temp = temp->next; 
	}
}

// 头插法构造循环单链表
LNode* headInsert(LNode *head){
	LNode *s;
	int x;
	head = new LNode(); // 头结点
	head->next = head;
	cin >> x;
	while(x != 9999){ // 输入 9999 停止；
		s = new LNode();
		s->data = x;
		s->next = head->next;
		head->next = s;
		cin >> x;
	}
	return head; 
}

/*
 * 18. 有两个循环单链表，链表头指针分别为 h1 和 h2，编写一个函数将链表 h2 链接到 h1 之后，要求链接后的链表仍保持循环链表形式。
 */
void mergeList(LNode* &h1, LNode* &h2){
	if(h1->next == h1){
		h1 = h2;
		return;
	}
	if(h2->next == h2)	return;
	LNode* p = h1;
	while(p->next != h1)	p = p->next;
	p->next = h2->next;
	LNode* q = h2;
	while(q->next != h2)	q = q->next;
	q->next = h1;
}

/*
 * 19. 设计一个带头结点的循环单链表，其结点值均为正整数。设计一个算法，反复找出单链表中结点值最小的结点并输出，
 *     然后将该结点从链表中删除，直到单链表为空，再删除链表的头结点。
 */
void findMinAndDel(LNode* &head){
	LNode* preMinNode;	// 指向当前最小值结点的前一个结点；
	LNode* pre;			// 当前检查结点的前一个结点；
	LNode* p;			// 当前循环检查的结点；
	LNode* q;
	int min;			// 当前最小值；
	while(head->next != head){
		preMinNode = head;	// 指向当前最小值结点的前一个结点；
		pre = head;			// 当前检查结点的前一个结点；
		p = head->next;		// 当前循环检查的结点；
		min = INT32_MAX;		// 当前最小值
		while(p != head){
			if(p->data < min){
				min = p->data;
				preMinNode = pre;
			} else {
				pre = p;
				p = p->next;
			}
		}
		cout << preMinNode->next->data << endl;
		q = preMinNode->next;
		preMinNode->next = preMinNode->next->next;
		delete q;
	}
	delete head;
}

int main(){
	LNode* head;
	head = headInsert(head);
	traverseLinkedList(head);
	findMinAndDel(head);
	traverseLinkedList(head);
	// LNode* head1;
	// head1 = headInsert(head1);
	// traverseLinkedList(head1);
	// mergeList(head, head1);
	// traverseLinkedList(head);
}
