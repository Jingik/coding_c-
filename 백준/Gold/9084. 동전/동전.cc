#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n, m, t;
    cin >> t;
    
    while(t--){
        int dp[10001] = {0, };
        int arr[20] = {0, };
        
        cin >> n;
        
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        
        cin >> m;
        
        dp[0] = 1;
        
        for(int i = 0; i < n; i++){
            for(int j = arr[i]; j <= m; j++){
                dp[j] += dp[j - arr[i]];
            }
        }
        
        cout << dp[m] << "\n";
    }
    
    return 0;
}