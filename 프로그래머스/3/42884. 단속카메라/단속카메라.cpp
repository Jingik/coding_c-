#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> routes) {
    sort(routes.begin(), routes.end(), [](const vector<int>& a, const vector<int>& b){
        return a[1] < b[1];
    });

    int answer = 0;
    int cam = -30001;

    for (auto& r : routes) {
        int in = r[0];
        int out = r[1];

        if (in <= cam && cam <= out) continue;
        else {
            cam = out;
            answer++;
        }
    }

    return answer;
}
