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
	while(temp->next != head){
		cout << temp->next->data << endl;
		temp = temp->next; 
	}
}

// �п�
bool isEmpty(DNode* head){
	if(head->next == head || head->prior == head){
		return true;
	}
	return false;
} 

// ͷ�巨������ͷ����˫����
DNode* headInsert(DNode *head){
	DNode *s;
	int x;
	head = new DNode(); // ����ͷ�ڵ� 
	head->next = head;
	head->prior = head;
	cin >> x;
	while(x != 9999){ // ����9999�������� 
		s = new DNode();
		s->data = x;
		s->next = head->next;
		s->prior = head;
		head->next = s;
		if(head->prior == head){   // �����һ��Ԫ�ص�ʱ����Ҫ�� head ��ǰ��ָ��ָ���²���Ľ�㣬֮����ͷ����ʱ����ı�ͷ���� prior; 
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

