#include <iostream>
#include <algorithm>
#define MAX 100001

using namespace std;
int N;
int Honey[MAX];
int Sum[MAX];
int Answer = 0;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;
    
	for (int i = 1; i <= N; i++) {
		cin >> Honey[i];
		Sum[i] = Sum[i - 1] + Honey[i];
	}
    
	for (int i = 2; i < N; i++) {
		int Cur = (Sum[i] - Sum[1]) + (Sum[N - 1] - Sum[i - 1]);
		Answer = max(Answer, Cur);
	}

	for (int i = 2; i < N; i++) {
		int Cur = (Sum[N] - Sum[1] - Honey[i]) + (Sum[N] - Sum[i]);
		Answer = max(Answer, Cur);
	}

	for (int i = 2; i < N; i++) {
		int Cur = (Sum[N - 1] - Honey[i]) + Sum[i - 1];
		Answer = max(Answer, Cur);
	}
    
	cout << Answer << "\n";

	return 0;
}