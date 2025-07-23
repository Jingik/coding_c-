#include <iostream>
#include <cstring>
#include <queue>
#include <string>
#define MAX 10000

using namespace std;

bool isPrime[MAX];
bool visited[MAX];
int startNum, endNum;

void initialize() {
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i < MAX; ++i) {
        if (!isPrime[i]) continue;
        for (int j = i * i; j < MAX; j += i) {
            isPrime[j] = false;
        }
    }
    memset(visited, false, sizeof(visited));
}

void findMinTransformation() {
    queue<pair<int, int>> q;
    q.push({startNum, 0});
    visited[startNum] = true;

    while (!q.empty()) {
        int current = q.front().first;
        int count = q.front().second;
        q.pop();

        if (current == endNum) {
            cout << count << endl;
            return;
        }

        string curStr = to_string(current);
        for (int i = 0; i < 4; ++i) {
            for (char d = '0'; d <= '9'; ++d) {
                string nextStr = curStr;
                nextStr[i] = d;
                int nextNum = stoi(nextStr);

                if (nextNum < 1000 || !isPrime[nextNum] || visited[nextNum])
                    continue;

                visited[nextNum] = true;
                q.push({nextNum, count + 1});
            }
        }
    }

    cout << "Impossible" << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int T;
    cin >> T;
    
    while (T--) {
        initialize();
        cin >> startNum >> endNum;
        findMinTransformation();
    }

    return 0;
}
