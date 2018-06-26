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
int a[15],ans[15],n;
map<int,int>m;
void dfs(int row,int aim)
{
	int i;
	if(aim==6)
	{
		for(i=0;i<6;i++)
		{
			cout<<ans[i];
			if(i!=5) cout<<" ";
			else puts("");
		}
		return;
	}
	for(i=row;i<n;i++)
	{
		if(!aim||(a[i]>ans[aim-1]&&!m[i]))
		{
			m[i]=1;
			ans[aim]=a[i];
			dfs(row+1,aim+1);
			m[i]=0;
			ans[aim]=0;
		}
	}
	return;
}
int main()
{
    int i,flag=0;
	while(cin>>n&&n)
	{
		if(flag) puts("");
		mem(a,0);
		mem(ans,0);
		m.clear();
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		dfs(0,0);
		flag=1;
	}
    return 0;
}