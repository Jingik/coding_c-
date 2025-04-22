#include <string>
#include <vector>
#include <iostream>
#include <deque>
using namespace std;
struct value{
    int wt;
    int time;
};

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    deque<value> que;
    deque<int> weights(truck_weights.begin(), truck_weights.end());

    que.push_back({truck_weights[0], 1});
    int total_weight = que.front().wt;
    int answer = 1;
    int idx = 1;

    while (!que.empty()) {
        answer++;

        if (que.front().time == bridge_length) {
            total_weight -= que.front().wt;
            que.pop_front();
        }

        if (idx < weights.size()) {
            int cur_weight = weights[idx];
            if ((total_weight + cur_weight) <= weight && que.size() <= bridge_length) {
                que.push_back({ cur_weight, 0 });
                idx++;
                total_weight += cur_weight;
            }
        }

        for (auto& cur : que) {
            cur.time += 1;
        }
    }

    return answer;
}