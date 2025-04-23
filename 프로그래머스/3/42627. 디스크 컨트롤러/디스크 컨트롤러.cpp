#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct Val{
    int index;
    int time;
    int start;
};

struct Compare {
    bool operator()(const Val& x, const Val& y) {
        if (x.time != y.time) {
            return x.time > y.time;
        }
        if (x.start != y.start) {
            return x.start > y.start;
        }
        return x.index > y.index;
    }
};

int solution(vector<vector<int>> jobs) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    sort(jobs.begin(), jobs.end());

    priority_queue<Val, vector<Val>, Compare> pq;
    int time = 0;
    int total = 0;
    int idx = 0;
    int count = jobs.size();

    while (idx < count || !pq.empty()) {
        while (idx < count && jobs[idx][0] <= time) {
            pq.push({ idx, jobs[idx][1], jobs[idx][0] });
            idx++;
        }

        if (!pq.empty()) {
            Val job = pq.top(); pq.pop();
            time += job.time;
            total += (time - job.start);
        }
        else {
            time = jobs[idx][0];
        }
    }

    return total / count;
}