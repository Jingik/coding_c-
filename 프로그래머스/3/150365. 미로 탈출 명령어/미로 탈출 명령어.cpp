#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int dx[] = {1, 0, 0, -1};
int dy[] = {0, -1, 1, 0};
char dir[] = {'d', 'l', 'r', 'u'};

int N, M, X, Y, R, C;
bool found = false;
string answer = "";

void dfs(int idx, int k, int x, int y, string cur){
    if(found) return;
    
    if(idx == k){
        if(x == R && y == C){
            answer = cur;
            found = true;
        }
        return;
    }
    
    int distance = abs(x - R) + abs(y - C);    
    if(idx >= k || distance > k - idx || (k - idx - distance) % 2 != 0) return;
    
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i], ny = y + dy[i];
        if(nx > 0 && nx <= N && ny > 0 && ny <= M){
            dfs(idx + 1, k, nx, ny, cur + dir[i]);            
        }
    }
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    N = n, M = m, X = x, Y = y, R = r, C = c;
    
    int distance = abs(x - r) + abs(y - c);
    if(distance > k || (k - distance) % 2 != 0) return "impossible";
    
    dfs(0, k, x, y, "");
    if (!answer.empty()){
        return answer;        
    }
    else return "impossible";
}