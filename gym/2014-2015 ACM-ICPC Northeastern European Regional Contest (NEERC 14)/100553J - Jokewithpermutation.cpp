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
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
int n,flag[55],ans[55],res;
int len;
char a[111];
void dfs(int pos,int cnt)
{
	int i,tag,temp;
	if(res) return;
	if(cnt==n&&pos==len)
	{
		tag=0;
		for(i=1;i<=n;i++)
		{
			if(!flag[i]) tag=1;
		}
		if(!tag) res=1;
		return;
	}
	temp=0;
	for(i=pos;i<len&&i<pos+2;i++)
	{
		if(res) return;
		temp=temp*10+a[i]-'0';
		if(temp>n||flag[temp]) continue;
		ans[cnt]=temp;
		flag[temp]=1;
		dfs(i+1,cnt+1);
		flag[temp]=0;
	}
}
int main()
{
	int i;
	freopen("joke.in","r",stdin);
	freopen("joke.out","w",stdout);
	while(~scanf("%s",a))
	{
		len=strlen(a);
		if(len<=9) n=len;
		else n=9+(len-9)/2;
		mem(flag,0);
		res=0;
		dfs(0,0);
		for(i=0;i<n;i++)
		{
			if(i==n-1) printf("%d\n",ans[i]);
			else printf("%d ",ans[i]);
		}
	} 
	return 0;
}