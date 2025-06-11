#include <bits/stdc++.h>
using namespace std;

set<string> M;
string S;

int main(){	
	ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
	cin >> S;
	
	int i,j,l=S.length();
	
	for(i=0;i<l;i++)
		for(j=i;j<l;j++)
			M.insert(S.substr(i,j-i+1));
	
	cout << M.size();
}