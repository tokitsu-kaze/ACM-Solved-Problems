#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int main()
{
	int n,i,ok;
	string s,t;
	cin>>n;
	cin>>s;
	cin>>t;
	ok=1;
	for(i=0;i<n;i++)
	{
		if(t[i]=='*') continue;
		if(t[i]!=s[i]) ok=0;
	}
	if(ok) puts("Yes");
	else puts("No");
	return 0;
}
