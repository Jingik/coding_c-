// 01_15.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <climits> 

using namespace std;

vector<long long>number;
int N;
int operators[4] = {0,};
// 0 : 덧셈, 1: 뺄셈, 2: 곱셈, 3: 나눗셈
long long max_num = LLONG_MIN;
long long min_num = LLONG_MAX;

void recur(long long current, int depth) {
	if (depth == N) {
		max_num = max(current, max_num);
		min_num = min(current, min_num);
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (operators[i] > 0) {
			operators[i]--;
			if (i == 0) {
				recur(current + number[depth], depth + 1);
			}
			else if(i == 1) {
				recur(current - number[depth], depth + 1);
			}
			else if (i == 2) {
				recur(current * number[depth], depth + 1);
			}
			else if (i == 3) {
				if (current > 0) {
					recur(current / number[depth], depth + 1);
				}
				else {
					recur(-(-(current) / number[depth]), depth + 1);
				}
			}
			operators[i]++;
		}
	}

}


int main()
{

	cin >> N;
	number.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> number[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> operators[i];
	}

	recur(number[0], 1);
	cout << max_num << "\n";
	cout << min_num << "\n";
}
