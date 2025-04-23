#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(string word) {
    vector<char> vowels = {'A', 'E', 'I', 'O', 'U'};
    int weights[5] = {781, 156, 31, 6, 1}; 
    unordered_map<char, int> indexMap = {{'A', 0}, {'E', 1}, {'I', 2}, {'O', 3}, {'U', 4}};
    
    int answer = 0;
    for (int i = 0; i < word.length(); ++i) {
        answer += weights[i] * indexMap[word[i]] + 1;
    }
    
    return answer;
}
