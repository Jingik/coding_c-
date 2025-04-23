#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> hq;
    for (const auto& val : scoville) {
        hq.push(val);
    }
    while (hq.size() >= 2 && hq.top() < K) {
        answer++;
        int num = hq.top();
        hq.pop();
        int num2 = hq.top();
        hq.pop();
        int num3 = num + (num2 * 2);
        hq.push(num3);
    }
    if (!hq.empty() && hq.top() >= K) return answer;

    return -1;
}