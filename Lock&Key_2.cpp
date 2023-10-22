//구현 문제 - 10 자물쇠와 열쇠
//프로그래머스 60059
#include <bits/stdc++.h>
using namespace std;

void RotateKey(vector<vector<int>>& key) {
	//시계방향 90도
	vector<vector<int>> tmp(key);
	for (int i = 0; i < key.size(); i++) {
		for (int j = key.size() - 1; j > -1; j--) {
			key[i][key.size() - 1 - j] = tmp[j][i];
		}
	}
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	int key_size = (int)key.size();
	int lock_size = (int)lock.size();
	int maps_size = lock_size + (2 * key_size);
	vector<vector<int>> maps(maps_size, vector<int>(maps_size, 0));

	for (int i = 0; i < lock_size; i++) {
		for (int j = 0; j < lock_size; j++) {
			maps[i+ key_size][j+ key_size] = lock[i][j];
		}
	}
	for (int rotate = 0; rotate < 4; rotate++) {
		for (int i = 0; i < lock_size + key_size; i++) {
			for (int j = 0; j < lock_size + key_size; j++) {

				//key 대입
				for (int x = 0; x < key_size; x++) {
					for (int y = 0; y < key_size; y++) {
						maps[i + x][j + y] += key[x][y];
					}
				}

				//Lock 해정 조건 검사
				int open = true;
				for (int x = 0; x < lock_size; x++) {
					for (int y = 0; y < lock_size; y++) {
						if (maps[key_size + x][key_size + y] != 1) {
							open = false;
							x = 20;
							y = 20;
						}
					}
				}
				if (open)
					return true;

				//key 꺼내기
				for (int x = 0; x < key_size; x++) {
					for (int y = 0; y < key_size; y++) {
						maps[i + x][j + y] -= key[x][y];
					}
				}
			}
		}
		RotateKey(key);
	}

	return false;
}

int main() {
	vector<vector<int>> key = { {0, 0, 0}, {1, 0, 0}, {0, 1, 1} };
	vector<vector<int>> lock = { {1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
	cout << solution(key, lock);
}