//정렬
#include <bits/stdc++.h>
using namespace std;
#define SWAP(x, y){int tmp = x; x=y; y=tmp;}

//데이터가 무작위로 여러 개 있을 때, 이	중에서 가장 작은 데이터를 선택해 맨 앞에 있는 데이터와 바꾸고, 
//그다음 작은 데이터를 선택해 앞에서 두 번째 데이터와 바꾸는 과정을 반복
void SelectionSort(vector<int> v) {
	vector<int> v2(v);

	for (int i = 0; i < v2.size(); i++) {
		int min_idx = i;
		for (int j = i+1; j < v2.size(); j++) {
			if (v2[min_idx] > v2[j])
				min_idx = j;
		}
		SWAP(v2[i], v2[min_idx]);
	}

	cout << "Selection Sort : ";
	for (auto it : v2) {
		cout << it << " ";
	}
	cout << '\n';
}
//데이터를 하나씩 확인하며, 각 데이터를 적절한 위치에 삽입
//특히 삽입 정렬은 필요할 때만 위치를 바꾸므로 데이터가 거의 정렬되어 있을 때 훨씬 효율적임.
void InsertionSort(vector<int> v) {
	vector<int> v2(v);

	for (int i = 1; i < v2.size(); i++) {
		for (int j = i; j > 0; j--) {
			if (v2[j] < v2[j - 1]) {
				SWAP(v2[j], v2[j-1]);
			}
			else
				break;
		}
	}

	cout << "Insertion Sort : ";
	for (auto it : v2) {
		cout << it << " ";
	}
	cout << '\n';

}
//특정한 조건이 부합할 때만 사용할 수 있지만 매우 빠른 정렬 알고리즘
//일반적으로 가장 큰 데이터와 가장 작은 데이터의 차이가 1,000,000을 넘지 않을 때 효과적으로 사용할 수 있다.
void CountSort(vector<int> v) {
	int count[10] = { 0, };
	for (int i = 0; i < v.size(); i++) {
		count[v[i]]++;
	}
	cout << "Count Sort     : ";
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < count[i]; j++)
			cout << i << " ";
	}
	cout << '\n';
}

//기준 데이터를 설정하고 그 기준보다 큰 데이터와 작은 데이터의 위치를 변경.
//호어 분할 방식 : 리스트에서 첫 번째 데이터를 피벗으로 정한다
void QuickSort(vector<int> &v, int start, int end) {
	if (start >= end) return;
	int pivot = start;
	int left = start + 1;
	int right = end;

	while (left <= right) {
		//피벗보다 큰 데이터를 찾을 때 까지 전진
		while (left <= end && v[left] <= v[pivot])
			left++;
		//피벗보다 작은 데이터를 찾을 때 까지 전진
		while (right > start && v[right] >= v[pivot])
			right--;
		if (left > right) {
			SWAP(v[pivot], v[right]);
		}
		else {
			SWAP(v[left], v[right]);
		}
	}

	QuickSort(v, start, right - 1);
	QuickSort(v, right+1, end);
}

int main() {
	vector<int> testArr = { 7, 5, 9, 0, 3, 1, 6, 2, 4, 8 };
	SelectionSort(testArr);
	InsertionSort(testArr);
	CountSort(testArr);
	vector<int> v2(testArr);
	QuickSort(v2, 0, v2.size() - 1);
	cout << "QuickSort Sort : ";
	for (auto it : v2) {
		cout << it << " ";
	}
	cout << '\n';

}