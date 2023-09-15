//탐색 - 이진탐색
#include <bits/stdc++.h>
using namespace std;

//재귀함수를 이용한 이진탐색
int BinarySearch1(int* arr, int target, int start, int end) {
	if (start > end) return -1;

	int middle = (start + end) / 2;
	if (arr[middle] == target)
		return middle;
	else if (arr[middle] < target)
		return BinarySearch1(arr, target, middle + 1, end);
	else if (arr[middle] > target)
		return BinarySearch1(arr, target, start, middle - 1);

	return -1;
}

//반복문을 이용한 이진탐색
int BinarySearch2(int* arr, int target, int start, int end) {
	while (start <= end) {
		int middle = (start + end) / 2;
		if (arr[middle] == target)
			return middle;
		else if (arr[middle] < target)
			start = middle + 1;
		else if (arr[middle] > target)
			end = middle - 1;
	}
	
	return -1;
}
int main() {
	int arr[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,15,16,18,19,20,22,25,26,30,35};
	int key = 3;
	int pos = BinarySearch1(arr, key, 0, sizeof(arr) / sizeof(int));
	cout << key << "'s index : " << pos << endl;

}