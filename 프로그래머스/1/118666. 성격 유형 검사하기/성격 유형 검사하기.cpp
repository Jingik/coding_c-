#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    unordered_map<char, int> scores;
    scores['R'] = 0; scores['T'] = 0;
    scores['C'] = 0; scores['F'] = 0;
    scores['J'] = 0; scores['M'] = 0;
    scores['A'] = 0; scores['N'] = 0;
    
    for(int i = 0; i < survey.size(); i++){
        char disagree = survey[i][0];
        char agree = survey[i][1];
        int score = choices[i];
        
        if(score < 4){
            scores[disagree] += (4 - score);
        }
        else{
            scores[agree] += (score - 4) ;
        }
    }
    vector<vector<char>> type = {{'R', 'T'}, {'C', 'F'}, {'J', 'M'}, {'A', 'N'}};
    
    for(int i = 0; i < 4; i++){
        int A = scores[type[i][0]], B = scores[type[i][1]];
        if(A >= B) answer+= type[i][0];
        else answer += type[i][1];
    }
    
    
    return answer;
}