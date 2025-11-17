#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int i,ok;
	string s,t;
	cin>>s>>t;
	ok=1;
	for(i=1;i<s.size();i++)
	{
		if(s[i]>='A' && s[i]<='Z')
		{
			if(t.find(s[i-1])==t.npos) ok=0;
		}
	}
	if(ok) puts("Yes");
	else puts("No");
	return 0;
}
