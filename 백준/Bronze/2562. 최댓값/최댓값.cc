#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
	int a; 
	int idx, max = 0; 
	
	for (int i = 1; i <= 9; i++) {
		cin >> a;
		if (max < a) {
			max = a;
			idx = i;
		}
	}

	cout << max << '\n' << idx;
	
	return 0;
}