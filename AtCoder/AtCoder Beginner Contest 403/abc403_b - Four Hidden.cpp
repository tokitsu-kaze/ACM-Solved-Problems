#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int i,j,ok,n,m,f;
	string s,t;
	cin>>s>>t;
	n=s.size();
	m=t.size();
	ok=0;
	for(i=0;i<=n-m;i++)
	{
		f=1;
		for(j=0;j<m;j++)
		{
			if(s[i+j]=='?') continue;
			if(s[i+j]!=t[j]) f=0;
		}
		ok|=f;
	}
	if(ok) puts("Yes");
	else puts("No");
	return 0;
}
