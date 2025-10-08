#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer;
    int max_edge = 0;
    for(const auto& edge : edges){
        max_edge = max(max_edge, edge[0]);
        max_edge = max(max_edge, edge[1]);
    }
    
    vector<int>outDeg(max_edge + 1);
    vector<int>inDeg(max_edge + 1);
    
    for(const auto& edge : edges){
        outDeg[edge[0]]++;
        inDeg[edge[1]]++;
    }
    
    int total_graph = 0;
    int root = 0;
    for(int i = 1; i < max_edge + 1; i++){
        if(outDeg[i] >= 2 && inDeg[i] == 0){
            root = i;
            total_graph = outDeg[i];
            break;
        }
    }
    
    int boards_graph = 0;
    for(int i = 1; i < max_edge + 1; i++){
        if(inDeg[i] > 0 && outDeg[i] == 0){
            boards_graph++;
        }
    }
    
    int eight_graph = 0;
    for(int i = 1; i < max_edge + 1; i++){
        if(inDeg[i] > 1 && outDeg[i] > 1){
            eight_graph++;
        }
    }
    
    int do_graph = total_graph - boards_graph - eight_graph;
    return {root, do_graph, boards_graph, eight_graph};
}