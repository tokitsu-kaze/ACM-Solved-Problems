#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
const int mod=998244353;
int main()
{
	int t,n,m,a,b,c,d,ans,x,y,f;
	char dir[5];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d%d%d%s",&n,&m,&a,&b,&c,&d,dir);
		map<pair<pair<int,int>,pair<int,int>>,int> flag;
		if(dir[0]=='D') x=1;
		else x=-1;
		if(dir[1]=='R') y=1;
		else y=-1;
		ans=0;
		while(1)
		{
			if(a==c&&b==d) break;
			if(flag.count({{a,x},{b,y}})) break;
			flag[{{a,x},{b,y}}]=1;
			f=0;
			if(x==-1&&a==1)
			{
				x=1;
				f=1;
			}
			if(x==1&&a==n)
			{
				x=-1;
				f=1;
			}
			if(y==-1&&b==1)
			{
				y=1;
				f=1;
			}
			if(y==1&&b==m)
			{
				y=-1;
				f=1;
			}
			ans+=f;
			a+=x;
			b+=y;
		}
		if(a==c&&b==d) printf("%d\n",ans);
		else puts("-1");
	}
	return 0;
}
