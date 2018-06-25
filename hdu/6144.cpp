////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-08-18 16:37:07
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6144
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1712KB
//////////////////System Comment End//////////////////
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
vector<char> v;
int main()
{
	ll ans,temp;
	int t,len,i,j,tag,b,flag,nowlen;
	char a[1111],now[1111];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",a);
		v.clear();
		len=strlen(a);
		tag=0;
		flag=0;
		nowlen=0;
		b=0;
		for(i=0;i<len;i++)
		{
			if(a[i]=='#') tag=1;
			else if(a[i]=='(') flag=tag+1;
			else if(a[i]==')')
			{
				if(flag==2)
				{
					nowlen=0;
					flag=0;
					tag=0;
					b=0;
				}
			}
			else if(a[i]>='0'&&a[i]<='9')
			{
				if(flag==1) now[nowlen++]=a[i];
				else if(flag==2)
				{
					b=a[i]-'0';
					while(b--)
					{
						for(j=0;j<nowlen;j++)
						{
							v.pb(now[j]);
						}
					}
				}
				else v.pb(a[i]);
			}
		}
		if(nowlen)
		{
			for(j=0;j<nowlen;j++)
			{
				v.pb(now[j]);
			}
		}
		ans=0;
		for(i=0;i<sz(v);i++)
		{
			ans=ans*10+v[i]-'0';
			ans%=mod;
		}
		printf("%I64d\n",ans);
	}
	return 0;
}