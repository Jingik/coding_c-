#include<iostream>

using namespace std;

int a[100][100];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, x, y, cnt=0;
    cin >> n;
    
    while(n--){
        cin >> x >> y;
        for(int i = y; i < y + 10; i++){
            for(int j = x; j < x + 10; j++){
                if(!a[i][j]){
                    cnt++;
                    a[i][j]=1;
                }
            }
        }
    }
    cout << cnt << '\n';
}