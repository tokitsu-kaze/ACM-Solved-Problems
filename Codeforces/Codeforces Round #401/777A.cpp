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
int main()
{
	int n,x,flag[6],i,j,pos;
	while(~scanf("%d%d",&n,&x))
	{
		n%=6;
		if(n==0) n=6;
		
		for(j=0;j<3;j++)
		{
			mem(flag,0);
			flag[j]=1;
			for(i=1;i<=n;i++)
			{
				if(i&1) swap(flag[0],flag[1]);
				else swap(flag[1],flag[2]);
			}
			for(i=0;i<3;i++)
			{
				if(flag[i])
				{
					pos=i;
					break;
				}
			}
			if(pos==x)
			{
				printf("%d\n",j);
				break;
			}
		}
	}
	return 0;
}
/*
0 1 2
1 0 2
1 2 0
2 1 0
2 0 1
0 2 1
0 1 2
*/