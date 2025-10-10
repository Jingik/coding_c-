#include <string>
#include <vector>
#include <set>
using namespace std;

bool MatchCard(set<int>& A, set<int>& B, int target){
    for(auto& x : A){
        auto it = B.find(target - x);
        if(it != B.end()){
            A.erase(x);
            B.erase(*it);
            return true;
        }
    }
    return false;
}

int solution(int coin, vector<int> cards) {
    int answer = 1, card_size = cards.size();
    set<int> hands, draws;
    
    for(int i = 0; i < card_size / 3; i++){
        hands.insert(cards[i]);
    }

    for(int i = card_size / 3; i < card_size; i += 2){
        draws.insert(cards[i]);
        draws.insert(cards[i + 1]);
        if (MatchCard(hands, hands, card_size + 1)){

        }
        else if (coin >= 1 && MatchCard(hands, draws, card_size + 1)){
            coin -= 1;
        }
        else if (coin >= 2 && MatchCard(draws, draws, card_size + 1)){
            coin -= 2;
        }
        else break;
        answer++;
    }
    
    return answer;
}