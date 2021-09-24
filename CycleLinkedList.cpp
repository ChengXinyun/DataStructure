#include <iostream>

using namespace std;

struct LNode{
	int data;
	LNode *next;
};

// ��������
void traverseLinkedList(LNode *head){
	LNode *temp = head;
	while(temp->next != head){			// ѭ����ֹ����
		cout << temp->next->data << endl;
		temp = temp->next; 
	}
}

// ͷ�巨����ѭ��������
LNode* headInsert(LNode *head){
	LNode *s;
	int x;
	head = new LNode(); // ͷ���
	head->next = head;
	cin >> x;
	while(x != 9999){ // ���� 9999 ֹͣ��
		s = new LNode();
		s->data = x;
		s->next = head->next;
		head->next = s;
		cin >> x;
	}
	return head; 
}

/*
 * 18. ������ѭ������������ͷָ��ֱ�Ϊ h1 �� h2����дһ������������ h2 ���ӵ� h1 ֮��Ҫ�����Ӻ�������Ա���ѭ��������ʽ��
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
 * 19. ���һ����ͷ����ѭ������������ֵ��Ϊ�����������һ���㷨�������ҳ��������н��ֵ��С�Ľ�㲢�����
 *     Ȼ�󽫸ý���������ɾ����ֱ��������Ϊ�գ���ɾ�������ͷ��㡣
 */
void findMinAndDel(LNode* &head){
	LNode* preMinNode;	// ָ��ǰ��Сֵ����ǰһ����㣻
	LNode* pre;			// ��ǰ������ǰһ����㣻
	LNode* p;			// ��ǰѭ�����Ľ�㣻
	LNode* q;
	int min;			// ��ǰ��Сֵ��
	while(head->next != head){
		preMinNode = head;	// ָ��ǰ��Сֵ����ǰһ����㣻
		pre = head;			// ��ǰ������ǰһ����㣻
		p = head->next;		// ��ǰѭ�����Ľ�㣻
		min = INT32_MAX;		// ��ǰ��Сֵ
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
