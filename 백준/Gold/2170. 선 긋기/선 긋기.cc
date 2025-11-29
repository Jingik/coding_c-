#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> val;

int N;
vector<val> lines;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for (int i=0; i<N; i++) {
        int s, e;
        cin >> s >> e;
        lines.push_back({s, e});
    }
    
    sort(lines.begin(), lines.end());
    
    int s = -1e9, e = -1e9;      
    int len = 0;
    
    for (int i=0; i<N; i++) {
        if (lines[i].first > e) {  
            len += e-s;
            s = lines[i].first;
            e = lines[i].second;
        }
        else {                
            e = max(e, lines[i].second);
        }
    }
    len += e-s;
    
    cout << len;

    return 0;
}