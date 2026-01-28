#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
ll check[250001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int N, X, num;
    cin >> N >> X;
    for(int i = 0; i < N; i++){
        cin >> num;
        if(i == 0)  {
            check[i] = num;
            continue;
        }
        check[i] = check[i - 1] + num;
    }
    ll maxval = check[X - 1];
    int cnt = 1;
    for(int i = X; i < N; i++){
        if(maxval < check[i] - check[i - X]){
            maxval = check[i] - check[i - X];
            cnt = 1;
        }
        else if(maxval == check[i] - check[i - X]){
            cnt += 1;
        }
    }
    if(maxval == 0){
        cout << "SAD";
    }
    else{
        cout << maxval << '\n' << cnt;
    }
}
