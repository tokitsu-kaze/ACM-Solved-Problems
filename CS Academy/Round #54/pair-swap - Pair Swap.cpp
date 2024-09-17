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
typedef unsigned long long ull;
#define PII pair<int,int>
#define PLL pair<ll,ll>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=2e5+10;
const ll mod=1e9+7;
int v[MAX],minn[MAX][22];
int pmin(int a,int b){return v[a]<v[b]?a:b;}
void RMQ(int n)
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		minn[i][0]=i;
	}
	for(j=1;1<<(j-1)<=n;j++)
	{
		for(i=1;i+(1<<j)-1<=n;i++)
		{
			int t=1<<(j-1);
			minn[i][j]=pmin(minn[i][j-1],minn[i+t][j-1]);
		}
	}
}
int query(int l,int r)
{
	int j=(int)(log10(r-l+1)/log10(2))+1;
	int i=r-(1<<(j-1))+1;
	return pmin(minn[l][j-1],minn[i][j-1]);
}
int main()
{
	int n,k,pos,i;
	while(~scanf("%d%d",&n,&k))
	{
		for(i=1;i<=n;i++) scanf("%d",&v[i]);
		RMQ(n);
		for(i=1;i<=n-1;i++)
		{
			pos=query(i+1,min(i+k,n));
//			cout<<i<<" "<<pos<<endl;
			if(v[pos]<v[i])
			{
				swap(v[pos],v[i]);
				break;
			}
		}
		printf("%d",v[1]);
		for(i=2;i<=n;i++) printf(" %d",v[i]);
		puts("");
	}
	return 0;
}
/*
5 3
5 4 3 2 1
6 2
1 2 3 4 5 1
5 3
2 1 1 1 1
6 1
2 3 4 4 4 5
6 3
2 3 2 3 2 3
*/