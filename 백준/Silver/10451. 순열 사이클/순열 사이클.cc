#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> a[1001];
bool check[1001];

void dfs(int node) {
	check[node]=true;
	for (int i=0; i<a[node].size(); i++) {
		int next = a[node][i];
		if (!check[next]) {
			dfs(next);
		}
	}
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i=1; i<=n; i++) {	
			a[i].clear();
			check[i]=false;
		}
		for (int i=1; i<=n; i++) {		
			int v;
			cin >> v;
			a[i].push_back(v);
		}
		int cnt=0;
		for (int i=1; i<=n; i++) {	
			if (!check[i]) {
				dfs(i);
				cnt++;
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}