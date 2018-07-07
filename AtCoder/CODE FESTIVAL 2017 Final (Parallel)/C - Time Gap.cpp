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
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
int main()
{
	int n,i,j,k,d[55],ans,res,flag[33],x;
	while(~scanf("%d",&n))
	{
		mem(flag,0);
		flag[0]++;
		for(i=0;i<n;i++)
		{
			scanf("%d",&x);
			flag[x]++;
		}
		if(n>23)
		{
			puts("0");
			goto end;
		}
		for(i=1;i<12;i++)
		{
			if(flag[i]>2)
			{
				puts("0");
				goto end;
			}
			if(flag[i]==2)
			{
				flag[i]=flag[24-i]=1;
			}
		}
		if(flag[0]>=2||flag[12]>=2)
		{
			puts("0");
			goto end;
		}
		n=0;
		for(i=0;i<24;i++)
		{
			if(flag[i]) d[n++]=i;
		}
		if(n>=15)
		{
			puts("1");
			goto end;
		}
		d[n++]=24;
		ans=0;
		for(i=0;i<(1<<(n-1));i++)
		{
			for(j=0;j<(n-1);j++)
			{
				if(i&(1<<j))
				{
					if(d[j]) d[j]=24-d[j];
				}
			}
			res=INF;
			for(j=0;j<n;j++)
			{
				for(k=0;k<n;k++)
				{
					if(j==k) continue;
					res=min(res,abs(d[j]-d[k]));
				}
			}
			if(res!=INF) ans=max(ans,res);
			for(j=0;j<(n-1);j++)
			{
				if(i&(1<<j))
				{
					if(d[j]) d[j]=24-d[j];
				}
			}
		}
		printf("%d\n",ans);
		end:;
	}
	return 0;
}
/*
13
0 1 2 3 4 5 6 7 8 9 10 11 12
*/

