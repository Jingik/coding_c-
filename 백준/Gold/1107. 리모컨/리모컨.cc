#include <iostream>
#include <string>

using namespace std;

int btn[10] = {
    0,
};


bool btn_set(int n)
{
    string str_n = to_string(n);
    for (int i = 0; i < str_n.length(); i++)
    {
        if (btn[str_n[i] - '0'] == 1)
            return false;
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int N, M;
    
    cin >> N >> M;
    
    int ch = 100;
    int ans;

    for (int i = 0; i < M; i++)
    {
        int btn_number;
        cin >> btn_number;
        btn[btn_number] = 1;
    }

    int cnt = abs(ch - N);
	
    for (int i = 0; i <= 1000000; i++)
    {
        if (btn_set(i) == true)
        {
            int second_cnt = abs(N - i) + to_string(i).length();
            cnt = min(cnt, second_cnt);
        }
    }
    cout << cnt;

    return 0;
}