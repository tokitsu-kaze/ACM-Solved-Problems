#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,i,n,ans,x,y;
	char l[33],r[33];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s%s",l,r);
		n=strlen(l);
		ans=0;
		x=y=0;
		for(i=0;i<n;i++)
		{
			x=x*10+l[i]-'0';
			y=y*10+r[i]-'0';
			if(x==y) ans+=2;
			else if(x+1==y) ans++;
			else break;
		}
		printf("%d\n",ans);
	}
	return 0;
}
