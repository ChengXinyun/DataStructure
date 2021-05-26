#include <iostream>

using namespace std;

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


// ������� 
void display(int num[], int n){
	for(int i = 0; i < n; i++){
		cout << num[i] << " ";
	}
	cout << endl;
}

int main(){
	int num[10] = {10,9,8,7,6,5,4,11,2,1};
	//InsertSort(num, 10);
	//HalfInsertSort(num, 10);
	ShellSort(num, 10);
	display(num, 10);
}
