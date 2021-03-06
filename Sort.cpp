#include <iostream>

using namespace std;


/*
 * 插入排序：
 * 1. 直接插入排序
 * 2. 折半插入排序
 * 3. 希尔排序 
 */

// 直接插入排序 
void InsertSort(int num[], int n){
	int i, j;
	for(int i = 1; i < n; i++){
		int temp = num[i];
		
		for(j = i - 1; temp < num[j]; --j){
			num[j + 1] = num[j];
		}
		num[j + 1] = temp;
	}
}

// 折半插入排序
void HalfInsertSort(int num[], int n){
	int i, j, low, high, mid;
	for(int i = 1; i < n; i++){
		int temp = num[i];
		low = 0;
		high = i - 1;
		while(low <= high){
			mid = (low + high) / 2;
			if(num[mid] > temp)	high = mid - 1;
			else	low = mid + 1;
		}
		for(j = i - 1; j >= high + 1; --j){//为什么是 >= high+1; 最后要移动的从 high + 1 结束； 
			num[j + 1] = num[j];
		} 
		num[high + 1] = temp;
	}
}

//希尔排序
void ShellSort(int num[], int n){
	int dk, i, j, temp;
	for(dk = n/2; dk >= 1; dk /= 2){
		for(i = dk; i < n; i++){
			if(num[i] < num[i - dk]){
				temp = num[i];
				for(j = i - dk; j>= 0 && temp < num[j]; j -= dk)
					num[j + dk] = num[j];
				num[j + dk] = temp; 
			}
		}
	}
} 

/*
 * 交换排序
 * 1. 冒泡排序
 * 2. 快速排序 
 */ 

// 冒泡排序
void BubbleSort(int num[], int n){
	for(int i = 0; i < n - 1; i++){
		bool flag = false;
		for(int j = n - 1; j > i; j--){
			if(num[j - 1] > num[j]){
				int t = num[j - 1];
				num[j - 1] = num[j];
				num[j] = t;
				flag = true;
			}
		}
		if(flag == false)
			return;
	}
} 

// 快速排序
int Partition(int num[], int low, int high){
	int pivot = num[low];
	while(low < high){
		while(low < high && num[high] >= pivot)
			high--;
		num[low] = num[high];
		
		while(low < high && num[low] <= pivot)
			low++;
		num[high] = num[low]; 
	}
	num[high] = pivot; // 这里的 low 和 high 的值是相同的，不管写哪一个都可以; 
	return high;
}

void QuickSort(int num[], int low, int high){
	if(low < high){
		int pivotpos = Partition(num, low, high);
		QuickSort(num, low, pivotpos - 1);
		QuickSort(num, pivotpos + 1, high);
	}
}


/*
 * 选择排序
 * 1. 简单选择排序
 * 2. 堆排序 
 */

// 简单选择排序
void SelectSort(int num[], int n){
	for(int i = 0; i < n - 1; i++){
		int min = i;
		for(int j = i + 1; j < n; j++){
			if(num[j] < num[min])	min = j;
		}
		if(min != i){
			int temp = num[i];
			num[i] = num[min];
			num[min] = temp;
		}
	}
} 

// 堆排序
// 将以 k 为根的子树进行调整 
void HeapAdjust(int num[], int k, int len){
	int temp = num[k];
	for(int i = 2 * k + 1; i < len; i = 2 * i + 1){
		if(i < len - 1 && num[i] < num[i + 1]){
			i++;
		}
		if(temp >= num[i])	break;
		else{
			num[k] = num[i];
			k = i;
		}
	}
	num[k] = temp;	
} 

// 建立大根堆
void BuildMaxHeap(int num[], int len){
	for(int i = len / 2 - 1; i >= 0; i--){
		HeapAdjust(num, i, len);
	}
}

// 堆排序算法
void HeapSort(int num[], int len){
	BuildMaxHeap(num, len);
	for(int i = len - 1; i > 0; i--){
		int temp = num[i];
		num[i] = num[0];
		num[0] = temp;
		HeapAdjust(num, 0, i); 
	}
} 

// 二路归并排序
void Merge(int num[], int low, int mid, int high){
	int n1 = mid - low + 1;
	int n2 = high - mid;
	
	// int* L = (int *)malloc(sizeof(int) * n1);
	// int* R = (int *)malloc(sizeof(int) * n2);
	int *L = new int[n1];
	int *R = new int[n2];
	
	int i, j;
	for(i = 0; i < n1; i++){
		L[i] = num[low + i];
	}
	for(j = 0; j < n2; j++){
		R[j] = num[mid + 1 + j];
	}
	
	i = j = 0;
	
	int k = low;
	while(i < n1 && j < n2){
		if(L[i] > R[j])	num[k++] = R[j++];
		else	num[k++] = L[i++];
	}
	
	while(i < n1){
		num[k++] = L[i++];
	}
	while(j < n2){
		num[k++] = R[j++];
	}
	
	delete L, R;
	// free(L);
	// free(R);
} 

void MergeSort(int num[], int low, int high){
	if(low < high){
		int mid = (low + high) / 2;
		MergeSort(num, low, mid);
		MergeSort(num, mid + 1, high);
		Merge(num, low, mid, high);
	}
}

// 输出数组 
void display(int num[], int n){
	for(int i = 0; i < n; i++){
		cout << num[i] << " ";
	}
	cout << endl;
}

int main(){
	int num[10] = {10,9,9,7,6,5,4,11,2,1};
	//InsertSort(num, 10);
	//HalfInsertSort(num, 10);
	//ShellSort(num, 10);
	//BubbleSort(num, 10);
	//QuickSort(num, 0, 9);
	//SelectSort(num, 10);
	//HeapSort(num, 10);
	MergeSort(num, 0, 9);
	display(num, 10);
}
