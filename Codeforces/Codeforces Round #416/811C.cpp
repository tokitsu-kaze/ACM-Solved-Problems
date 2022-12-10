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
#define MP make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=5e3+10;
const ll mod=1e9+7;
struct node
{
	int id,l,r,v;
	node(){}
	node(int a,int b)
	{
		id=a;
		l=b;
		r=-1;
		v=0;
	}
}a[MAX];
int dp[MAX],mp[MAX];
int main()
{
	int i,j,n,b[MAX],flag[MAX],cnt,ans;
	while(~scanf("%d",&n))
	{
		mem(mp,0);
		cnt=1;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&b[i]);
			if(!mp[b[i]])
			{
				mp[b[i]]=cnt;
				a[cnt++]=node(b[i],i);
			}
			else a[mp[b[i]]].r=i;
		}
		cnt--;
		for(i=1;i<=cnt;i++)
		{
			if(a[i].r==-1) a[i].r=a[i].l;
			a[i].v=a[i].id;
			mem(flag,0);
			flag[a[i].id]=1;
			for(j=a[i].l+1;j<=a[i].r;j++)
			{
				if(!flag[b[j]])
				{
					a[i].v^=b[j];
					flag[b[j]]=1;
				}
			}
	//		cout<<a[i].id<<" "<<a[i].l<<" "<<a[i].r<<" "<<a[i].v<<endl;
		}
		mem(dp,0);
		ans=0;
		for(i=1;i<=n;i++)
		{
			dp[i]=dp[i-1];
			if(i==a[mp[b[i]]].r)
			{
				int temp=a[mp[b[i]]].l,pos=mp[b[i]];
				for(j=a[mp[b[i]]].l;j<a[mp[b[i]]].r;j++)
				{
					if(a[mp[b[j]]].r>i)
					{
						temp=-1;
						break;
					}
					if(a[mp[b[j]]].l<temp)
					{
						temp=a[mp[b[j]]].l;
						pos=mp[b[j]];
					}
				}
				if(temp!=-1) dp[i]=max(dp[temp-1]+a[pos].v,dp[i]);
			}
	//		cout<<dp[i]<<endl;
		}
		printf("%d\n",dp[n]);
	}
	return 0;
}