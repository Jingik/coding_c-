#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {

    sort(people.begin(), people.end());
    int answer = 0;
    int n = people.size();
    
    int left = 0, right = people.size() - 1;
    
    while(left < right){
        int num = people[left] + people[right];
        if(num <= limit){
            answer++; left++; right--;
        }
        else{
            answer++; right--;
        }
        if(left == right){
            answer++;
            break;
        }
    }
    return answer;
}