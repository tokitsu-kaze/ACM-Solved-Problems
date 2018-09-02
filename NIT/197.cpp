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
#define mem(a,b) memset((a),(b),sizeof(a))
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=2e5+10;
const ll mod=1e9+6;
struct node
{
	int id,v;
}a[MAX];
int flag[MAX];
int tag[MAX];
int sum[MAX];
int t[MAX];
int main()
{
	int n,m,i,k,s,cnt,ans1,ans2;
	while(~scanf("%d",&n))
	{
		mem(tag,0);
		mem(sum,0);
		s=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&a[i].id,&a[i].v);
			if(!tag[a[i].id])
			{
				sum[s++]=a[i].id;
				tag[a[i].id]=a[i].v;
			}
			tag[a[i].id]=min(tag[a[i].id],a[i].v);
		}
		scanf("%d",&m);
		mem(t,0);
		while(m--)
		{
	//		mem(flag,0);
			scanf("%d",&k);
			cnt=0;
			for(i=0;i<k;i++)
			{
				scanf("%d",&t[i]);
				if(tag[t[i]]) cnt++;
				flag[t[i]]=1;
			}
			if(cnt==s)
			{
				puts("0 0");
				for(i=0;i<k;i++)
				{
					flag[t[i]]=0;
				}
				continue;
			}
			ans1=ans2=INF;
			if(cnt==s-1)
			{
				for(i=0;i<s;i++)
				{
					if(!flag[sum[i]]&&tag[sum[i]])
					{
						ans1=sum[i];
						ans2=tag[sum[i]];
						break;
					}
				}
			}
			else
			{
				for(i=n;i>=1;i--)
				{
					if(!flag[a[i].id])
					{
						if(ans1!=INF&&ans1!=a[i].id) break;
						if(ans1==a[i].id)
						{
							ans2=min(ans2,a[i].v);
						}
						else if(ans1==INF)
						{
							ans1=a[i].id;
							ans2=a[i].v;
						}
					}
				}
			}
			printf("%d %d\n",ans1,ans2);
			for(i=0;i<k;i++)
			{
				flag[t[i]]=0;
			}
		}
	}
	return 0;
}