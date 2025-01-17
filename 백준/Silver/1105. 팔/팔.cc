#include <iostream>
#include <string>
using namespace std;

int main() {
	string L, R;
	int min = 0;
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> L >> R;

	if (L.size() != R.size()) {
		cout << 0;
	}

	else {
		for (int i = 0; i < L.size(); i++) {
			if (L[i] != R[i]) {
				break;
			}

			if (L[i] == R[i] && L[i] == '8') {
				min++;
			}
		}

		cout << min;

	}

	return 0;
}
