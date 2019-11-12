/*
Problem URL : https://codeforces.com/problemset/problem/158/B
34번째 테스트 케이스에서 오류 발생
*/

#include<iostream>
#include<vector>

using namespace std;

int main(void)
{
	int n;
	cin >> n;

	int answer = 0;
	int one = 0, two = 0;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		switch (temp)
		{
		case 1:
			if (one < 0)
				answer++;
			one++;
			break;
		case 2:
			two++;
			break;
		case 3:
			if (one > 0)
				answer++;
			one--;
			break;
		case 4:
			answer++;
			break;
		}
	}

	if (one > 0)
	{
		answer += one / 4;
		one = one % 4;
		if (one == 0)
		{
			answer += two / 2 + two % 2;
		}
		else
		{
			if (one >= two)
			{
				switch (one)
				{
				case 1:
					answer += 1;
					two--;
					if (two >= 0)
						answer += two / 2 + two % 2;
					break;
				case 2:
					answer += 1;
					two--;
					if (two >= 0)
						answer += two / 2 + two % 2;
					break;
				case 3:
					if (two == 1 || two == 2)
						answer += 2;
					else
					{
						answer += 2;
						two -= 2;
						answer += two / 2 + two % 2;
					}
				}
			}
			else
			{
				switch (one)
				{
				case 1:
				case 2:
					answer += 1;
					break;
				case 3:
					if (two == 0)
						answer += 1;
					else
						answer += 2;
					break;
				}
			}
		}
	}
	else if (one < 0)
	{
		(two / 2) ? (two % 2 ? answer += (two / 2) + 1 : answer += (two / 2)) : (two ? answer += two : answer);
		answer -= one;
	}
	else 
	{
		(two / 2) ? (two % 2 ? answer += (two / 2) + 1 : answer += (two / 2)) : (two ? answer += two : answer);
	}

	cout << answer << endl;

	return 0;
}
