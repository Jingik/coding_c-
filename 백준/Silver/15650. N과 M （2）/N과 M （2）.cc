#include <iostream>
using namespace std;

int N, M;          
int path[10];       

void func(int depth, int now) {
    if (depth >= M) {
        for (int i = 0; i < M; i++) {
            cout << path[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int i = now; i <= N; i++) {
        path[depth] = i;
        func(depth + 1, i + 1);
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);             

    cin >> N >> M;               
    func(0, 1);

    return 0;
}
