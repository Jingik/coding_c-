#include <iostream>
#include <algorithm>
using namespace std;
string num;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> num;
    sort(num.begin(), num.end(), greater<char>());
    cout << num;
    return 0;
}