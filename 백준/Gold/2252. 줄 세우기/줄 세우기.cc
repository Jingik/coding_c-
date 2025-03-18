#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

int n, m; 
vector<int> inDegree, result;
vector<vector<int>> graph; 

void input(){
    cin >> n >> m;
    inDegree.assign(n + 1, 0);
    result.assign(n + 1, 0);
    graph.assign(n + 1, vector<int>(0, 0));

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        graph[a].emplace_back(b);
        inDegree[b]++;
    }
}

void tp_sort(){
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(inDegree[i] == 0)    q.push(i);
    }

    for(int i = 0; i < n; i++){
        if(q.empty())   return;
        int cur = q.front(); 
        result[i] = cur; 
        q.pop();

        for(int k = 0; k < graph[cur].size(); k++){
            int next = graph[cur][k];
            if(--inDegree[next] == 0)   q.push(next);
        }
    }
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    tp_sort();

    for(int i = 0; i < n; i++){
        cout << result[i] << " ";
    }

    return 0;
}