#include <iostream>
#include <vector>
 
using namespace std;
 
void func();
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
	int C;
	cin >> C;
 
	for (int i = 0; i < C; i++) {
		func();
	}
 
	return 0;
}
 
void func() {
	int N;
	cin >> N;
 
	vector<int> vec;
 
	for (int i = 0; i < N; i++) {
		int value;
		cin >> value;
		vec.push_back(value); 
	}
 
	double avg = 0;
	for (auto &val : vec) {
		avg += val; 
	}
	avg = avg / N; 
 
	double count = 0;
	for (auto &val : vec) {
		if (val > avg) {
			count++;
		}
	}
 
 
	double result = (count / N) * 100;
	cout << fixed;
	cout.precision(3);
	cout << result << "%\n";
}