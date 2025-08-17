#include <iostream>

using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
	int N;
	cin >> N;
 
	int facN = 1;
 
	for (int i = 1; i <= N; i++)
	{
		facN *= i;
	}
 
	cout << facN << '\n';
	return 0;
}