#include <vector>
#include <algorithm>

using namespace std;

bool Sort(vector<int>& a, vector<int>& b){
    return a[1] < b[1] || (a[1] == b[1] && a[0] < b[0]);
}

int solution(vector<vector<int>> targets) {
    int answer = 0;
    sort(targets.begin(), targets.end(), Sort);
    
    int last = -1;
    for (auto& target : targets) {
        int s = target[0], e = target[1];
        if (s >= last) {
            answer++;
            last = e;
        }
    }
    
    return answer;
}