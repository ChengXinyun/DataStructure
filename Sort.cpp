#include <iostream>

using namespace std;


/*
 * ��������
 * 1. ֱ�Ӳ�������
 * 2. �۰��������
 * 3. ϣ������ 
 */

// ֱ�Ӳ������� 
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

// �۰��������
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
		for(j = i - 1; j >= high + 1; --j){//Ϊʲô�� >= high+1; ���Ҫ�ƶ��Ĵ� high + 1 ������ 
			num[j + 1] = num[j];
		} 
		num[high + 1] = temp;
	}
}

//ϣ������
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
 * ��������
 * 1. ð������
 * 2. �������� 
 */ 

// ð������
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

// ��������
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
	num[high] = pivot; // ����� low �� high ��ֵ����ͬ�ģ�����д��һ��������; 
	return high;
}

void QuickSort(int num[], int low, int high){
	if(low < high){
		int pivotpos = Partition(num, low, high);
		QuickSort(num, low, pivotpos - 1);
		QuickSort(num, pivotpos + 1, high);
	}
}


// ������� 
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
	QuickSort(num, 0, 9);
	display(num, 10);
}
