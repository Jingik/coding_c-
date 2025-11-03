#include <bits/stdc++.h>
using namespace std;

const int MAX = 26;
int leftChild[MAX], rightChild[MAX];

void preorder(int idx) {
    if (idx == -1) return;
    cout << (char)(idx + 'A');
    preorder(leftChild[idx]);
    preorder(rightChild[idx]);
}

void inorder(int idx) {
    if (idx == -1) return;
    inorder(leftChild[idx]);
    cout << (char)(idx + 'A');
    inorder(rightChild[idx]);
}

void postorder(int idx) {
    if (idx == -1) return;
    postorder(leftChild[idx]);
    postorder(rightChild[idx]);
    cout << (char)(idx + 'A');
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin >> N;

    for (int i = 0; i < MAX; i++) {
        leftChild[i] = rightChild[i] = -1;
    }

    for (int i = 0; i < N; i++) {
        char p, l, r;
        cin >> p >> l >> r;
        int idx = p - 'A';
        leftChild[idx] = (l == '.') ? -1 : l - 'A';
        rightChild[idx] = (r == '.') ? -1 : r - 'A';
    }

    preorder(0);   cout << '\n';
    inorder(0);    cout << '\n';
    postorder(0);  cout << '\n';

    return 0;
}