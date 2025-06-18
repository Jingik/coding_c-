#include <iostream>

using namespace std;

bool isHansu(int n) {
    if (n < 100) { 
        return true;
    } else if (n >= 100 && n < 1000) { 
        int hun = n / 100; 
        int ten = (n / 10) % 10; 
        int one = n % 10; 

        if ((hun - ten) == (ten - one)) {
            return true;
        } else {
            return false;
        }
    }
    return false; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin >> N;

    int hansuCount = 0;
    for (int i = 1; i <= N; ++i) {
        if (isHansu(i)) {
            hansuCount++;
        }
    }

    cout << hansuCount << endl;

    return 0;
}