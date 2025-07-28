#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
int n;
int map[52][52]; 
int visit[52][52]; 
int dx[] = {0, 0, -1, 1}; 
int dy[] = {1, -1, 0, 0}; 
 
void bfs(){
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    visit[0][0] = 0; 
    while(!q.empty()){
        int x = q.front().first; 
        int y = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++){
            int nx = x + dx[i]; 
            int ny = y + dy[i]; 
            if(nx >=0 && nx < n && ny>=0 && ny <n){
                if(map[ny][nx] == 1){ 
                    if(visit[ny][nx] > visit[y][x]){
                        visit[ny][nx] = visit[y][x];
                        q.push(make_pair(nx, ny));
                    } 
                }else{ 
                    if(visit[ny][nx] > visit[y][x]+1){
                        visit[ny][nx] = visit[y][x]+1;
                        q.push(make_pair(nx, ny));
                    } 
                }
            }
        }  
    }     
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> n;
    char a;
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> a;
            map[i][j] = a - '0';
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            visit[i][j] = 987654321;
        }
    }
    bfs();
    cout << visit[n - 1][n - 1] << endl;
 
    return 0;
}