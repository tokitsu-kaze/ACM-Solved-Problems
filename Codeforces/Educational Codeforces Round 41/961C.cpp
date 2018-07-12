#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
using namespace std;
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
typedef long long ll;
typedef unsigned long long ull;
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<double,double>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-8;
const int MAX=2e5+10;
const ll mod=1e9+7;
int mp[155][155][5];
int  main()
{
	int n,i,j,k,flag[]={0,1,2,3},ans,now;
	char c;
	while(~scanf("%d",&n))
	{
		for(i=0;i<n;i++)
		{
			getchar();
			for(j=0;j<n;j++)
			{
				scanf("%c",&c);
				mp[i][j][0]=c-'0';
			}
		}
		getchar();
		for(i=0;i<n;i++)
		{
			getchar();
			for(j=0;j<n;j++)
			{
				scanf("%c",&c);
				mp[i][j][1]=c-'0';
			}
		}
		getchar();
		for(i=0;i<n;i++)
		{
			getchar();
			for(j=0;j<n;j++)
			{
				scanf("%c",&c);
				mp[i][j][2]=c-'0';
			}
		}
		getchar();
		for(i=0;i<n;i++)
		{
			getchar();
			for(j=0;j<n;j++)
			{
				scanf("%c",&c);
				mp[i][j][3]=c-'0';
			}
		}
		ans=INF;
		do
		{
			now=0;
			for(k=0;k<4;k++)
			{
				for(i=0;i<n;i++)
				{
					for(j=0;j<n;j++)
					{
						if((i+j)%2==k%2)
						{
							if(mp[i][j][flag[k]]!=0) now++;
						}
						else
						{
							if(mp[i][j][flag[k]]==0) now++;
						}
					}
				}
			}
			ans=min(ans,now);
			for(k=0;k<4;k++)
			{
				for(i=0;i<n;i++)
				{
					for(j=0;j<n;j++)
					{
						if((i+j)%2==k%2)
						{
							if(mp[i][j][flag[k]]!=1) now++;
						}
						else
						{
							if(mp[i][j][flag[k]]==1) now++;
						}
					}
				}
			}
			ans=min(ans,now);
		}
		while(next_permutation(flag,flag+4));
		printf("%d\n",ans);
	}
	return 0;
}