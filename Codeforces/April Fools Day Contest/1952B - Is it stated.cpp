#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	string s;
	cin>>t;
	while(t--)
	{
		cin>>s;
		if(s.find("it")!=s.npos) puts("YES");
		else puts("NO");
	}
	return 0;
}
