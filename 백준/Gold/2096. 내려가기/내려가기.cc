#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::vector;
using std::min;
using std::max;

int dp[3];
char input[100'001][3];

int main(void){
    std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;

    for(int i=0;i<N;i++){
        cin >> input[i][0] >> input[i][1] >> input[i][2];
        input[i][0] -= '0';
        input[i][1] -= '0';
        input[i][2] -= '0';
    }

    dp[0] = input[N-1][0];
    dp[1] = input[N-1][1];
    dp[2] = input[N-1][2];

    int temp1, temp2, temp3;

    for(int i=N-2;i>=0;i--){
        temp1 = input[i][0] + max({dp[0], dp[1]});
        temp2 = input[i][1] + max({dp[0], dp[1], dp[2]});
        temp3 = input[i][2] + max({dp[1], dp[2]});

        dp[0] = temp1;
        dp[1] = temp2;
        dp[2] = temp3;
    }

    int _max = max({dp[0], dp[1], dp[2]});

    dp[0] = input[N-1][0];
    dp[1] = input[N-1][1];
    dp[2] = input[N-1][2];

    for(int i=N-2;i>=0;i--){
        temp1 = input[i][0] + min({dp[0], dp[1]});
        temp2 = input[i][1] + min({dp[0], dp[1], dp[2]});
        temp3 = input[i][2] + min({dp[1], dp[2]});

        dp[0] = temp1;
        dp[1] = temp2;
        dp[2] = temp3;
    }

    int _min = min({dp[0], dp[1], dp[2]});

    cout << _max << " " << _min << "\n";

    return 0;
}