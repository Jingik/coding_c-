#include <string>
#include <vector>

using namespace std;

int total = 0;

void DFS(vector<int> numbers, int target, int cur, int count){
    if(count >= numbers.size()){
        if(target == cur){
            total ++;
        }
        return; 
    }
    DFS(numbers, target, cur + numbers[count], count + 1);
    DFS(numbers, target, cur - numbers[count], count + 1);
}

int solution(vector<int> numbers, int target) {
    
    DFS(numbers, target, numbers[0], 1);
    DFS(numbers, target, -numbers[0], 1);
    return total;
}