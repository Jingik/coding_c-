#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool check(int& mid, const vector<int>& citiations) {
    int check = 0;
    for (const auto& x : citiations) {
        if (mid <= x) {
            check++;
        }
        else break;
    }
    return check >= mid;
}

int solution(vector<int> citations) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    sort(citations.begin(), citations.end(),greater<>());
    int start = 0, end = *max_element(citations.begin(), citations.end());
    int answer = 0;
    while (start < end) {
        int mid = (start + end) / 2;
        if (!check(mid, citations)) {
            end--;
        }
        else {
            if(answer < mid) answer = mid;
            start++;
        }
    }
    return answer;
}