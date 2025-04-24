#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long left = 0;
    long long right = 1LL * (*max_element(times.begin(), times.end())) * n;
    long long answer = right;
    
    while(left <= right){
        long long mid = (right + left) / 2;
        long long people = 0;
        for(auto time : times){
            people += mid / time;
        }
        
        if(people >= n){
            answer = mid;
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    return answer;
}
