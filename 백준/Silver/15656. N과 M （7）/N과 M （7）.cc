#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N, M;
int arr[10];
string result;

void func(int depth, string current) {
    if (depth == M) {
        result += current + "\n"; 
        return;
    }

    for (int i = 0; i < N; i++) {
        func(depth + 1, current + to_string(arr[i]) + " "); 
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + N); 
    func(0, "");       

    cout << result;    
    return 0;
}
