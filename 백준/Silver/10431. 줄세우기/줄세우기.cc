#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int t, num;
    int member[20];
    cin >> t;

    while (t > 0) {
        int result = 0;
        t--;
        cin >> num;
        for (int i = 0; i < 20; i++) {
            cin >> member[i];
        }
        for (int i = 0; i < 20; i++) {
            for (int j = 1; j < 20 - i; j++) {
                if (member[j - 1] > member[j]) {
                    result++;
                    swap(member[j - 1], member[j]);
                }
            }
        }
        cout << num << " " << result << '\n';
    }

    return 0;
}
