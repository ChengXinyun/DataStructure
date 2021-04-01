#include <iostream>

using namespace std;

struct DNode{
	int data;		// ������ 
	DNode* prior;	// ǰ��ָ�� 
	DNode* next;	// ���ָ�� 
};

// ˳��������
void traverseLinkedList(DNode *head){
	DNode *temp = head;
	while(temp->next != NULL){
		cout << temp->next->data << endl;
		temp = temp->next; 
	}
}

// ͷ�巨������ͷ����˫����
DNode* headInsert(DNode *head){
	DNode *s;
	int x;
	head = new DNode(); // ����ͷ�ڵ� 
	head->next = NULL;
	head->prior = NULL;
	cin >> x;
	while(x != 9999){ // ����9999�������� 
		s = new DNode();
		s->data = x;
		s->next = head->next;
		s->prior = head;
		head->next = s;
		cin >> x;
	}
	return head; 
}

// �ڸ������ p ֮������½�� q
void insertDNodeAfter(DNode* p, DNode* q){
	q->next = p->next;
	q->next->prior = p;
	q->next = p;
	p->prior = q;
} 

// ɾ��������� p �ĺ�̽��
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

