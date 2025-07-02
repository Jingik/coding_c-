#include <iostream>
#include <string>
#include <vector>

using namespace std;

int T;
vector<string> V;

int Is_Palindrome(int Left, int Right, int Delete, string Str)
{
	while (Left < Right)
	{
		if (Str[Left] != Str[Right])
		{
			if (Delete == 0)
			{
				if (Is_Palindrome(Left + 1, Right, 1, Str) == 0) return 1;
				if (Is_Palindrome(Left, Right - 1, 1, Str) == 0) return 1;
				return 2;
			}
			else return 2;
		}
		else
		{
			Left++;
			Right--;
		}
	}
	return 0;
}


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		string S;
		cin >> S;
		V.push_back(S);
	}

	for (int t = 0; t < T; t++)
	{
		string Str = V[t];
		int Result = Is_Palindrome(0, Str.length() - 1, 0, Str);
		cout << Result << endl;
	}
	return 0;
}