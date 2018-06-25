////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2018-02-01 19:02:55
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5884
////Problem Title: 
////Run result: Accept
////Run time:421MS
////Run memory:3020KB
//////////////////System Comment End//////////////////
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
int a[MAX],n;
int Huffman(int k)
{
	int i,res,s;
	queue<int> q,d;
	s=((n-1)%(k-1)?k-1-(n-1)%(k-1):0);
	while(s--) q.push(0);
	for(i=1;i<=n;i++) q.push(a[i]);
	res=0;
	while(sz(q)+sz(d)>1)
	{
		s=0;
		for(i=0;i<k;i++)
		{
			if(sz(q)&&sz(d))
			{
				if(q.front()<d.front())
				{
					s+=q.front();
					q.pop();
				}
				else
				{
					s+=d.front();
					d.pop();
				}
			}
			else if(sz(q))
			{
				s+=q.front();
				q.pop();
			}
			else if(sz(d))
			{
				s+=d.front();
				d.pop();
			}
		}
		res+=s;
		d.push(s);
	}
	return res;
}
int main()
{
	int t,i,l,r,mid,k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		l=2;
		r=n;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(Huffman(mid)<=k) r=mid;
			else l=mid+1;
		}
		printf("%d\n",l);
	}
	return 0;
}