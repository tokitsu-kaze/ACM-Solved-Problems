#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cctype>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#define mem(a,b) memset((a),(b),sizeof(a))
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-5;
const int MAX=1000000+10;
const ll mod=1e6;
ll ans[MAX];
ll cnt;
void init()
{
	ll t;
	cnt=0;
	mem(ans,0);
	queue<ll> q;
	q.push(8);
	q.push(9);
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		ans[cnt++]=t;
		if(t*10+8>1e10) continue;
		q.push(t*10+8);
		q.push(t*10+9);
	}
//	cout<<cnt<<endl;
//	for(ll i=0;i<cnt;i++) cout<<ans[i]<<endl;
}
int main()
{
	init();
	ll t,n,i,res,flag;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		flag=0;
		for(i=0;i<cnt;i++)
		{
			if(ans[i]%n==0)
			{
				printf("%lld\n",ans[i]/n);
				flag=1;
			}
		}
		if(!flag) puts("\\This is not of value!\\");
	}
	return 0;
}