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
const int MAX=2e5+10;
const ll mod=1e9+7;
char name[55][5];
void init()
{
	int i,j;
	for(i=1;i<=26;i++)
	{
		j=i-1;
		name[i][0]=name[i+26][0]=j+'A';
		name[i][1]=name[i+26][1]=j+'a';
		name[i+26][2]=j+'a';
	}
}
int main()
{
	int n,k,i,ans[55],now;
	init();
	char res[5];
	while(~scanf("%d%d",&n,&k))
	{
		mem(ans,0);
		for(i=1;i<=k;i++)
		{
			ans[i]=i;
		}
		now=k;
		for(i=1;i<=n-k+1;i++)
		{
			scanf("%s",res);
			if(i==1)
			{
				if(res[0]=='N') ans[i]=ans[now];
			}
			else
			{
				now++;
				if(res[0]=='N') ans[now]=ans[i];
				else ans[now]=now;
			}
		}
		for(i=1;i<=n;i++)
		{
			if(i==1) printf("%s",name[ans[i]]);
			else printf(" %s",name[ans[i]]);
		}
		puts("");
	}
	return 0;
}