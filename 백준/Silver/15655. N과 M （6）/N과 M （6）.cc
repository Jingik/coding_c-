#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int arr[10];
int path[10];
bool visited[10];

void func(int depth, int start) {
    if (depth == M) { 
        for (int i = 0; i < M; i++) {
            cout << path[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = start; i < N; i++) {
        path[depth] = arr[i]; 
        func(depth + 1, i+1);         
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr+N);
    func(0,0); 

    return 0;
}
