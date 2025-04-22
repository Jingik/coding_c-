#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<string, int> type_count;

    for (const vector<string>& item : clothes) {
        const string& name = item[0];
        const string& type = item[1];
        type_count[type]++;
    }

    int answer = 1;
    
    for (const auto& [type, count] : type_count) {
        answer *= (count + 1);
    }

    return answer - 1;
}
