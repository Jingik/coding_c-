#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> best;
int maxDiff;
vector<int> info_global;

void dfs(int idx, int arrows, vector<int>& ryan) {
    if (idx == 10) {
        ryan[10] = arrows;
        int apeach = 0, lion = 0;
        for (int i = 0; i < 11; ++i) {
            if (info_global[i] == 0 && ryan[i] == 0) continue;
            if (info_global[i] >= ryan[i]) apeach += 10 - i;
            else lion += 10 - i;
        }
        int diff = lion - apeach;
        if (diff > maxDiff) {
            maxDiff = diff;
            best = ryan;
        } else if (diff == maxDiff && diff > 0) {
            for (int i = 10; i >= 0; --i) {
                if (ryan[i] > best[i]) { best = ryan; break; }
                if (ryan[i] < best[i]) break;
            }
        }
        ryan[10] = 0;
        return;
    }
    if (arrows > info_global[idx]) {
        ryan[idx] = info_global[idx] + 1;
        dfs(idx + 1, arrows - ryan[idx], ryan);
        ryan[idx] = 0;
    }
    dfs(idx + 1, arrows, ryan);
}

vector<int> solution(int n, vector<int> info) {
    best = vector<int>();
    maxDiff = -1;
    info_global = info;
    vector<int> ryan(11, 0);
    dfs(0, n, ryan);
    return maxDiff > 0 ? best : vector<int>{-1};
}