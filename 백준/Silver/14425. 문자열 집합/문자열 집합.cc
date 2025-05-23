#include <iostream>
#include <map>
using namespace std;
map<string, bool> m;
int N, M;
string str;
int res = 0;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		m.insert(pair<string, bool>(str, true));
	}

	for (int i = 0; i < M; i++)
	{
		cin >> str;
		if (m[str]==true)
			res++;
	}
	cout << res;

}