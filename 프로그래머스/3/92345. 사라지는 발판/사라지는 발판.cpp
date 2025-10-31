#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Point { int x, y; };
vector<vector<int>> map;
int n, m;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int dfs(Point me, Point you) {
    if (map[me.x][me.y] == 0) return 0;
    
    int result = 0;
    for (int i = 0; i < 4; i++) {
        int nx = me.x + dx[i], ny = me.y + dy[i];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m || map[nx][ny] == 0) continue;
        
        map[me.x][me.y] = 0;
        int val = dfs(you, {nx, ny}) + 1;
        map[me.x][me.y] = 1;
        
        if (val % 2 == 1 && result % 2 == 0) result = val;
        else if (val % 2 == 0 && result % 2 == 0) result = max(result, val);
        else if (val % 2 == 1 && result % 2 == 1) result = min(result, val);
    }
    return result;
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    map = board;
    n = board.size();
    m = board[0].size();
    return dfs({aloc[0], aloc[1]}, {bloc[0], bloc[1]});
}