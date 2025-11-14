#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main(){
    int n;
    string key, value;
    map<string, string, greater<string>> m;
    vector<string> v;
    
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> key >> value;
        if(value == "enter") m.insert(make_pair(key, value));
        else m.erase(key);
    }
    
    for(auto it : m){
      cout << it.first << "\n";
    }
    
    return 0;
}