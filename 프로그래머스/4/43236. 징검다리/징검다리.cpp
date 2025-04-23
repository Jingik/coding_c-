#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    sort(rocks.begin(), rocks.end());
    rocks.push_back(distance);

    int left = 1, right = distance;
    int answer = 0;

    while (left <= right) {
        int mid = (left + right) / 2;
        int removed = 0;
        int prev = 0;

        for (int i = 0; i < rocks.size(); ++i) {
            int gap = rocks[i] - prev;
            if (gap < mid) {
                removed++;
            } else {
                prev = rocks[i];
            }
        }

        if (removed > n) {
            right = mid - 1;
        } else {
            answer = mid;
            left = mid + 1;
        }
    }

    return answer;
}
