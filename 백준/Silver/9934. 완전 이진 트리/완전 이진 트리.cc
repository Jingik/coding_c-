#include <iostream>
#include <vector>
using namespace std;


int input[10024];
int k;
vector<int> arr[10];
void Tree(int depth,int start, int end) {
	if (start >= end) {
		return;
	}
	int mid = (start + end) / 2;
    
	arr[depth].push_back(input[mid]);
	Tree(depth + 1, start, mid);
	Tree(depth + 1, mid+1, end);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	cin >> k;
	
	int num;
	int idx = 0;
	while (cin >> num) {
		input[idx++] = num;
	}
	Tree(0,0, idx);
	for (int i = 0; i < k; i++) {
		for (auto o : arr[i]) {
			cout << o << ' ';
		}
		cout << '\n';
	}
	return 0;
}