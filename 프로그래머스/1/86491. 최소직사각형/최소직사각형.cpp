#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;

    vector<int> row, col;

    for (const auto& size : sizes) {
        if (size[0] >= size[1]) {
            row.push_back(size[0]);
            col.push_back(size[1]);
        }
        else {
            row.push_back(size[1]);
            col.push_back(size[0]);
        }
    }
    answer = (*max_element(row.begin(), row.end())) * (*max_element(col.begin(), col.end()));
    
    return answer;
}