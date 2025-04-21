#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer; 
    for (auto& x : commands) {
        int start = x[0] - 1;
        int end = x[1];
        int target = x[2] - 1;

        vector<int> sample(array.begin() + start, array.begin() + end);

        sort(sample.begin(), sample.end());
        answer.push_back(sample[target]);
    }
    return answer;
}