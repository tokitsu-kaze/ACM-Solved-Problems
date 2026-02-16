#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=4e5+10;
int cal(int x)
{
	string tmp=to_string(x);
	int res=0;
	for(auto &it:tmp)
	{
		x=it-'0';
		res+=x*x;
	}
	return res;
}
int main()
{
	int n,i,vis[2027],ok;
	scanf("%d",&n);
	memset(vis,0,sizeof vis);
	ok=0;
	while(1)
	{
		if(n==1)
		{
			ok=1;
			break;
		}
		if(vis[n]) break;
		vis[n]=1;
		n=cal(n);
	}
	if(ok) puts("Yes");
	else puts("No");
	return 0;
}
