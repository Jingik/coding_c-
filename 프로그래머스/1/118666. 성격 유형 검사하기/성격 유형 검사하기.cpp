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
    
    for(int i = 0; i < survey.size(); i++) {
        char disagree = survey[i][0];
        char agree = survey[i][1];
        int choice = choices[i];
        
        if(choice < 4) {
            scores[disagree] += (4 - choice);
        } else if(choice > 4) {
            scores[agree] += (choice - 4);
        }
    }
    
    vector<vector<char>> type = {{'R', 'T'}, {'C', 'F'}, {'J', 'M'}, {'A', 'N'}};
    
    for(int i = 0; i < 4; i++) {
        char type1 = type[i][0];
        char type2 = type[i][1];
        
        if(scores[type1] >= scores[type2]) {
            answer += type1;
        } else {
            answer += type2;
        }
    }
    
    return answer;
}