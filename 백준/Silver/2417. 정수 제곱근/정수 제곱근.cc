#include <iostream>
#include <math.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
	long long n;
	long long q;
	
	cin >> n;
	
	q = sqrt(n);

	if ( (q*q) < n) {
		++q;
	}

	cout << q;

	return 0;
}