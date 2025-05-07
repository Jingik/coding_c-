#include <iostream>
#include <algorithm>

using namespace std;

int N;
int num[11];
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> s;
    for(int i=0;i<s.length();i++)
        num[s[i]-48]++;
    int sixnine = (num[6] + num[9] +1)/2;
    num[6]=num[9]=sixnine;
    cout << *max_element(num,num+11);
}