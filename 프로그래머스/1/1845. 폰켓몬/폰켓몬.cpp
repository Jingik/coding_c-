#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

int solution(vector<int> nums)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int choice = nums.size() / 2;
    unordered_set<int> check(nums.begin(), nums.end());
    
    int answer = 0;
    if (choice > check.size()) {
        answer = check.size();
    }
    else {
        answer = choice;
    }


    return answer;
}