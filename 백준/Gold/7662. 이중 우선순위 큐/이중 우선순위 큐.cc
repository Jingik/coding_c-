#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    if(!(cin >> T)) return 0;
    
    while (T--) {
        int k;
        cin >> k;
        
        priority_queue<int> maxQ;
        priority_queue<int, vector<int>, greater<>> minQ;
        unordered_map<int, int> cnt;
        
        for (int i = 0; i < k; ++i) {
            char op; int x;
            cin >> op >> x;
            
            if (op == 'I') {
                maxQ.push(x);
                minQ.push(x);
                ++cnt[x];
            } else {
                if (cnt.empty()) continue;
                
                if (x == 1) {
                    while (!maxQ.empty() && cnt[maxQ.top()] == 0)
                        maxQ.pop();
                    if (!maxQ.empty()) {
                        --cnt[maxQ.top()];
                        maxQ.pop();
                    }
                } else {
                    while (!minQ.empty() && cnt[minQ.top()] == 0)
                        minQ.pop();
                    if (!minQ.empty()) {
                        --cnt[minQ.top()];
                        minQ.pop();
                    }
                }
            }
        }
        
        while (!maxQ.empty() && cnt[maxQ.top()] == 0) maxQ.pop();
        while (!minQ.empty() && cnt[minQ.top()] == 0) minQ.pop();
        
        if (maxQ.empty()) {
            cout << "EMPTY\n";
        } else {
            cout << maxQ.top() << ' ' << minQ.top() << '\n';
        }
    }
    return 0;
}