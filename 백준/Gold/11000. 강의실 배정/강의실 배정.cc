#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> Lecture;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin >> N;

    vector<Lecture> lectures(N);
    for (int i = 0; i < N; ++i) {
        cin >> lectures[i].first >> lectures[i].second;
    }

    sort(lectures.begin(), lectures.end());

    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(lectures[0].second);

    for (int i = 1; i < N; ++i) {
        int start = lectures[i].first;
        int end = lectures[i].second;

        if (pq.top() <= start) {
            pq.pop();
        }

        pq.push(end);
    }

    cout << pq.size() << '\n'; 
    return 0;
}
