////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-10-10 18:50:46
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4041
////Problem Title: 
////Run result: Accept
////Run time:171MS
////Run memory:5672KB
//////////////////System Comment End//////////////////
#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define all(x) x.begin(),x.end()
using namespace std;
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1000000+10;
const ll mod=1e9+7;
char a[MAX],temp[22],res[50010][22];
int tot,pre[50010];
vector<int> mp[50010];
void dfs(int x,int fa)
{
	int i,to;
	for(i=0;i<sz(mp[x]);i++)
	{
		to=mp[x][i];
		if(to==fa) continue;
		printf("%d %d\n",x,to);
		dfs(to,x);
		printf("%d %d\n",to,x);
	}
}
int main()
{
	int t,i,len,cnt,fa;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",a);
		for(i=1;i<=50000;i++)
		{
			mp[i].clear();
			pre[i]=0;
		}
		tot=0;
		len=strlen(a);
		cnt=0;
		fa=0;
		for(i=0;i<len;i++)
		{
			if(a[i]>='a'&&a[i]<='z') temp[cnt++]=a[i];
			else
			{
				if(cnt==0)
				{
					if(a[i]==')'&&a[i-1]==')') fa=pre[fa];
					continue;
				}
				temp[cnt]='\0';
				strcpy(res[++tot],temp);
				if(a[i]=='(')
				{
					if(fa==0) fa=tot;
					else
					{
						pre[tot]=fa;
						fa=tot;
					}
				}
				else if(a[i]==',') pre[tot]=fa;
				else if(a[i]==')')
				{
					pre[tot]=fa;
					fa=pre[fa];
				}
				cnt=0;
			}
		}
		if(cnt)
		{
			temp[cnt]='\0';
			strcpy(res[++tot],temp);
			if(fa) pre[tot]=fa;
		}
		printf("%d\n",tot);
		for(i=1;i<=tot;i++)
		{
			puts(res[i]);
		}
		for(i=1;i<=tot;i++)
		{
			mp[i].pb(pre[i]);
			mp[pre[i]].pb(i);
		}
		dfs(1,0);
		puts("");
	}
	return 0;
}
/*
100
a(b(c(d,e)),f)
*/