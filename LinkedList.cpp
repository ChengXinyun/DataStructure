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

/*
 * 2. �ڴ�ͷ���ĵ����� L �У�ɾ������ֵΪ x �Ľ�㣬���ͷ���ռ䣬����ֵΪ x �Ľ�㲻Ψһ���Ա�д�㷨��ʵ������������ 
 *    ��һ������ʹ����֮���Ԫ�ؽ��н������뷨�����Ƕ������һ�����޷��������޷���֮��������н�����
 *	  ��˿��Բ�������ָ�룬һ��ָ��ǰ���ָ�룬һ��ָ��ǰָ�롣 
 */
void deleteX_1(LNode* head, int x){
	LNode* front = head;			// ǰ��ָ�� 
	LNode* p = head->next;			// ��ǰ����ָ�� 
	while(p){
		if(p->data == x){			// ��鵱ǰ���ֵ�Ƿ�Ϊ x 
			LNode* q = p;			// ʹ q ָ��ǰ��㣬����֮���ɾ������ 
			p = p->next;			// p ָ����һ����� 
			front->next = p;		// ǰ��ָ����� 
			delete q;				// ɾ����ǰ���� x �Ľڵ� 
		} else {
			front = p;				// ��������� x������ָ�붼����ƶ�һ��λ�� 
			p = p->next;
		}
	}
}

/*
 * 3. �� L Ϊ��ͷ���ĵ�������д�㷨ʵ�ִ�β��ͷ�������ÿ���ڵ��ֵ�� 
 *    ʹ�õݹ�ķ���ʵ�֣���ʵ�൱�ڰ��������ηŽ�ջ�У�Ȼ���ٴ�ջ�е������� 
 */ 
void reverseOutput(LNode* &head){
	if(head->next == NULL)	return;			// �ݹ���� 
	reverseOutput(head->next);				// �ݹ���һ�� 
	cout << head->next->data << endl;		// ��� 
} 

/*
 * 4. ʹ��д�ڴ�ͷ���ĵ����� L ��ɾ��һ����Сֵ���ĸ�Ч�㷨(������Сֵ���ʹ��Ψһ��)�� 
 */
void deleteMin(LNode* &head){
	LNode* pre = head;						// pre ָ����СԪ�ص�ǰһ�� 
	LNode* p = head->next;					// Ĭ��һ��ʼͷ������һ����С 
	while(p->next != NULL){
		if(p->next->data < pre->next->data){// �Ƚ� 
			pre = p;
		}
		p = p->next; 
	}
	LNode* d = pre->next;					// ɾ������ҵ��� pre ����һ��Ԫ�� 
	pre->next = d->next;
	delete d;
} 
// ��д�� �� ��ͷ���ĵ����� L ��ɾ��һ����Сֵ���ĸ�Ч�㷨(������Сֵ���ʹ��Ψһ��)��
// û����������������������еڶ�����㣬ʹ�ڶ������Ϊ��ʼ��Сֵ��㡣 
void deleteMin_1(LNode* &head){
	LNode* pre = head;
	LNode* p = head->next;
	if(p){
		if(pre->data < p->data){
			int temp = pre->data;
			pre->data = p->data;
			p->data = temp;
		}
	} else {
		delete p;
		return;
	}
	while(p->next != NULL){
		if(p->next->data < pre->next->data){// �Ƚ� 
			pre = p;
		}
		p = p->next; 
	}
	LNode* d = pre->next;					// ɾ������ҵ��� pre ����һ��Ԫ�� 
	pre->next = d->next;
	delete d;	
} 

/*
 * 5. �Ա�д�㷨����ͷ���ĵ�����͵����� -> �����ռ临�Ӷ�Ϊ O(1) 
 */
void reverseLinkedList(LNode* &head){
	LNode* p = head->next;
	LNode* r = p->next;
	p->next = NULL;
	while(r != NULL){
		LNode* pre = p;
		p = r;
		r = r->next;
		p->next = pre;
	}
	head->next = p;
}

/*
 * 6. ��һ����ͷ���ĵ����� L �����һ���㷨ʹ��Ԫ�ص������� 
 * ��������ʱ�临�Ӷ� O(n^2).
 * �����Ը��Ƶ������У������֮���ٸ��Ƶ������С� 
 */
void sort(LNode* &head){
	LNode* p = head->next, *pre;
	if(p == NULL)	return;
	LNode* r = p->next;
	p->next = NULL;
	p = r;
	while(p){
		r = p->next;
		pre = head;
		while(pre->next && pre->next->data < p->data){
			pre = pre->next;
		}
		p->next = pre->next;
		pre->next = p;
		p = r;
	}
} 

/*
 * 7. ����һ����ͷ���ĵ�����������Ԫ�ؽ�������ֵ�����Ա�дһ������
 *    ɾ���������н��ڸ���������ֵ����Ϊ��������������֮���Ԫ�ء� 
 */
void deleteXY(LNode* &head, int x, int y){
	LNode* p = head->next;
	LNode* pre = head;
	while(p){
		if(p->data > x && p->data < y){
			pre->next = p->next;
			delete p;
			p = pre->next;
		} else {
			pre = p;
			p = p->next;
		}
	}
} 

/*
 * 8. ����������������д�㷨�ҳ���������Ĺ�����㡣 
 */
LNode* findCommonNode(LNode* &head1, LNode* &head2){
	int l1 = 0;
	int l2 = 0;
	LNode* p1 = head1->next;
	LNode* p2 = head2->next; 
	while(p1){
		l1++;
		p1 = p1->next; 
	}
	while(p2){
		l2++;
		p2 = p2->next;
	}
	p1 = head1->next;
	p2 = head2->next; 
	if(l1 > l2){
		int k = l1 - l2;
		while(k--){
			p1 = p1->next;		
		}
	} else {
		int k = l2 - l1;
		while(k--){
			p2 = p2->next;		
		}
	}
	while(p1 != NULL){
		if(p1 == p2){
			return p1;
		} else {
			p1 = p1->next;
			p2 = p2->next;
		}
	}
	return NULL;
} 

/*
 * 9. ����һ����ͷ���ĵ�������������������������е�����Ԫ�أ������ͷŽ����ռ�Ĵ洢�ռ䡣 
 */
void sortAndDelete(LNode* &head){
	LNode* pre;					// ָ����Ҫɾ������ǰ����� 
	LNode* p;					// ���� 
	LNode* d;					// ָ��ɾ���Ľ�� 
	while(head->next){			// ÿ�α���ֱ������Ϊ��Ϊֹ
		pre = head;				 
		p = head->next;		
		while(p->next){				
			if(p->next->data < pre->next->data){
				pre = p;		
			} 
			p = p->next;	 
		}
		cout << pre->next->data << endl;
		d = pre->next;
		pre->next = d->next;
		delete d;
	}
	delete head;
} 

/*
 * 10. ��һ����ͷ���ĵ����� A �ֽ�Ϊ������ͷ���ĵ����� A �� B��
 *     ʹ�� A ���к���ԭ�������Ϊ������Ԫ�أ��� B ���к���ԭ�������Ϊż����Ԫ�أ�
 *     �ұ��������˳�򲻱� 
 */
LNode* createTwoList(LNode* &A){
	LNode* B = new LNode;
	B->next = NULL;
	LNode* ra = A;
	LNode* rb = B;
	LNode* p = A->next;
	A->next = NULL;
	while(p){
		rb->next = p->next;
		rb = p->next;
		ra->next = p;
		ra = p;
		if(p->next){
			p = p->next->next;
		} else {
			break;
		}
	}
	if(ra)
		ra->next = NULL;
	if(rb)
		rb->next = NULL;
	return B;
} 

/*
 * 11. �� C = {a1,b1,a2,b2,...,an,bn}Ϊ���Ա����ô�ͷ���ĵ������ţ�������Ϊ�������Ա� A = {a1,a2,a3,...,an} �� B = {bn,bn-1,bn-2,...,b1};
 * ����һ�ⲻͬ���ǲ��õ���ͷ�巨������˳�����ã�
 */
LNode* discreat(LNode* &A){
	LNode* B = new LNode();
	B->next = NULL;
	LNode* p = A->next, *q;
	LNode* ra = A;
	while(p){
		ra->next = p;
		ra = p;
		if(p){
			q = p->next;
		}
		p->next = B->next;
		B->next = p;
		p = q;
	}
	ra->next = NULL;
	return B;
}

/*
 * 12. ��һ��������������Ա��У�����ֵ��ͬ��Ԫ�ش��ڣ����洢��ʽΪ����������㷨ȥ����ͬ��Ԫ�أ�ʹ���в������ظ���Ԫ�أ�
 */
void del_same(LNode* &head){
	if(head->next == nullptr || head->next->next == nullptr)	return;	// ��������ڵ����ֻ��һ���ڵ㣬ֱ�ӷ��أ�
	LNode* p = head->next;												// p ����ָ�룬����ɨ�裻
	LNode* q;															// q ��Ϊ p �ĺ�̣������ж�ֵ�Ƿ���ȣ���ȵĻ���ɾ����
	while(p->next){
		q = p->next;
		if(p->data == q->data){
			p->next = q->next;
			delete q;
		} else {
			p = p->next;	
		}
	}
}

/*
 * 13. ������������Ԫ��ֵ�����������е����Ա����Ե��������ʽ�洢�����д�㷨����ϲ�Ϊһ����Ԫ��ֵ�ݼ��������еĵ�������Ҫ������ԭ����������Ľڵ��Ź鲢��ĵ�����
 */
void mergeList(LNode* &A, LNode* &B){	
	LNode* LA = A->next;
	LNode* LB = B->next;
	LNode* head = A;	// �������ͷ
	head->next = NULL;
	LNode* r;
	while(LA && LB){
		if(LA->data < LB->data){
			r = LA->next;
			LA->next = head->next;
			head->next = LA;
			LA = r;
		} else {
			r = LB->next;
			LB->next = head->next;
			head->next = LB;
			LB = r;
		}
	}
	if(LA == nullptr)	LA = LB;
	while(LA){
		r = LA->next;
		LA->next = head->next;
		head->next = LA;
		LA = r;
	}	
	delete B;
}

/*
 * 14. �� A �� B ��������ͷ���ĵ���������Ԫ�ص����������һ���㷨�� A �� B �еĹ���Ԫ�ز��������� C��Ҫ���ƻ� A �� B �Ľڵ㣻
 */ 
void commonNode(LNode* &A, LNode* &B, LNode* &C){
	LNode* LA = A->next;
	LNode* LB = B->next;
	C->next = nullptr;
	LNode* tail = C;
	if(LA == nullptr || LB == nullptr)	return;
	while(LA != nullptr && LB != nullptr){
		if(LA->data == LB->data){
			LNode* p = new LNode();
			p->data = LA->data;
			tail->next = p;
			tail = p;
			LA = LA->next;
			LB = LB->next;
		} else if(LA->data > LB->data){
			LB = LB->next;
		} else {
			LA = LA->next;
		}
	}
	tail->next = nullptr;
}

/*
 * 15. ��֪�������� A �� B �ֱ��ʾ�������ϣ���Ԫ�ص������У����ƺ������� A �� B �Ľ������������ A �����У�
 */
void commonSet(LNode* &A, LNode* &B){
	LNode* pre = A;
	LNode* LA = A->next;
	LNode* LB = B->next;
	if(LA == nullptr || LB == nullptr){
		A->next = nullptr;
		return;
	}
	while(LA && LB){
		if(LA->data == LB->data){
			pre = LA;
			LA = LA->next;
			LB = LB->next;
		} else if(LA->data > LB->data){
			LB = LB->next;
		} else {
			LA = LA->next;
			pre->next = LA;
		}
	}
	pre->next = nullptr;
}

/*
 * 16. ������������ A = a1, a2,...,an;�� B = b1, b2,...,bm; �Ѿ����������������У����һ���㷨���ж����� B �Ƿ�Ϊ���� A �������У�
 */
bool isSubList(LNode* &B, LNode* &A){
	LNode* LA = A->next;
	LNode* p = LA;
	LNode* LB = B->next;
	if(LA == nullptr || LB == nullptr)	return 0;
	while(p && LB){
		if(p->data == LB->data){
			p = p->next;
			LB = LB->next;
		} else {
			LA = LA->next;
			p = LA;
			LB = B->next;
		}
	}
	if(LB == nullptr){
		return 1;
	} else {
		return 0;
	}
}
/*
 * 21. (2009) ����ͷ���ĵ��������������е����� k ��λ���ϵĽ�㣨k Ϊ���������������ҳɹ�������ý��date���ֵ��������1������ֻ����0��
 */
int lastKthNode(LNode* head, int k){
	if(head->next == nullptr || k > lengthOfLinkedList(head))	return 0;
	LNode* p = head;
	LNode* q = head;
	while(--k){
		q = q->next;
	}
	while(q->next != nullptr){
		p = p->next;
		q = q->next;
	}
	cout << p->data << endl;
	return 1;
}

int main(){
	LNode *head = NULL;
	head = headInsert(head);
	traverseLinkedList(head);
	cout << "------------"<<endl;
	cout << lastKthNode(head, 3) << endl;
	cout << lastKthNode(head, 10) << endl;
	// LNode *head1 = NULL;
	// head1 = headInsert(head1);
	// traverseLinkedList(head1);
	// cout << "------------"<<endl;
	// cout << isSubList(head, head1);
	// LNode* C = new LNode();
	// C->next = NULL;
	// traverseLinkedList(C);
	// commonNode(head, head1, C);
	// traverseLinkedList(C);
	// mergeList(head, head1);
	// del_same(head);
	// deleteX_1(head, 3);
	// reverseOutput(head);
	// deleteMin_1(head);
	// reverseLinkedList(head);
	// deleteXY(head, 2, 4);
	// sortAndDelete(head);
	// LNode* B = createTwoList(head);
	// traverseLinkedList(head);
	// cout << "------------"<<endl;
	// traverseLinkedList(B);
	// head = tailInsert(head);
	// cout << getLNodeByIndex(head, 3)->data << endl;
	// cout << getLNodeByValue(head, 3)->data << endl;
	// insertLNode(head, 2);
	// deleteTheLNode(getLNodeByIndex(head, 3));
	// traverseLinkedList(head);
	// cout << lengthOfLinkedList(head) << endl;	
}

