//백준 11727 - 2×n 타일링 2

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[1000] = { 0, };
    arr[1] = 1;
    arr[2] = 3;

    for (int i = 3; i <= n; i++) {
        arr[i] = (arr[i - 1] + (2 * arr[i - 2])) % 10007;
    }

    cout << arr[n] << endl;

}