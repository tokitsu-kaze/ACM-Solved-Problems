////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-10-11 22:19:20
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6000
////Problem Title: 
////Run result: Accept
////Run time:7753MS
////Run memory:14136KB
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
const int MAX=1e6+10;
const ll mod=1e9+7;
struct node
{
	ll v,temp;
	node(){}
	node(ll a,ll b)
	{
		v=a;
		temp=b;
	}
	friend bool operator<(const node &a,const node &b)
	{
		return a.v>b.v;
	}
};
ll res[MAX];
int main()
{
	ll t,i,a,b,c,cas=1;
	ll x;
	scanf("%lld",&t);
//	t=io.read();
	while(t--)
	{
		scanf("%lld%lld%lld",&a,&b,&c);
	/*	a=io.read();
		b=io.read();
		c=io.read();*/
		priority_queue<node> q1,q2;
		for(i=1;i<=b;i++)
		{
			scanf("%lld",&x);
	//		x=io.read();
			q1.push(node(x,x));
		}
		for(i=1;i<=c;i++)
		{
			scanf("%lld",&x);
	//		x=io.read();
			q2.push(node(x,x));
		}
		printf("Case #%lld: ",cas++);
		ll ans=0;
		for(i=a;i>=1;i--)
		{
			node temp1=q1.top();
			q1.pop();
			res[i]=temp1.v;
			q1.push(node(res[i]+temp1.temp,temp1.temp));
		}
		for(i=1;i<=a;i++)
		{
			node temp2=q2.top();
			q2.pop();
			ans=max(ans,res[i]+temp2.v);
			q2.push(node(temp2.v+temp2.temp,temp2.temp));
		}
		printf("%lld\n",ans);
	}
	return 0;
}