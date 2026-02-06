#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	string s1, s2;
	cin >> s1 >> s2;
	
	int alphabet1[26] = {};
	int alphabet2[26] = {};
	
	for (int i = 0; i < s1.length(); i++) {
		alphabet1[s1[i] - 'a']++;
	}
	for (int i = 0; i < s2.length(); i++) {
		alphabet2[s2[i] - 'a']++;
	}
	
	int ans = 0;
	for (int i = 0; i < 26; i++) {
		if (alphabet1[i] != alphabet2[i]) {
			ans += abs(alphabet1[i] - alphabet2[i]);
		}
	}
    
	cout << ans;
	
	return 0;
}