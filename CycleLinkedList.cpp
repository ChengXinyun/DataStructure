#include <iostream>

using namespace std;

// ������ڵ����� 
struct LNode{
	int data;
	LNode *next;
};

// �������
void traverseLinkedList(LNode *head){
	LNode *temp = head;
	while(temp->next != head){			// ѭ���������пղ�����Ϊ�Ƿ�Ϊͷָ��; 
		cout << temp->next->data << endl;
		temp = temp->next; 
	}
}

// ͷ�巨������ͷ����ѭ��������
LNode* headInsert(LNode *head){
	LNode *s;
	int x;
	head = new LNode(); // ����ͷ�ڵ� 
	head->next = head;
	cin >> x;
	while(x != 9999){ // ����9999�������� 
		s = new LNode();
		s->data = x;
		s->next = head->next;
		head->next = s;
		cin >> x;
	}
	return head; 
}

// ѭ�����������ɾ�Ĳ�����͵����������ͬ��ֻ��һ�㣺���һ������ next ָ�� head; 

int main(){
	LNode* head;
	head = headInsert(head);
	traverseLinkedList(head);
}
