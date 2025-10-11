#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    queue<long long> q1, q2;
    long long sum1 = 0, sum2 = 0;
    long long total = 0;
    
    for (int x : queue1) {
        q1.push(x);
        sum1 += x;
    }
    for (int x : queue2) {
        q2.push(x);
        sum2 += x;
    }
    total = sum1 + sum2;
    
    if (total % 2 != 0) return -1;
    
    long long target = total / 2;
    int answer = 0;
    int max_operations = queue1.size() * 3;
    
    while (sum1 != sum2 && answer <= max_operations) {
        if (sum1 > sum2) {
            long long cur = q1.front();
            q1.pop();
            q2.push(cur);
            sum1 -= cur;
            sum2 += cur;
        } else {
            long long cur = q2.front();
            q2.pop();
            q1.push(cur);
            sum2 -= cur;
            sum1 += cur;
        }
        answer++;
    }
    
    return (sum1 == sum2) ? answer : -1;
}