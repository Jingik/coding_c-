#include<vector>
#include<queue>
using namespace std;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

struct Dir{
    int x;
    int y;
};

bool valid(int x, int y, int n, int m) {
    return 0 <= x && x < m && 0 <= y && y < n;
}

int BFS(Dir start, vector<vector<int>>& maps){
    int n = maps.size();
    int m = maps[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));
    queue<Dir> que;
    que.push(start);
    visited[start.y][start.x] = 1;

    while(!que.empty()){
        Dir cur = que.front(); que.pop();
        for(int i = 0; i < 4; i++){
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if(valid(nx, ny, n, m) && !visited[ny][nx] && maps[ny][nx] == 1){
                visited[ny][nx] = visited[cur.y][cur.x] + 1;
                que.push({nx, ny});
            }
        }
    }

    return visited[n-1][m-1] == 0 ? -1 : visited[n-1][m-1];
}

int solution(vector<vector<int>> maps)
{
    
    int answer = 0;
    Dir start = {0,0};
    answer = BFS(start, maps);
    
    return answer;
}