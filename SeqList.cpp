// 线性表的顺序表示 

#include <iostream>
using namespace std;
// 表的初始长度 
#define InitSize 100

//表中数据类型 
typedef int ElementType;

typedef struct {
	ElementType *data; // 动态分配数组长度 
	int length; // 表中数据个数 
}SeqList;

// 初始化顺序表 
bool InitList(SeqList &l){
	l.data = new ElementType[InitSize];
	if(!l.data)
		return false;
	l.length = 0;
	return true;
}

// 向顺序表中插值 
bool InsertToList(SeqList &l, int i, ElementType e){
	// i不符合范围 
	if(i < 1 || i > l.length + 1){
		return false;
	}
	// 顺序表已经满了,不能接着插入 
	if(l.length >= InitSize){
		return false;
	}
	// 从顺序表的最后一个位置往后移，直到i位置 
	for(int j = l.length; j >= i; j--){
		l.data[j] = l.data[j-1];
	}
	l.data[i - 1] = e; // 插入第二个位置，数组中对应的是下标 1 ; 
	l.length++; // 记得加长度 
	return true; 
}

bool DeleteList(SeqList &l, int i, ElementType &e){
	// i不符合范围 
	if(i < 1 || i > l.length){
		return false;
	}
	// 顺序表为空的，不能删除
	if(l.length <= 0){
		return false;
	} 
	//用 e 返回删除的值 
	e = l.data[i - 1];
	// 从删除的位置开始，后面的每一个元素向前移一位； 
	for(int j = i - 1; j < l.length; j++){
		l.data[j] = l.data[j + 1];
	}
	l.length--;
	return true;
} 

// 按位查找 
bool GetElementByLocate(SeqList &l, int i, ElementType &e){
	if(i < 1 || i > l.length){
		return false;
	}
	// 顺序表为空的，不能取值 
	if(l.length <= 0){
		return false;
	}
	e = l.data[i - 1];
	return true; 
}

// 按值查找 
bool GetElementByValue(SeqList &l, ElementType e, int &i){
	for(int j = 0; j < l.length; j++){
		if(e == l.data[j]){
			i = j + 1;
			return true;
		}
	}
	return false;
}

// 遍历
void TraverseSeqList(SeqList &l){
	for(int i = 0; i < l.length; i++){
		cout << l.data[i] << " ";
	}
	cout << endl;
} 
/*
int main(){
	SeqList l;
	
	InitList(l);
	TraverseSeqList(l);
	
	int num[10] = {1,2,3,4,5,6};
	for(int i = 0; i < 10; i++){
		InsertToList(l, i + 1, num[i]);	
	}
	TraverseSeqList(l);
	
	int deleteValue;
	bool f = DeleteList(l, 2, deleteValue);
	cout << f << " "<< deleteValue << endl;
	TraverseSeqList(l);
	
	bool f1 = DeleteList(l, 11, deleteValue);
	cout << f1 << " "<< deleteValue << endl;
	
	int e;
	bool f2 = GetElementByLocate(l, 9, e);
	cout << f2 << " " << e << endl;
	
	cout << GetElementByLocate(l, 11, e) << endl;
	
	int i;
	bool f3 = GetElementByValue(l, 3, i);
	cout << f3 << " " << i << endl;
	
	cout << GetElementByValue(l, 9, i) << endl;
	
	return 0;
} */

/*
 * 1. 从顺序表中删除具有最小值的元素（假设唯一）并由函数返回被删除元素的值
 * 空出的位置由最后一个元素填补，若顺序表为空则显示出错信息并退出运行。 
 */
bool deleteMinValue(SeqList &l, ElementType &e){
	if(l.length == 0){
		cout << "The SeqList Is Empty!" << endl;
		return false;
	}
	e = l.data[0];
	int min_index = 0;
	for(int i = 0; i < l.length; i++){
		if(l.data[i] < e){
			e = l.data[i];
			min_index = i;
		}	
	}
	l.data[min_index] = l.data[l.length - 1];
	l.length--;
	return true;
} 

/*
 * 2. 设计一个高效算法，将顺序表L的所有元素逆置，要求算法的空间复杂度为O(1). 
 */ 
void reverseSeqList(SeqList &l){
	ElementType temp;
	for(int i = 0; i < l.length / 2; i++){
		temp = l.data[i];
		l.data[i] = l.data[l.length - i - 1];
		l.data[l.length - i - 1] = temp;	
	}
} 

/*
 * 3. 对长度为n的顺序表L，编写一个时间复杂度为O(n)、空间复杂度为O(1)的算法，
 *    该算法删除线性表中所有值为x的数据元素。 
 */ 
void delAllX_1(SeqList &l, ElementType x){
	int k = 0; // 记录顺序表中等于x的数的个数;
	
	for(int i = 0; i < l.length; i++){
		if(l.data[i] == x) // 遇到等于k的，k++，然后继续往后走 
			k++;
		else{
			l.data[i-k] = l.data[i]; // 遇到不等于k的，向前移动k位; 
		}
	}
	l.length -= k; // 最后整体长度-k; 
} 

void delAllX_2(SeqList &l, ElementType x){
	int k = 0; // 记录顺序表中不等于x的数的个数;
	int i = 0;
	while(i < l.length){
		if(l.data[i] != x){
			l.data[k] = l.data[i];
			k++;
		}
	} 
	l.length = k;
}

/*
 * 4 and 5. 从顺序表中删除其值在给定 s 和 t 之间（要求 s < t）的所有元素，
 *    如果 s 或 t 不合理或顺序表为空，则显示出错信息并退出运行。  
 *
   4. 王道考研2021书上面的答案，对于顺序表假如是逆序就无法删除。emmm好像答案都是按顺序处理的。。。 
      因此最好不用去找这一个区间，直接遍历去移动每一个元素就行，时间复杂度上还要更加快； 
bool Del_s_t(SeqList &l, ElementType s, ElementType t){
	int i, j;
	if(s >= t || l.length == 0){
		return false;
	}
	for(i = 0; i < l.length && l.data[i] < s; i++);
	if(i >= l.length)
		return false;
	for(j = i; j < l.length && l.data[j] <= t; j++);
	for(;j < l.length; i++,j++)
		l.data[i] = l.data[j];
		l.length = i;
		return true;
}
*/
bool Del_s_t(SeqList &l, ElementType s, ElementType t){
	if(s >= t){
		cout << " s >= t" << endl;
		return false;
	}
	if(l.length ==  0){
		cout << "The SeqList Is Empty." << endl;
		return false;
	}
	
	int k = 0; // 记录顺序表中在 s 到 t 区间上的数;
	for(int i = 0; i < l.length; i++){
		if(l.data[i] >= s && l.data[i] <= t){
			k++;
		} else {
			l.data[i - k] = l.data[i]; // 不是该区间的数直接向前移 k 位 
		}
	} 
	l.length -= k;
	return true;  
}

/*
 * 6. 从有序顺序表中删除所有其值重复的元素，使表中所有元素的值均不同。 
 */
void delRepeatValue(SeqList &l){
	int k = 0; // 记录顺序表中不重复元素的个数 
	
	// 第一个开始不重复 
	for(int i = 1; i < l.length; i++){
		// 因为是有序的，与不重复区的最后一个比较即可 
		if(l.data[i] != l.data[k]){
			k++; //  不重复的元素插入到最后 
			l.data[k] = l.data[i];
		}
	}
	l.length = k + 1; 
}

/*
 * 7. 将两个有序（从小到大）顺序表合并为一个新的有序（从小到大）顺序表，并由函数返回结果顺序表。 
 */ 
bool mergeSeqList(SeqList l1, SeqList l2, SeqList &l){
	if(l1.length + l2.length > l.length){
 		cout << "The SeqList can't contain so many items." << endl;
		return false;	
	}
	
	int i = 0; // 指向第一个顺序表 l1； 
	int j = 0; // 指向第二个顺序表 l2；
	int k = 0; // 指向合并后的顺序表 l；
	while(i < l1.length && j < l2.length){
		// 谁小就先把谁插入新的顺序表 
		if(l1.data[i] < l2.data[j]){
			l.data[k++] = l1.data[i++];
		} else {
			l.data[k++] = l2.data[j++];
		}
	} 
	
	// 将剩余的插入 
	while(i < l1.length){
		l.data[k++] = l1.data[i++];
	}
	while(j < l2.length){
		l.data[k++] = l2.data[j++];
	}
	l.length = k; 
	return true;
}  

/*
 * 8. 已知在一维数组A[m+n]中依次存放两个线性表(a1,a2,a3,...,am)和(b1,b2,b3,...,bn)。
 * 试编写一个函数，将数组中两个顺序表的位置互换，即将(b1,b2,b3,...,bn)放在 (a1,a2,a3,...,am)的前面。 
 */
void traverseSeqList(ElementType array[], int start, int end){
	for(int i = start, j = end; i < j; i++, j--){
		ElementType temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	}
}

void swapSeqList(ElementType array[], int m, int n){
	traverseSeqList(array, 0, m + n - 1);
	traverseSeqList(array, 0, n - 1);
	traverseSeqList(array, n, n + m - 1);
}

/*
 * 9. 线性表(a1,a2,a3,...,an)中的元素递增有序且按顺序存储于计算机内。
 *    完成用最少时间在表中查找数值为 x 的元素，若找到则将其与后继元素位置相交换，
 *    若找不到则将其插入表中并使表中元素仍递增有序。 
 */
void findX(SeqList &l, ElementType e){
	// 二分法查找 
	int left = 0;
	int right = l.length - 1;
	int mid;
	while(left <= right){
		mid = (right + left) / 2;
		
		// 如果找到 e , 交换其后继节点； 
		if(l.data[mid] == e && mid != l.length - 1){
			ElementType temp = l.data[mid];
			l.data[mid] = l.data[mid + 1];
			l.data[mid+1] = temp;
			break;
		} else if(l.data[mid] > e){
			// 左半部分查找 
			right = mid - 1;
		} else {
			// 右半部分查找 
			left = mid + 1;
		}	
	}
	// 没有找到就插入 
	if(left > right){
		int i;
		for(i = l.length - 1; i > right; i--){
			l.data[i + 1] = l.data[i];
		}
		l.data[i + 1] = e;
		l.length++;
	}
} 

/*
 * 10.(2010统考真题) 设将 n (n > 1)个整数存放到一维数组 R 中, 设计一个在时间和
 *   空间两个方面都尽可能高效的算法。将 R 中保存的序列循环左移 p (0 < p < n)个位置   
 *  与第八题一样，先整体逆置，然后再局部逆置。时间复杂度 O(n), 空间复杂度 O(1); 
 */ 

/*
 * 11.(2011统考真题) 一个长度为 L (L >= 1) 的升序序列 S，处在第[L / 2]个位置的数称为 S 的中位数。
 * 现有两个等长升序序列 A 和 B，设计一个在时间和空间两个方面都尽可能高效的算法找出A和B的中位数。 
 */ 

//时间复杂度 O(n), 空间复杂度 O(1);  
int findMid_1(int a[], int b[], int length){
	int i = 0;
	int j = 0;
	int mid;
	// 遍历两个序列，只需要遍历序列长度就可以找到； 
	while(length--){
		if(a[i] < b[j]){
			mid = a[i];
			i++;			
		} else {
			mid = b[j];
			j++;
		}	
	}
	return mid;
} 

// 时间复杂度 O(logN),空间复杂度 O(1) 
int findMid_2(int a[], int b[], int length){
	int s1 = 0, d1 = length - 1;
	int s2 = 0, d2 = length - 1;
	int mid1, mid2;
	while(s1 != d1 || s2 != d2){
		mid1 = (s1 + d1) / 2;
		mid2 = (s2 + d2) / 2;
		if(a[mid1] == b[mid2]){
			return a[mid1];
		}
		
		// 舍弃区间时，保持对称； 
		if(a[mid1] < b[mid2]){
			if((s1 + d1) % 2 == 0){ // 元素个数为奇数 (0+4) 
				s1 = mid1;
				d2 = mid2;
			} else {   
				s1 = mid1 + 1;
				d2 = mid2;	
			}
		} else {
			if((s2 + d2) % 2 == 0){
				s2 = mid2;
				d1 = mid1;
			} else {
				s2 = mid2 + 1;
				d1 = mid1;	
			}
		}
	}
	return a[s1] < b[s2] ? a[s1] : b[s2]; // 最后只剩一个，哪个小就是中位数 
} 

/*
 * 12. 已知一个整数序列 A = (a0,a1,...,an-1),其中 0 <= ai < n(0 <= i < n). 
 *     寻找主元素：在序列中出现超过半数的数； 
 *     A = (0,5,5,3,5,1,5,7) 则 5 是主元素； 
 */ 
// 超过半数的元素，例如 8 个元素，主元素要出现大于 4 次，即至少出现 5 次；
// 八个空位分成四份，相当于至少5个球放到四个桶，至少有一个里面有两个； 
int findMain(int A[], int n){
	int i;
	int m = A[0]; // 先选取第一个作为主元素
	int count = 1;   // 记录主元素出现的次数
	
	// 寻找可能存在的主元素;时间复杂度 O(n) 
	for(i = 1; i < n; i++){
		if(A[i] == m){
			count++; // 计数主元素 
		} else {
			if(count > 0){      
				count--;
			} else { // 更换元素 
				m = A[i];
				count = 1;
			}
		}
	}
	// 重新统计出现的次数，是否大于 n/2;时间复杂度 O(n); 
	if(count > 0){
		for(i = count = 0; i < n; i++){
			if(A[i] == m){
				count++;
			}
		}
	}
	if(count > n / 2)
		return m;
	return -1;
} 

/*
 * 13. 给定一个含 n(n >= 1) 个整数的数组，请设计一个在时间上尽可能高效的算法，找出数组中未出现的最小正整数。 
 */ 
int findMinInterger(int A[], int n){
	int *B = new int[n]; // 用B数组标记是否出现; 
	// int* B = (int *)malloc(sizeof(int)*n); 
	int i;
	
	// memset(B,0,sizeof(int)*n)可以用这个赋值 
	for(i = 0; i < n; i++){
		B[i] = 0; // 全部赋初始值为 0; 
	}
	// 遍历寻找是否出现 
	for(i = 0; i < n; i++){
		if(A[i] > 0 && A[i] <= n){
			B[A[i] - 1] = 1;
		}
	}
	// 寻找未出现的那个正整数; 
	for(i = 0; i < n; i++){
		if(B[i] == 0){
			break;
		}
	}
	// 若找到了，则 i 表示的是 A[i] - 1, 返回 i + 1; 
	// 若没有找到，则 i = n 返回最小正整数是 n + 1; 
	return i + 1; 
}

int main(){
	SeqList l;
	InitList(l);
	int num[10] = {1,2,3,4,5,6,7,8,9,10};
	for(int i = 0; i < 10; i++){
		InsertToList(l, i + 1, num[i]);	
	}
	findX(l, 14);
	TraverseSeqList(l);
	int a[5] = {1,13,15,17,19};
	int b[5] = {2,4,6,8,11};
	cout << findMinInterger(a, 5) << endl; 
}
