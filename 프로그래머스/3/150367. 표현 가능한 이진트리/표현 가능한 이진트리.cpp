#include <string>
#include <vector>

using namespace std;

bool isValidTree(const string& binary, int left, int right, bool parentValid) {
    if (left > right) return true;
    
    int mid = (left + right) / 2;
    if (!parentValid && binary[mid] == '1') return false;
    
    bool leftValid = isValidTree(binary, left, mid - 1, binary[mid] == '1');
    bool rightValid = isValidTree(binary, mid + 1, right, binary[mid] == '1');
    
    return leftValid && rightValid;
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    
    for (long long num : numbers) {
        string binary = "";
        while (num > 0) {
            binary = (num % 2 == 0 ? "0" : "1") + binary;
            num /= 2;
        }
        
        int len = binary.size();
        int h = 0;
        while ((1LL << h) - 1 < len) h++;
        int fullSize = (1 << h) - 1;
        while (binary.size() < fullSize) binary = "0" + binary;
        
        answer.push_back(isValidTree(binary, 0, binary.size() - 1, true) ? 1 : 0);
    }
    
    return answer;
}