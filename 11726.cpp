//���� 11726 - 2��n Ÿ�ϸ�
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[1000] = { 0, };
    arr[1] = 1;
    arr[2] = 2;

    for (int i = 3; i <= n; i++) {
        arr[i] = (arr[i - 1] + arr[i - 2]) % 10007;
    }

    cout << arr[n] << endl;

}