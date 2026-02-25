#include <iostream>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
	int T;
	cin >> T;
	
	for (int i = 1; i <= T; i++) {
		int a;
		int b;
		cin >> a >> b;
 
		cout << "Case #" << i << ": " << a << " + " << b << " = " << a + b << "\n"; //(또는 endl;)
	}
	return 0;
}