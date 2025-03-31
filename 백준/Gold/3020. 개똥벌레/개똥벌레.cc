#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 
int n, h;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	cin >> n >> h;
	vector<int> bottom(h + 1, 0); 
	vector<int> top(h + 1, 0); 
	vector<int> result(h + 1, 0); 
	for (int i = 0; i < n / 2; i++) {
		int a, b; cin >> a >> b; 
		bottom[a]++; 
		top[h + 1 - b]++; 		
	}
	for (int i = h-1; i >= 1; i--) {
		bottom[i] += bottom[i + 1]; 
	}
	int min_num = 987654321;
	int cnt = 0; 
	for (int i = 1; i <= h; i++) {
		top[i] += top[i - 1]; 
		result[i] += top[i] + bottom[i]; 
		if (min_num > result[i]) {
			cnt = 1;
			min_num = result[i];
		}
		else if (result[i] == min_num)cnt++; 
	}
	cout << min_num << " " << cnt; 
}