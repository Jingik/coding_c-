#include <iostream>
#include <string>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
	int count[10] = {};
	int a, b, c;
 
	cin >> a >> b >> c;
 
	int res = a * b * c;

	string s = to_string(res);
 
	for (char ch : s) {
		count[ch - '0']++;
	}
 
	for (int v : count) {
		cout << v << "\n";
	}
	return 0;
}