#include <vector>
#include <algorithm>

using namespace std;

bool Sort(vector<int>& A, vector<int>&B){
    if(A[1] == B[1]){
        return A[0] < B[0];
    }
    return A[1] < B[1];
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