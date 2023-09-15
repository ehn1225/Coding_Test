//정렬 알고리즘
#include <bits/stdc++.h>
using namespace std;

void SelectionSort(int* arr, int n) {
	//선택정렬
	//0번 인덱스부터 배열을 탐색
	//현재의 인덱스를 제외한 이후의 원소들 중에서 제일 작은 원소 선택 후 SWAP
	for (int i = 0; i < n; i++) {
		int index = i;
		for(int j = i+1; j < n; j++){
			if (arr[index] > arr[j])
				index = j;
		}
		int tmp = arr[i];
		arr[i] = arr[index];
		arr[index] = tmp;
	}
}

void InsertionSort(int* arr, int n) {
	//삽입정렬
	//인덱스 0번 원소는 고정
	//이후 원소들을 계속 앞으로 끌어오는 방식

	for (int i = 1; i < n; i++) {
		for (int j = i; j >= 0; j--) {
			if (arr[j] < arr[j - 1]) {
				int tmp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = tmp;
			}
			else
				break;

		}
	}
}

void QuickSort(int* arr, int start, int end) {
	//퀵정렬
	//피봇을 기준으로 앞에는 피봇보다 작은값들만, 뒤에는 큰값들만
	int pivot = start;
	int left = start + 1, right = end;
	if (start >= end) return;

	while (left <= right) {
		while ((arr[left] <= arr[pivot]) && left <= end) left++;
		while ((arr[right] >= arr[pivot]) && right > start) right--;
		if (left > right) swap(arr[right], arr[pivot]);
		else swap(arr[right], arr[left]);
	}

	QuickSort(arr, start, right - 1);
	QuickSort(arr, right+1, end);
}

void CountSort(int *arr, int n) {
	//계수정렬
	//인덱스 리스트을 만드는 방식
	int* arr2 = new int[(n + 1)];
	memset(arr2, 0, sizeof(int) * (n + 1));
	/*
	for (int i = 0; i <= n; i++) {
		arr2[i] = 0;
	}
	*/

	for (int i = 0; i < n; i++) {
		arr2[arr[i]]++;
	}

	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < arr2[i]; j++)
			cout << i << " ";
	}
}

void PrintArr(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	int arr[10] = {7, 5, 6, 1, 2, 8, 4, 3, 10, 9};
	//SelectionSort(arr, 10);
	//InsertionSort(arr, 10);
	//QuickSort(arr, 0, 9);
	//PrintArr(arr, 10);

	int arr2[20] = { 7, 5, 6, 1, 2, 8, 4, 3, 10, 9, 5, 5, 7, 1, 8, 10, 11, 8, 20, 5};
	CountSort(arr2, 20);
}