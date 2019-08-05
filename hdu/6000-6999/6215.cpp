////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2018-02-05 22:22:36
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6215
////Problem Title: 
////Run result: Accept
////Run time:265MS
////Run memory:3668KB
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
int l[MAX],r[MAX];
int v[MAX];
int q[MAX],front;
int main()
{
	int t,n,i,now,cnt,f;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		front=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&v[i]);
			q[front++]=i;
			l[i]=i-1;
			r[i]=i+1;
		}
		r[0]=1;
		v[0]=0;
		while(1)
		{
			cnt=now=0;
			while(now<front)
			{
				i=q[now];
				f=0;
				while(r[i]<=n&&v[i]>v[r[i]]) i=r[i],f=1;
				if(f)
				{
					r[l[q[now]]]=r[i];
					l[r[i]]=l[q[now]];
					q[cnt++]=l[q[now]];
				}
				while(q[now]<=i&&now<front) now++;
			}
			if(!cnt) break;
			front=cnt;
		}
		now=0;
		vector<int> ans;
		while(now<=n)
		{
			if(now)ans.pb(v[now]);
			now=r[now];
		}
		printf("%d\n",sz(ans));
		for(i=0;i<sz(ans);i++) printf("%d ",ans[i]);
		puts("");
	}
	return 0;
}