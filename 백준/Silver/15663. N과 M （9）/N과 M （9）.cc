#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int input[10];
int ans[10];
bool isUsed[10];

void func(int L){
    if (L == M){
        for (int i = 0; i < M; i++) cout << ans[i] << ' ';
        cout << '\n';
        return;
    }

    int tmp = -1;
    for (int i = 0; i < N; i++){
        if (!isUsed[i] && tmp != input[i]){
            ans[L] = input[i];
            tmp = input[i];
            isUsed[i] = true;
            func(L + 1);
            isUsed[i] = false;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> input[i];
    sort(input, input + N);

    func(0);
    return 0;
}
