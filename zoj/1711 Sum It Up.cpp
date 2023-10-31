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
#define MAX 10000+10
using namespace std;
typedef long long ll;
int n,a[13],ans[13],t,flag;
void dfs(int val,int cnt,int p)
{
	int i;
	if(val==t)
	{
		for(i=0;i<cnt;i++)
		{
			cout<<ans[i];
			if(i!=cnt-1) cout<<"+";
		}
		puts("");
		flag=0;
		return;
	}
	if(val>t) return;
	if(p>=n) return;
	ans[cnt]=a[p];
	dfs(val+a[p],cnt+1,p+1);
	while(p+1<n&&a[p]==a[p+1])
	{
		p++;
	}
	dfs(val,cnt,p+1);
}
int main()
{
	int i;
	while(cin>>t>>n&&(t+n))
	{
		mem(a,0);
		mem(ans,0);
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		printf("Sums of %d:\n",t);
		flag=1;
		dfs(0,0,0);
		if(flag) puts("NONE");
	}
    return 0;
}