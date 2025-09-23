#include <iostream>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int y;
    cin >> y;
 
    if (y % 4 == 0) {
        if (y % 400 == 0) {  
            cout << 1;
        } 
        else if (y % 100 != 0) { 
            cout << 1;
        } 
        else {
            cout << 0;
        }
    } else {
        cout << 0;
    }
 
    return 0;
}