#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
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
typedef unsigned long long ull;
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<double,double>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-8;
const int MAX=1e5+10;
const ll mod=1e9+7;
int mp[(1<<10)+10][(1<<10)+10];
int main()
{
	int k,i,j,now,pre;
	while(~scanf("%d",&k))
	{
		if(k==0)
		{
			puts("+");
			continue;
		}
		else if(k==1)
		{
			puts("+*");
			puts("++");
			continue;	
		}
		mp[1][1]=mp[2][1]=mp[2][2]=1;
		mp[1][2]=-1;
		k--;
		pre=2;
		while(k--)
		{
			now=pre<<1;
			for(i=1;i<=pre;i++)
			{
				for(j=pre+1;j<=now;j++)
				{
					mp[j][i]=mp[i][j]=mp[i][j-pre];
				}
			}
			for(i=pre+1;i<=now;i++)
			{
				for(j=1;j<=now;j++)
				{
					mp[i][j]=mp[i-pre][j];
				}
			}
			for(i=pre+1;i<=now;i++)
			{
				for(j=pre+1;j<=now;j++)
				{
					mp[i][j]=-1*mp[i-pre][j-pre];
				}
			}
			pre=now;
		}
	//	cout<<now<<endl;
		for(i=1;i<=now;i++)
		{
			for(j=1;j<=now;j++)
			{
				if(mp[i][j]==1) putchar('+');
				else putchar('*');
			}
			puts("");
		}
	}
	return 0;
}