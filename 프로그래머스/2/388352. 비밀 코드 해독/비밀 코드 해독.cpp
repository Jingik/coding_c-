#include <string>
#include <vector>
using namespace std;

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    int answer = 0;
    int m = q.size();
    
    vector<int> comb(5);
    for (int i = 0; i < 5; ++i) {
        comb[i] = i;
    }
    
    while (true) {
        vector<int> candidate(5);
        for (int i = 0; i < 5; ++i) {
            candidate[i] = comb[i] + 1;
        }
        
        bool valid = true;
        for (int i = 0; i < m; ++i) {
            int match = 0;
            for (int x : q[i]) {
                for (int y : candidate) {
                    if (x == y) {
                        match++;
                        break;
                    }
                }
            }
            if (match != ans[i]) {
                valid = false;
                break;
            }
        }
        
        if (valid) {
            answer++;
        }
        
        int idx = 4;
        while (idx >= 0 && comb[idx] == n - 5 + idx) {
            idx--;
        }
        if (idx < 0) break;
        comb[idx]++;
        for (int i = idx + 1; i < 5; ++i) {
            comb[i] = comb[i - 1] + 1;
        }
    }
    
    return answer;
}