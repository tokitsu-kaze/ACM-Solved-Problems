////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-10-11 20:45:55
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6008
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1736KB
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
const int MAX=1e5+10;
const ll mod=1e9+7;
int main()
{
	int t,g,x,y,i,j,cas=1;
	scanf("%d",&t);
	char q[33],temp[33];
	while(t--)
	{
		scanf("%d%s",&g,q);
		map<int,string> mp1[6],mp2;
		map<string,int> mp;
		for(j=1;j<=5;j++)
		{
			for(i=1;i<=20;i++)
			{
				scanf("%s",temp);
				mp1[j][i]=temp;
			}
		}
		for(i=1;i<=20;i++)
		{
			scanf("%s",temp);
			mp2[i]=temp;
		}
		printf("Case #%d: ",cas++);
		int flag=0;
		for(y=0;y<=g;y++)
		{
			x=g-y;
			mp.clear();
			int c=0;
			for(i=1;i<=20;i++)
			{
				if(c==x) break;
				for(j=1;j<=5;j++)
				{
					if(c==x) break;
					if(!mp[mp1[j][i]]) mp[mp1[j][i]]=++c;
				}
			}
			c=0;
			for(i=1;i<=20&&c<y;i++)
			{
				if(c==y) break;
				if(!mp[mp2[i]]) mp[mp2[i]]=++c;
				
			}
			if(mp[q]) flag++;
			else
			{
				printf("%d\n",y);
				break;
			}
		}
		if(flag==g+1) puts("ADVANCED!");
	}
	return 0;
}