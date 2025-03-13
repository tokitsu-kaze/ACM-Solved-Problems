#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
const int mod=998244353;
int main()
{
	int n,i,cnt;
	string s[11];
	n=8;
	cnt=0;
	for(i=0;i<n;i++)
	{
		cin>>s[i];
		if(s[i]=="AC") cnt++;
		else if(s[i]=="NoOut") cnt++;
	}
	if(cnt>=6) puts("Win");
	else if(cnt==5) puts("Draw");
	else puts("Lose");
	return 0;
}
