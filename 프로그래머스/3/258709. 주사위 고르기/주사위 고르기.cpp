#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

void dfs(int idx, int currSum, const vector<vector<int>>& dice, const vector<int>& selected, vector<int>& sums) {
    if (idx == selected.size()) {
        sums.push_back(currSum);
        return;
    }
    for (int face : dice[selected[idx]]) {
        dfs(idx + 1, currSum + face, dice, selected, sums);
    }
}

void calculateSums(const vector<vector<int>>& dice, const vector<int>& selected, vector<int>& sums) {
    sums.clear(); 
    dfs(0, 0, dice, selected, sums); 
}

long long countWins(const vector<int>& aSums, const vector<int>& bSums) {
    long long wins = 0;
    for (int a : aSums) {
        for (int b : bSums) {
            if (a > b) wins++; 
        }
    }
    return wins;
}

vector<int> solution(vector<vector<int>> dice) {
    int n = dice.size();
    int half = n / 2;
    vector<int> answer;
    long long maxWins = -1;

    vector<int> indices(n);
    for (int i = 0; i < n; ++i) indices[i] = i;

    vector<bool> comb(n, false);
    fill(comb.begin(), comb.begin() + half, true);

    do {
        vector<int> aIndices, bIndices;
        for (int i = 0; i < n; ++i) {
            if (comb[i]) aIndices.push_back(i);
            else bIndices.push_back(i);
        }

        vector<int> aSums, bSums;
        calculateSums(dice, aIndices, aSums);
        calculateSums(dice, bIndices, bSums);

        long long wins = countWins(aSums, bSums);

        if (wins > maxWins) {
            maxWins = wins;
            answer = aIndices;
        }
    } while (prev_permutation(comb.begin(), comb.end()));

    for (int& x : answer) x += 1;
    return answer;
}