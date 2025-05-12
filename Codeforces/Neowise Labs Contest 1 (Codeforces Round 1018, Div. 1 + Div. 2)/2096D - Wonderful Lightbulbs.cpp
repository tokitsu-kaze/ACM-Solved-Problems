#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX],b[MAX];
int main()
{
	int T,n,i,x,y;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		map<int,int> ra,rb;
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&x,&y);
			ra[x]++;
			rb[x+y]++;
		}
		for(auto &it:ra)
		{
			if(it.second&1) x=it.first;
		}
		for(auto &it:rb)
		{
			if(it.second&1) y=it.first-x;
		}
		printf("%d %d\n",x,y);
	}
	return 0;
}

