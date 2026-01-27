#include <iostream>
#include <algorithm>

#define MAX 2223
#define INF 1e9
using namespace std;

int N;

int q[MAX][MAX];
int cache[MAX][MAX];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j<= N; j++){
            cin >> q[i][j];
        }
    }
    
    for(int k = 3; k <= N + N; k++){
        for(int i = 1; i <= k; i++){
            int j = k - i;
            if(i > N || j > N) continue;
            
            int up = INF, left = INF;
            if(j - 1 > 0){
                int cost = (q[i][j-1] - q[i][j] > 0 ? 0 :q[i][j] - q[i][j-1] + 1);
                left = min(left, cost + cache[i][j-1]);
            }
            if(i - 1 > 0){
                int cost = (q[i-1][j] - q[i][j] > 0 ? 0 :q[i][j] - q[i-1][j] + 1);
                up = min(up, cost + cache[i-1][j]);
            }
            cache[i][j] = min(up, left);
        }
    }
    cout << cache[N][N];
    
    return 0;
}