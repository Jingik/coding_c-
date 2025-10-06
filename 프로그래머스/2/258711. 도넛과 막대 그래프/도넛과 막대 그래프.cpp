#include <string>
#include <vector>
#include <algorithm> 

using namespace std;

vector<int> solution(vector<vector<int>> edges) {
    int maxV = 0;
    for (const auto& e : edges) {
        maxV = max(maxV, max(e[0], e[1]));
    }
    
    vector<int> inDeg(maxV + 1, 0);
    vector<int> outDeg(maxV + 1, 0);
    
    for (const auto& e : edges) {
        int a = e[0], b = e[1];
        outDeg[a]++;
        inDeg[b]++;
    }
    
    int root = -1;
    int totalGraphs = 0;
    for (int i = 1; i <= maxV; ++i) {
        if (inDeg[i] == 0 && outDeg[i] >= 2) {
            root = i;
            totalGraphs = outDeg[i];
            break;
        }
    }
    
    int barCount = 0;
    for (int i = 1; i <= maxV; ++i) {
        if (outDeg[i] == 0 && inDeg[i] != 0) {
            barCount++;
        }
    }

    int eightCount = 0;
    for (int i = 1; i <= maxV; ++i) {
        if (inDeg[i] >= 2 && outDeg[i] >= 2) {
            eightCount++;
        }
    }
    
    int donutCount = totalGraphs - barCount - eightCount;
    
    return {root, donutCount, barCount, eightCount};
}