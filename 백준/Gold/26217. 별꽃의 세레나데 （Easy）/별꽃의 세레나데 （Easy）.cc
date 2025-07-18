#include <iostream>
#include <algorithm>

using namespace std;
double harmonic(double n){
    double sum = 0;
    for(double i = 1; i < n+1; i++){
        sum += 1/i;
    }
    return sum;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    double n, ans;
    cin >> n;
    ans = n * harmonic(n);
    cout << ans;
    return 0;
    }