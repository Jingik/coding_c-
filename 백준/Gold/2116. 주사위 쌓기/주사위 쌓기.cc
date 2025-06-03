#include <iostream>
#include <algorithm>
using namespace std;

int N;
int dice[10001][6]; 
int opposite[6] = { 5, 3, 4, 1, 2, 0 }; 

int getMaxSide(int idx, int bottom, int top) {
    int maxVal = 0;
    for (int i = 0; i < 6; i++) {
        if (i == bottom || i == top) continue;
        maxVal = max(maxVal, dice[idx][i]);
    }
    return maxVal;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < 6; j++)
            cin >> dice[i][j];

    int answer = 0;

    for (int firstBottom = 0; firstBottom < 6; firstBottom++) {
        int sum = 0;
        int bottomIdx = firstBottom;
        int topIdx = opposite[bottomIdx];
        int topNum = dice[0][topIdx];
        sum += getMaxSide(0, bottomIdx, topIdx);

        for (int i = 1; i < N; i++) {
            for (int j = 0; j < 6; j++) {
                if (dice[i][j] == topNum) {
                    bottomIdx = j;
                    topIdx = opposite[j];
                    topNum = dice[i][topIdx];
                    sum += getMaxSide(i, bottomIdx, topIdx);
                    break;
                }
            }
        }
        answer = max(answer, sum);
    }

    cout << answer << '\n';
    return 0;
}
