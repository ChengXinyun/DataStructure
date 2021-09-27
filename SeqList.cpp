// ���Ա��˳���ʾ 

#include <iostream>
using namespace std;
// ��ĳ�ʼ���� 
#define InitSize 100

//������������ 
typedef int ElementType;

typedef struct {
	ElementType *data; // ��̬�������鳤�� 
	int length; // �������ݸ��� 
}SeqList;

// ��ʼ��˳��� 
bool InitList(SeqList &l){
	l.data = new ElementType[InitSize];
	if(!l.data)
		return false;
	l.length = 0;
	return true;
}

// ��˳����в�ֵ 
bool InsertToList(SeqList &l, int i, ElementType e){
	// i�����Ϸ�Χ 
	if(i < 1 || i > l.length + 1){
		return false;
	}
	// ˳����Ѿ�����,���ܽ��Ų��� 
	if(l.length >= InitSize){
		return false;
	}
	// ��˳�������һ��λ�������ƣ�ֱ��iλ�� 
	for(int j = l.length; j >= i; j--){
		l.data[j] = l.data[j-1];
	}
	l.data[i - 1] = e; // ����ڶ���λ�ã������ж�Ӧ�����±� 1 ; 
	l.length++; // �ǵüӳ��� 
	return true; 
}

bool DeleteList(SeqList &l, int i, ElementType &e){
	// i�����Ϸ�Χ 
	if(i < 1 || i > l.length){
		return false;
	}
	// ˳���Ϊ�յģ�����ɾ��
	if(l.length <= 0){
		return false;
	} 
	//�� e ����ɾ����ֵ 
	e = l.data[i - 1];
	// ��ɾ����λ�ÿ�ʼ�������ÿһ��Ԫ����ǰ��һλ�� 
	for(int j = i - 1; j < l.length; j++){
		l.data[j] = l.data[j + 1];
	}
	l.length--;
	return true;
} 

// ��λ���� 
bool GetElementByLocate(SeqList &l, int i, ElementType &e){
	if(i < 1 || i > l.length){
		return false;
	}
	// ˳���Ϊ�յģ�����ȡֵ 
	if(l.length <= 0){
		return false;
	}
	e = l.data[i - 1];
	return true; 
}

// ��ֵ���� 
bool GetElementByValue(SeqList &l, ElementType e, int &i){
	for(int j = 0; j < l.length; j++){
		if(e == l.data[j]){
			i = j + 1;
			return true;
		}
	}
	return false;
}

// ����
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
 * 1. ��˳�����ɾ��������Сֵ��Ԫ�أ�����Ψһ�����ɺ������ر�ɾ��Ԫ�ص�ֵ
 * �ճ���λ�������һ��Ԫ�������˳���Ϊ������ʾ������Ϣ���˳����С� 
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
 * 2. ���һ����Ч�㷨����˳���L������Ԫ�����ã�Ҫ���㷨�Ŀռ临�Ӷ�ΪO(1). 
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
 * 3. �Գ���Ϊn��˳���L����дһ��ʱ�临�Ӷ�ΪO(n)���ռ临�Ӷ�ΪO(1)���㷨��
 *    ���㷨ɾ�����Ա�������ֵΪx������Ԫ�ء� 
 */ 
void delAllX_1(SeqList &l, ElementType x){
	int k = 0; // ��¼˳����е���x�����ĸ���;
	
	for(int i = 0; i < l.length; i++){
		if(l.data[i] == x) // ��������k�ģ�k++��Ȼ����������� 
			k++;
		else{
			l.data[i-k] = l.data[i]; // ����������k�ģ���ǰ�ƶ�kλ; 
		}
	}
	l.length -= k; // ������峤��-k; 
} 

void delAllX_2(SeqList &l, ElementType x){
	int k = 0; // ��¼˳����в�����x�����ĸ���;
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
 * 4 and 5. ��˳�����ɾ����ֵ�ڸ��� s �� t ֮�䣨Ҫ�� s < t��������Ԫ�أ�
 *    ��� s �� t �������˳���Ϊ�գ�����ʾ������Ϣ���˳����С�  
 *
   4. ��������2021������Ĵ𰸣�����˳��������������޷�ɾ����emmm����𰸶��ǰ�˳����ġ����� 
      �����ò���ȥ����һ�����䣬ֱ�ӱ���ȥ�ƶ�ÿһ��Ԫ�ؾ��У�ʱ�临�Ӷ��ϻ�Ҫ���ӿ죻 
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
	
	int k = 0; // ��¼˳������� s �� t �����ϵ���;
	for(int i = 0; i < l.length; i++){
		if(l.data[i] >= s && l.data[i] <= t){
			k++;
		} else {
			l.data[i - k] = l.data[i]; // ���Ǹ��������ֱ����ǰ�� k λ 
		}
	} 
	l.length -= k;
	return true;  
}

/*
 * 6. ������˳�����ɾ��������ֵ�ظ���Ԫ�أ�ʹ��������Ԫ�ص�ֵ����ͬ�� 
 */
void delRepeatValue(SeqList &l){
	int k = 0; // ��¼˳����в��ظ�Ԫ�صĸ��� 
	
	// ��һ����ʼ���ظ� 
	for(int i = 1; i < l.length; i++){
		// ��Ϊ������ģ��벻�ظ��������һ���Ƚϼ��� 
		if(l.data[i] != l.data[k]){
			k++; //  ���ظ���Ԫ�ز��뵽��� 
			l.data[k] = l.data[i];
		}
	}
	l.length = k + 1; 
}

/*
 * 7. ���������򣨴�С����˳���ϲ�Ϊһ���µ����򣨴�С����˳������ɺ������ؽ��˳��� 
 */ 
bool mergeSeqList(SeqList l1, SeqList l2, SeqList &l){
	if(l1.length + l2.length > l.length){
 		cout << "The SeqList can't contain so many items." << endl;
		return false;	
	}
	
	int i = 0; // ָ���һ��˳��� l1�� 
	int j = 0; // ָ��ڶ���˳��� l2��
	int k = 0; // ָ��ϲ����˳��� l��
	while(i < l1.length && j < l2.length){
		// ˭С���Ȱ�˭�����µ�˳��� 
		if(l1.data[i] < l2.data[j]){
			l.data[k++] = l1.data[i++];
		} else {
			l.data[k++] = l2.data[j++];
		}
	} 
	
	// ��ʣ��Ĳ��� 
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
 * 8. ��֪��һά����A[m+n]�����δ���������Ա�(a1,a2,a3,...,am)��(b1,b2,b3,...,bn)��
 * �Ա�дһ��������������������˳����λ�û���������(b1,b2,b3,...,bn)���� (a1,a2,a3,...,am)��ǰ�档 
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
 * 9. ���Ա�(a1,a2,a3,...,an)�е�Ԫ�ص��������Ұ�˳��洢�ڼ�����ڡ�
 *    ���������ʱ���ڱ��в�����ֵΪ x ��Ԫ�أ����ҵ���������Ԫ��λ���ཻ����
 *    ���Ҳ������������в�ʹ����Ԫ���Ե������� 
 */
void findX(SeqList &l, ElementType e){
	// ���ַ����� 
	int left = 0;
	int right = l.length - 1;
	int mid;
	while(left <= right){
		mid = (right + left) / 2;
		
		// ����ҵ� e , �������̽ڵ㣻 
		if(l.data[mid] == e && mid != l.length - 1){
			ElementType temp = l.data[mid];
			l.data[mid] = l.data[mid + 1];
			l.data[mid+1] = temp;
			break;
		} else if(l.data[mid] > e){
			// ��벿�ֲ��� 
			right = mid - 1;
		} else {
			// �Ұ벿�ֲ��� 
			left = mid + 1;
		}	
	}
	// û���ҵ��Ͳ��� 
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
 * 10.(2010ͳ������) �轫 n (n > 1)��������ŵ�һά���� R ��, ���һ����ʱ���
 *   �ռ��������涼�����ܸ�Ч���㷨���� R �б��������ѭ������ p (0 < p < n)��λ��   
 *  ��ڰ���һ�������������ã�Ȼ���پֲ����á�ʱ�临�Ӷ� O(n), �ռ临�Ӷ� O(1); 
 */ 

/*
 * 11.(2011ͳ������) һ������Ϊ L (L >= 1) ���������� S�����ڵ�[L / 2]��λ�õ�����Ϊ S ����λ����
 * ���������ȳ��������� A �� B�����һ����ʱ��Ϳռ��������涼�����ܸ�Ч���㷨�ҳ�A��B����λ���� 
 */ 
// ���������Ҫ���ƣ�
//ʱ�临�Ӷ� O(n), �ռ临�Ӷ� O(1);  
int findMid_1(int a[], int b[], int length){
	int i = 0;
	int j = 0;
	int mid;
	// �����������У�ֻ��Ҫ�������г��ȾͿ����ҵ��� 
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

// ʱ�临�Ӷ� O(logN),�ռ临�Ӷ� O(1) 
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
		if(a[mid1] < b[mid2]){
			if((s1 + d1) % 2 == 0){
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
	return a[s1] < b[s2] ? a[s1] : b[s2]; // ���ֻʣһ�����ĸ�С������λ�� 
} 

/*
 * 12. ��֪һ���������� A = (a0,a1,...,an-1),���� 0 <= ai < n(0 <= i < n). 
 *     Ѱ����Ԫ�أ��������г��ֳ������������� 
 *     A = (0,5,5,3,5,1,5,7) �� 5 ����Ԫ�أ� 
 */ 
// ����������Ԫ�أ����� 8 ��Ԫ�أ���Ԫ��Ҫ���ִ��� 4 �Σ������ٳ��� 5 �Σ�
// �˸���λ�ֳ��ķݣ��൱������5����ŵ��ĸ�Ͱ��������һ�������������� 
int findMain(int A[], int n){
	int i;
	int m = A[0]; // ��ѡȡ��һ����Ϊ��Ԫ��
	int count = 1;   // ��¼��Ԫ�س��ֵĴ���
	
	// Ѱ�ҿ��ܴ��ڵ���Ԫ��;ʱ�临�Ӷ� O(n) 
	for(i = 1; i < n; i++){
		if(A[i] == m){
			count++; // ������Ԫ�� 
		} else {
			if(count > 0){      
				count--;
			} else { // ����Ԫ�� 
				m = A[i];
				count = 1;
			}
		}
	}
	// ����ͳ�Ƴ��ֵĴ������Ƿ���� n/2;ʱ�临�Ӷ� O(n); 
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
 * 13. ����һ���� n(n >= 1) �����������飬�����һ����ʱ���Ͼ����ܸ�Ч���㷨���ҳ�������δ���ֵ���С�������� 
 */ 
int findMinInterger(int A[], int n){
	int *B = new int[n];  
	// int* B = (int *)malloc(sizeof(int)*n); 
	int i;
	
	// memset(B,0,sizeof(int)*n)
	for(i = 0; i < n; i++){
		B[i] = 0; 
	}
	for(i = 0; i < n; i++){
		if(A[i] > 0 && A[i] <= n){
			B[A[i] - 1] = 1;
		}
	}
	// Ѱ��δ���ֵ��Ǹ�������; 
	for(i = 0; i < n; i++){
		if(B[i] == 0){
			break;
		}
	}
	// ���ҵ��ˣ��� i ��ʾ���� A[i] - 1, ���� i + 1; 
	// ��û���ҵ����� i = n ������С�������� n + 1; 
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
	int a[5] = {11,13,15,17,19};
	int b[5] = {2,4,6,8,11};
	cout << findMid_2(a,b,5) << endl; 
}

