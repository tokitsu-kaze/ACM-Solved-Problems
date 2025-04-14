#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
char s[MAX],ans[MAX];
int main()
{
	int n,x,y,i,nx,ny;
	scanf("%d%d%d",&n,&x,&y);
	scanf("%s",s+1);
	map<pair<int,int>,int> mp;
	nx=ny=0;
	mp[{nx,ny}]=1;
	for(i=1;i<=n;i++)
	{
		if(s[i]=='N') nx--;
		else if(s[i]=='S') nx++;
		else if(s[i]=='W') ny--;
		else ny++;
		if(mp.count({nx-x,ny-y})) ans[i]='1';
		else ans[i]='0';
		mp[{nx,ny}]=1;
	}
	ans[n+1]='\0';
	puts(ans+1);
	return 0;
}

