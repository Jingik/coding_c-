#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N, M;

void dfs(int cnt, string num) {
    if (cnt == M) {
        cout << num << "\n";
        return;
    }
    for (int i = 1; i < N; i++) {
        dfs(cnt + 1, num + " " + to_string(i));
    }
}

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    cin >> N >> M;
    N += 1;

    for (int i = 1; i < N; i++) {
        dfs(1, to_string(i));
    }
    
    return 0;
}