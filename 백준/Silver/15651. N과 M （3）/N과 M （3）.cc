#include <iostream>
#include <vector>
using namespace std;

int N, M;           
int path[10];       

void func(int depth) {
    if (depth == M) { 
        for (int i = 0; i < M; i++) {
            cout << path[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= N; i++) {
        path[depth] = i; 
        func(depth + 1); 
    }
}

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL);           

    cin >> N >> M;
    func(0);

    return 0;
}
