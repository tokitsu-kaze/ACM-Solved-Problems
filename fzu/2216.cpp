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
#define INF 0x3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define MAX 100000+10
using namespace std;
typedef long long ll;
int dp[MAX],cnt;
int check(int s,int e)
{
	if(dp[e]-dp[s-1]<=cnt) return 1;
	return 0;
}
int search2(int i,int r)
{
	int mid,l;
	l=i;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(check(i,mid)) l=mid+1;
		else r=mid;
	}
	if(dp[l]-dp[i-1]>cnt) l--;
	return l;
}
int main()
{ 
	int t,n,m,i,flag[MAX],a,temp,ans;
	while(cin>>t)
	{
		while(t--)
		{
			cin>>n>>m;
			mem(flag,0);
			mem(dp,0);
			cnt=temp=ans=0;
			for(i=0;i<n;i++)
			{
				scanf("%d",&a);
				if(a==0) cnt++;
				else flag[a]=1;
			}
			for(i=1;i<=m;i++)
			{
				if(!flag[i]) temp++;
				dp[i]=temp; 
			}
			for(i=1;i<=m;i++)
			{
				ans=max(ans,search2(i,m)-i+1);
			}
			cout<<ans<<endl;
		}
	}
    return 0;
}