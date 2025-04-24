#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    vector<vector<int>> graph(n + 1);
    vector<int> dist(n + 1, -1);  

    for (auto& e : edge) {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }

    queue<int> q;
    q.push(1);
    dist[1] = 0;
    
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(auto ncur : graph[cur]){
            if(dist[ncur] == -1){
                dist[ncur] = dist[cur] + 1;
                q.push(ncur);
            }
        }
    }
    int max_dist = *max_element(dist.begin(), dist.end());
    return count(dist.begin(), dist.end(), max_dist);
}
