#include <iostream>
#include <queue>
#include <vector>

using namespace std;
 
int F, S, G, U, D;
const int MAX = 1000001;
int path[MAX];
bool visited[MAX];
vector<int> dx;
queue<int> q;
 
void BFS(int v) {
    visited[v] = true;
    q.push(v);
 
    while (!q.empty()) {
        v = q.front();
        q.pop(); 
        
        for (int i = 0; i < 2; i++) {
            int nv = v + dx[i];
 
            if (0 < nv && nv <= F) {
                if (!visited[nv]) {
                    visited[nv] = true;
                    q.push(nv);
                    path[nv] = path[v] + 1;
                }
            }
        }
        
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> F >> S >> G >> U >> D;
 
    dx.push_back(U);
    dx.push_back(D * -1);
 
    BFS(S);
 
    if (visited[G]) {
        cout << path[G];
    }
    else {
        cout << "use the stairs";
    }
}