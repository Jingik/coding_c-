#include <iostream>
 
using namespace std;
 
int main() { 
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
	int count[42] = {};	
	int v;
    
	for(int i = 0; i < 10; i++) {
		cin >> v;
		count[v % 42]++;	
	}
 
	int result = 0;
	for(int v : count) {
		if(v > 0) {		
		    result++;
		}
	}
	cout << result;
    
	return 0;
}