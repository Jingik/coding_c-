#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct leng{
    int row;
    int col;
};

bool compare(const leng& x, const leng& y){
    if(x.row != y.row){
        return x.row > y.row;
    }
    return x.col < y.col;
}

vector<int> solution(int brown, int yellow) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int ro_co = brown + yellow;
    vector<leng> dir;
    
    vector<int> answer;
    for(int i = 1; i < ro_co; i++){
        if(ro_co % i == 0){
            dir.push_back({i, (ro_co / i) });
        }
    }
    sort(dir.begin(),dir.end(), compare);
    for(auto& sam : dir){
        if((sam.row * sam.col) == ro_co && (sam.row * 2) + ((sam.col - 2) * 2) == brown){
            answer.push_back(sam.row);
            answer.push_back(sam.col);
            return answer;
        }
    }
    return answer;
}