// ���Ա����ʽ��ʾ 
#include <iostream>

using namespace std;

// ������ڵ����� 
struct LNode{
	int data;
	LNode *next;
}; 

typedef LNode* LinkedList;

// �������
void traverseLinkedList(LNode *head){
	LNode *temp = head;
	while(temp->next != NULL){
		cout << temp->next->data << endl;
		temp = temp->next; 
	}
} 

// ͷ�巨������ͷ���ĵ�����
LNode* headInsert(LNode *head){
	LNode *s;
	int x;
	head = new LNode(); // ����ͷ�ڵ� 
	head->next = NULL;
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

// ͷ�巨��������ͷ���ĵ�����
LNode* headInsert_1(LNode *head){
	LNode *s;
	int x;
	cin >> x;
	while(x != 9999){ // ����9999�������� 
		s = new LNode();
		s->data = x;
		if(head != NULL){
			s->next = head;
		} else {
			s->next = NULL;
		}
		head = s;
		cin >> x;
	}
	return head; 
} 
// ��������ͷ���ĵ�����
void traverseLinkedList_1(LNode* head){
	if(head == NULL)	return;
	LNode* p = head;
	while(p){
		cout << p->data << endl;
		p = p->next;
	} 
} 

// β�巨������ͷ���ĵ�������Ҫ��β�����һ��βָ�룻
LNode* tailInsert(LNode *head){
	LNode *s;                      // ָ��ÿ����Ҫ����Ľ���ָ�� ;
	int x;                         // ÿ����Ҫ����Ľ������� ;
	head = new LNode();            // �½�ͷ��� ;
	LNode *tail = head;            // ����Ϊ��ʱ��βָ��ָ��ͷ��� ;
	head->next = NULL;             // ����Ϊ��ʱ��ͷָ��� next ��Ϊ NULL; 
	cin >> x;              
	while(x != 9999){              // ���� 9999 ��������; 
		s = new LNode();           // ÿ�β����㣬���½�һ�� LNode; 
		s->data = x;               // ��ֵ���½��������� data; 
		tail->next = s;            // ���½�������βָ�����һ�� ;
		s->next = NULL;            // �½���������һ����㣬������ next ��Ϊ��; 
		tail = s;                  // βָ��Ӧ��ָ�����һ��Ԫ��; 
		cin >> x;                  // ��������;
	} 
	return head;                   // ����ͷָ��;
} 

// ����ŷ��ؽ�㣬���0 -> ͷ���;
LNode* getLNodeByIndex(LNode* head, int i){
	if(i < 0)	return NULL;       // i < 0��Ч������NULL;
	if(i == 0)	return head;       // i == 0������ͷ���;
	int j = 1;                     // ��������;
	LNode *p = head->next;         // ��ͷ�����ĵ�һ�����;
	while(p && i != j){            // ����������ĳ��ȣ�p ����� NULL;  
		p = p->next;               // ��������ִ��ѭ����ָ�����ʱ��ע��Ҫ�ж�ָ���Ƿ�Ϊ�յ����;
		j++;                       // j++, ֱ���ҵ� j==i �������һ��; 
	}
	return p; 				       // ����ͷָ��; 
}

// ��ֵ���������еĽ��
LNode* getLNodeByValue(LNode* head, int x){
	LNode* p = head->next;         // ��ͷ������һ����ʼ; 
	while(p && p->data != x)       // �ж�ָ���Ƿ�Ϊ NULL �Լ�ֵ�Ƿ���� x ;
		p = p->next;               // ��������һ����� ;
	return p;                      // ����ҵ��ˣ�����ָ��ý���ָ�룻���û���ҵ������ص�ָ�� p ָ�����һ��Ԫ�ص� next Ϊ NULL; 
} 

// �� i λ�ò�����, ���������Χ�Ͳ嵽�����β��; 
void insertLNode(LNode* head, int i){
	if(i <= 0)	return;			   // i <= 0��Ч��ֱ�ӷ���; 
	LNode* p = head;		       // ��ͷ��㿪ʼ; 
	int j = 1;					   // ����; 
	while(p->next && j++ != i)	   // ����������ĳ��ȣ�p ��ָ�����һ�����;  
		p = p->next;			   // j++, ֱ���ҵ� j==i �������һ��; 
	LNode* s = new LNode();		   // �½�������;
	int x;						   // ����ڵ��ֵ; 
	cin >> x;						
	s->data = x; 				   // ����;
	s->next = p->next;			   // ���������һ���� p ���� next; 
	p->next = s;				   // �� p ���� next ָ�������;  
} 

// ��ĳһ������ǰ�����, ����ʹ�ú�巨��Ȼ�󽻻���������������ʱ�临�Ӷ� O(1); 
// Tip: ��û�и�ͷָ�������Ĳ���Ҳ����������������ɾ����ͷָ��ĵ������ĳ����㣻 
void insertLNodeFront(LNode* p, LNode* front){ // �� frontָ��Ľ����뵽 pָ��Ľ���ǰ��; 
	front->next = p->next;   	   // ��巨 
	p->next = front;
	int temp = p->data;			   // ���������� 
	p->data = front->data;
	front->data = temp;
} 

// ɾ�����, ʱ�临�Ӷ� O(n); 
void deleteLNode(LNode* head, int i){
	LNode* p = getLNodeByIndex(head, i - 1);    // ͨ���±�õ�ǰ�����; 
	LNode* q = p->next; 						// q ָ��ɾ����� ;
	p->next = q->next;							// ǰ�����ĺ��ָ�� q ����һ��; 
	delete q;									// �ͷ� q ָ��Ľ��; 
} 

// ɾ��ĳ�������Ľ�� q ��ʱ�临�Ӷ� O(1); 
void deleteTheLNode(LNode* q){
	LNode* p = q->next;							// ָ��ɾ��������һ�����;
	if(p != NULL) {								// ��� p ��Ϊ�գ����� p �� q; 
		q->data = p->data;						
		q->next = p->next;
		delete p;
	} else {									// ��� p Ϊ�գ�ֱ���ͷ� q; 
		delete q;
	}								
} 

// �����������ͷ���ĳ���
int lengthOfLinkedList(LNode* head){
	LNode* p = head->next;						// p ָ�򲻰���ͷ���ĵ�һ�����; 
	int length = 0;								// Ϊ����ĳ��ȼ���; 
	while(p){									// ����������п�; 
		length++;								// ��Ϊ�գ��� +1; 
		p = p->next;							// �������ִ��;
	}
	return length;								// ��������ĳ���; 
} 

/*
 * 1. ���һ���ݹ��㷨��ɾ������ͷ���ĵ����� L ������ֵΪ x �Ľ��; 
 */
void deleteX(LNode* &head, int x){	//	����Ҫ�����ã����� 
	if(head == NULL)	return;		//	�ݹ�ĳ��� 
	if(head->data == x){			//	�ҵ����� x �Ľ�� 
		LNode* q = head;			//
		head = head->next;			// 	����� head ��ʵ����һ��ݹ�� head->next����Ϊ�����ã��������������; 
		delete q;					//	�ͷŷ��������Ľ�� 
		deleteX(head, x);			//	�������㿪ʼ�ݹ� 
	} else {	
		deleteX(head->next, x);		
	}
}

int main(){
	LNode *head = NULL;
	head = headInsert_1(head);
	traverseLinkedList_1(head);
	deleteX(head, 3);
	traverseLinkedList_1(head);
	// head = tailInsert(head);
	// cout << getLNodeByIndex(head, 3)->data << endl;
	// cout << getLNodeByValue(head, 3)->data << endl;
	// insertLNode(head, 2);
	// deleteTheLNode(getLNodeByIndex(head, 3));
	// traverseLinkedList(head);
	// cout << lengthOfLinkedList(head) << endl;	
}

