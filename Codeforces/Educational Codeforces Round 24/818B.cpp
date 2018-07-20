#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cctype>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <ctime>
#define mem(a,b) memset((a),(b),sizeof(a))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=3e5+10;
const ll mod=1e9+7;
int main()
{
	int n,m,now,l[111],a[111],cnt[111],i,flag,rest[111],j;
	while(~scanf("%d%d",&n,&m))
	{
		for(i=1;i<=m;i++)
		{
			scanf("%d",&l[i]);
		}
		flag=0;
		mem(a,0);
		mem(cnt,0);
		now=l[1];
		for(i=2;i<=m;i++)
		{
			if(a[now]==0)
			{
				a[now]=l[i]+n-now;
				if(a[now]>n) a[now]%=n;
				cnt[a[now]]++;
			}
			else if(a[now]!=((l[i]+n-now)>n?(l[i]+n-now)%n:(l[i]+n-now))) flag=1;
			now=l[i];
		}
		mem(rest,0);
		j=0;
		for(i=1;i<=n;i++)
		{
			if(cnt[i]>1) flag=1;
			else if(cnt[i]==0) rest[j++]=i;
		}
		j=0;
		if(flag) puts("-1");
		else
		{
			for(i=1;i<=n;i++)
			{
				if(!a[i]) a[i]=rest[j++];
				if(i==1) printf("%d",a[i]);
				else printf(" %d",a[i]);
			}
			puts("");
		}
	}
	return 0;
}