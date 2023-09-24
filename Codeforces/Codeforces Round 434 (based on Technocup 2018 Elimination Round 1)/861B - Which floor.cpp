#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-8;
const int MAX=1e5+10;
const ll mod=1e9+7;
int main()
{
	int n,m,i,a,b,c[111],ans[111],cnt,k,flag,res[111];
	while(~scanf("%d%d",&n,&m))
	{
		if(m==0)
		{
			if(n==1) puts("1");
			else puts("-1");
			continue;
		}
		mem(c,0);
		while(m--)
		{
			scanf("%d%d",&a,&b);
			c[a]=b;
		}
		cnt=0;
		for(k=1;k<=100;k++)
		{
			flag=0;
			for(i=1;i<=100;i++)
			{
				int temp=i/k;
				if(i%k) temp++;
				if(c[i]&&c[i]!=temp)
				{
					flag=1;
					break;
				}
			}
			if(!flag) ans[cnt++]=k;
		}
		set<int> s;
		for(i=0;i<cnt;i++)
		{
			s.insert(n/ans[i]+(n%ans[i]==0?0:1));
		}
		if(sz(s)!=1) puts("-1");
		else printf("%d\n",*s.begin());
	}
	return 0;
}
/*
7 3
2 1
4 2
6 3
*/