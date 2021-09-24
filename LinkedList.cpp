// 线性表的链式表示 
#include <iostream>

using namespace std;

// 单链表节点类型 
struct LNode{
	int data;
	LNode *next;
}; 

typedef LNode* LinkedList;

// 遍历输出
void traverseLinkedList(LNode *head){
	LNode *temp = head;
	while(temp->next != NULL){
		cout << temp->next->data << endl;
		temp = temp->next; 
	}
} 

// 头插法建立带头结点的单链表
LNode* headInsert(LNode *head){
	LNode *s;
	int x;
	head = new LNode(); // 创建头节点 
	head->next = NULL;
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

// 头插法建立不带头结点的单链表
LNode* headInsert_1(LNode *head){
	LNode *s;
	int x;
	cin >> x;
	while(x != 9999){ // 输入9999结束插入 
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
// 遍历不带头结点的单链表
void traverseLinkedList_1(LNode* head){
	if(head == NULL)	return;
	LNode* p = head;
	while(p){
		cout << p->data << endl;
		p = p->next;
	} 
} 

// 尾插法建立带头结点的单链表，需要在尾部添加一个尾指针；
LNode* tailInsert(LNode *head){
	LNode *s;                      // 指向每次需要插入的结点的指针 ;
	int x;                         // 每次需要插入的结点的数据 ;
	head = new LNode();            // 新建头结点 ;
	LNode *tail = head;            // 链表为空时，尾指针指向头结点 ;
	head->next = NULL;             // 链表为空时，头指针的 next 置为 NULL; 
	cin >> x;              
	while(x != 9999){              // 输入 9999 结束插入; 
		s = new LNode();           // 每次插入结点，先新建一个 LNode; 
		s->data = x;               // 赋值给新建结点的数据 data; 
		tail->next = s;            // 将新建结点插入尾指针的下一个 ;
		s->next = NULL;            // 新建结点是最后一个结点，将他的 next 置为空; 
		tail = s;                  // 尾指针应该指向最后一个元素; 
		cin >> x;                  // 继续输入;
	} 
	return head;                   // 返回头指针;
} 

// 按序号返回结点，序号0 -> 头结点;
LNode* getLNodeByIndex(LNode* head, int i){
	if(i < 0)	return NULL;       // i < 0无效，返回NULL;
	if(i == 0)	return head;       // i == 0，返回头结点;
	int j = 1;                     // 用来计数;
	LNode *p = head->next;         // 除头结点外的第一个结点;
	while(p && i != j){            // 若超过链表的长度，p 会等于 NULL;  
		p = p->next;               // 在链表中执行循环对指针操作时，注意要判断指针是否为空的情况;
		j++;                       // j++, 直到找到 j==i 或者最后一个; 
	}
	return p; 				       // 返回头指针; 
}

// 按值查找链表中的结点
LNode* getLNodeByValue(LNode* head, int x){
	LNode* p = head->next;         // 从头结点的下一个开始; 
	while(p && p->data != x)       // 判断指针是否为 NULL 以及值是否等于 x ;
		p = p->next;               // 接着找下一个结点 ;
	return p;                      // 如果找到了，返回指向该结点的指针；如果没有找到，返回的指针 p 指向最后一个元素的 next 为 NULL; 
} 

// 在 i 位置插入结点, 如果超出范围就插到链表的尾部; 
void insertLNode(LNode* head, int i){
	if(i <= 0)	return;			   // i <= 0无效，直接返回; 
	LNode* p = head;		       // 从头结点开始; 
	int j = 1;					   // 计数; 
	while(p->next && j++ != i)	   // 若超过链表的长度，p 会指向最后一个结点;  
		p = p->next;			   // j++, 直到找到 j==i 或者最后一个; 
	LNode* s = new LNode();		   // 新建插入结点;
	int x;						   // 插入节点的值; 
	cin >> x;						
	s->data = x; 				   // 输入;
	s->next = p->next;			   // 插入结点的下一个是 p 结点的 next; 
	p->next = s;				   // 将 p 结点的 next 指向插入结点;  
} 

// 对某一结点进行前插操作, 可以使用后插法，然后交换两个结点的数据域，时间复杂度 O(1); 
// Tip: 对没有给头指针的链表的操作也可以类似做：例如删除无头指针的单链表的某个结点； 
void insertLNodeFront(LNode* p, LNode* front){ // 将 front指向的结点插入到 p指向的结点的前面; 
	front->next = p->next;   	   // 后插法 
	p->next = front;
	int temp = p->data;			   // 交换数据域 
	p->data = front->data;
	front->data = temp;
} 

// 删除结点, 时间复杂度 O(n); 
void deleteLNode(LNode* head, int i){
	LNode* p = getLNodeByIndex(head, i - 1);    // 通过下标得到前驱结点; 
	LNode* q = p->next; 						// q 指向被删除结点 ;
	p->next = q->next;							// 前驱结点的后继指向 q 的下一个; 
	delete q;									// 释放 q 指向的结点; 
} 

// 删除某个给定的结点 q ，时间复杂度 O(1); 
void deleteTheLNode(LNode* q){
	LNode* p = q->next;							// 指向删除结点的下一个结点;
	if(p != NULL) {								// 如果 p 不为空，复制 p 到 q; 
		q->data = p->data;						
		q->next = p->next;
		delete p;
	} else {									// 如果 p 为空，直接释放 q; 
		delete q;
	}								
} 

// 求表长：不包括头结点的长度
int lengthOfLinkedList(LNode* head){
	LNode* p = head->next;						// p 指向不包括头结点的第一个结点; 
	int length = 0;								// 为链表的长度计数; 
	while(p){									// 遍历到最后，判空; 
		length++;								// 不为空，则 +1; 
		p = p->next;							// 继续向后执行;
	}
	return length;								// 返回链表的长度; 
} 

/*
 * 1. 设计一个递归算法，删除不带头结点的单链表 L 中所有值为 x 的结点; 
 */
void deleteX(LNode* &head, int x){	//	这里要加引用！！！ 
	if(head == NULL)	return;		//	递归的出口 
	if(head->data == x){			//	找到等于 x 的结点 
		LNode* q = head;			//
		head = head->next;			// 	这里的 head 其实是上一层递归的 head->next，因为是引用，所以链表并不会断; 
		delete q;					//	释放符合条件的结点 
		deleteX(head, x);			//	从这个结点开始递归 
	} else {	
		deleteX(head->next, x);		
	}
}

/*
 * 2. 在带头结点的单链表 L 中，删除所有值为 x 的结点，并释放其空间，假设值为 x 的结点不唯一，试编写算法以实现上述操作。 
 *    这一题中我使用与之后的元素进行交换的想法，但是对于最后一个数无法操作，无法与之后的数进行交换。
 *	  因此可以采用两个指针，一个指向前面的指针，一个指向当前指针。 
 */
void deleteX_1(LNode* head, int x){
	LNode* front = head;			// 前驱指针 
	LNode* p = head->next;			// 当前检查的指针 
	while(p){
		if(p->data == x){			// 检查当前结点值是否为 x 
			LNode* q = p;			// 使 q 指向当前结点，便于之后的删除操作 
			p = p->next;			// p 指向下一个结点 
			front->next = p;		// 前驱指针后移 
			delete q;				// 删除当前等于 x 的节点 
		} else {
			front = p;				// 如果不等于 x，两个指针都向后移动一个位置 
			p = p->next;
		}
	}
}

/*
 * 3. 设 L 为带头结点的单链表，编写算法实现从尾到头反向输出每个节点的值。 
 *    使用递归的方法实现，其实相当于把数据依次放进栈中，然后再从栈中倒出来。 
 */ 
void reverseOutput(LNode* &head){
	if(head->next == NULL)	return;			// 递归出口 
	reverseOutput(head->next);				// 递归下一个 
	cout << head->next->data << endl;		// 输出 
} 

/*
 * 4. 使编写在带头结点的单链表 L 中删除一个最小值结点的高效算法(假设最小值结点使是唯一的)。 
 */
void deleteMin(LNode* &head){
	LNode* pre = head;						// pre 指向最小元素的前一个 
	LNode* p = head->next;					// 默认一开始头结点的下一个最小 
	while(p->next != NULL){
		if(p->next->data < pre->next->data){// 比较 
			pre = p;
		}
		p = p->next; 
	}
	LNode* d = pre->next;					// 删除最后找到的 pre 的下一个元素 
	pre->next = d->next;
	delete d;
} 
// 编写在 不 带头结点的单链表 L 中删除一个最小值结点的高效算法(假设最小值结点使是唯一的)。
// 没有条件，创造条件！如果有第二个结点，使第二个结点为初始最小值结点。 
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
		if(p->next->data < pre->next->data){// 比较 
			pre = p;
		}
		p = p->next; 
	}
	LNode* d = pre->next;					// 删除最后找到的 pre 的下一个元素 
	pre->next = d->next;
	delete d;	
} 

/*
 * 5. 试编写算法将带头结点的单链表就地逆置 -> 辅助空间复杂度为 O(1) 
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
 * 6. 有一个带头结点的单链表 L ，设计一个算法使其元素递增有序。 
 * 插入排序，时间复杂度 O(n^2).
 * 还可以复制到数组中，排序好之后再复制到链表中。 
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
 * 7. 设在一个带头结点的单链表中所有元素结点的数据值无序，试编写一个函数
 *    删除表中所有介于给定的两个值（作为函数参数给出）之间的元素。 
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
 * 8. 给定两个单链表，编写算法找出两个链表的公共结点。 
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
 * 9. 给定一个带头结点的单链表，按递增次序输出单链表中的数据元素，并且释放结点所占的存储空间。 
 */
void sortAndDelete(LNode* &head){
	LNode* pre;					// 指向需要删除结点的前驱结点 
	LNode* p;					// 遍历 
	LNode* d;					// 指向删除的结点 
	while(head->next){			// 每次遍历直到链表为空为止
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
 * 10. 将一个带头结点的单链表 A 分解为两个带头结点的单链表 A 和 B，
 *     使得 A 表中含有原表中序号为奇数的元素，而 B 表中含有原表中序号为偶数的元素，
 *     且保持其相对顺序不表。 
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
 * 11. 设 C = {a1,b1,a2,b2,...,an,bn}为线性表，采用带头结点的单链表存放，将其拆分为两个线性表 A = {a1,a2,a3,...,an} 和 B = {bn,bn-1,bn-2,...,b1};
 * 与上一题不同的是采用的是头插法，导致顺序逆置；
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
 * 12. 在一个递增有序的线性表中，有数值相同的元素存在，若存储形式为单链表，设计算法去除相同的元素，使表中不再有重复的元素；
 */
void del_same(LNode* &head){
	if(head->next == nullptr || head->next->next == nullptr)	return;	// 如果不含节点或者只有一个节点，直接返回；
	LNode* p = head->next;												// p 工作指针，用来扫描；
	LNode* q;															// q 作为 p 的后继，用来判断值是否相等，相等的话则删除；
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
 * 13. 假设有两个按元素值递增次序排列的线性表，均以单链表的形式存储，请编写算法将其合并为一个按元素值递减次序排列的单链表，并要求利用原来两个链表的节点存放归并后的单链表；
 */
void mergeList(LNode* &A, LNode* &B){	
	LNode* LA = A->next;
	LNode* LB = B->next;
	LNode* head = A;	// 新链表的头
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
 * 14. 设 A 和 B 是两个带头结点的单链表，其中元素递增有序，设计一个算法从 A 和 B 中的公共元素产生单链表 C，要求不破坏 A 和 B 的节点；
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
 * 15. 已知两个链表 A 和 B 分别表示两个集合，其元素递增排列，绘制函数，求 A 和 B 的交集，并存放于 A 链表中；
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
 * 16. 两个整数序列 A = a1, a2,...,an;和 B = b1, b2,...,bm; 已经存入两个单链表中，设计一个算法，判断序列 B 是否为序列 A 的子序列；
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
 * 21. (2009) 带有头结点的单链表，查找链表中倒数第 k 个位置上的结点（k 为正整数）。若查找成功，输出该结点date域的值，并返回1；否则只返回0；
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

