#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int main()
{
	int i,ok;
	string s;
	cin>>s;
	if(s[0]=='<' && s.back()=='>')
	{
		ok=1;
		for(i=1;i<s.size()-1;i++)
		{
			if(s[i]!='=') ok=0;
		}
		if(ok) puts("Yes");
		else puts("No");
	}
	else puts("No");
	return 0;
}
