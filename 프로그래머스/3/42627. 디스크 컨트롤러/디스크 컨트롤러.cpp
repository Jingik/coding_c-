#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct Time {
    int time;
    int start;
    int index;
    // operator<(const Time& x){
    //     if(time != x.time){
    //         return time > x.time;
    //     }
    //     if(start != x.start){
    //         return start > x.start;
    //     }
    //     return index > x.index; 
    // }
};

struct Compare {
    bool operator()(const Time& x, const Time& y) {
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
    priority_queue<Time, vector<Time>, Compare> hq;

    int time = 0;
    int idx = 0;
    int total = 0;
    int count = jobs.size();

    while (idx < count || !hq.empty()) {
        while (idx < count && jobs[idx][0] <= time) {
            hq.push({ jobs[idx][1], jobs[idx][0], idx });
            idx++;
        }
        if (!hq.empty()) {
            Time job = hq.top(); hq.pop();
            time += job.time;
            total += (time - job.start);
        }
        else {
            time = jobs[idx][0];
        }
    }

    return total / count;
}