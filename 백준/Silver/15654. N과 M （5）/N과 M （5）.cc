#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
//vector<int> arr;
int arr[10];
int path[10];
bool visited[10];

void func(int depth) {
    if (depth == M) { 
        for (int i = 0; i < M; i++) {
            cout << path[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < N; i++) {
        if (visited[i]) continue; 

        visited[i] = true;     
        path[depth] = arr[i]; 
        func(depth + 1);         
        visited[i] = false;     
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    //arr.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    //sort(arr.begin(), arr.end());
    sort(arr, arr + N);
    func(0); 

    return 0;
}
