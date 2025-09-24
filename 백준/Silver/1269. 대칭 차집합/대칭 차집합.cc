#include <iostream>
#include <map>
using namespace std;
map<int, bool> m;
int N,M;
int num;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
	cin >> N >> M;
	for (int i = 0; i < N+M; i++)
	{
		cin >> num;
		if (m[num] == true) 
			m.erase(num);
		else
			m[num] = true;
	}
	cout << m.size();
    return 0;
}