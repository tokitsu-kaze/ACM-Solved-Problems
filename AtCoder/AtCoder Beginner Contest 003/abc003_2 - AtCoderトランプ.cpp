#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1440+10;
int main()
{
	string tmp="atcoder";
	string s,t;
	int n,i;
	cin>>s>>t;
	n=s.size();
	for(i=0;i<n;i++)
	{
		if(s[i]==t[i]) continue;
		if(s[i]=='@')
		{
			if(tmp.find(t[i])!=tmp.npos) continue;
		}
		if(t[i]=='@')
		{
			if(tmp.find(s[i])!=tmp.npos) continue;
		}
		puts("You will lose");
		return 0;
	}
	puts("You can win");
	return 0;
}
