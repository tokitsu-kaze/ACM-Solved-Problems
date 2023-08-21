#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
struct node{int v,id;};
int a[MAX],n;
char ans[MAX];
int ck(int x)
{
	int i;
	ll sum=0;
	for(i=1;i<=n;i++) sum+=__gcd(a[i],x);
	if(sum&1) return 0;
	sum/=2;
	vector<node> res;
	for(i=1;i<=n;i++) res.push_back({__gcd(a[i],x),i});
	sort(res.begin(),res.end(),[&](node a,node b){
		return a.v>b.v;
	});
	for(auto &it:res)
	{
		if(sum>=it.v)
		{
			sum-=it.v;
			ans[it.id]='1';
		}
		else ans[it.id]='0';
	}
	ans[n+1]='\0';
	if(sum) return 0;
	return 1;
}
int main()
{
	int i,x;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	if(!(n&1))
	{
		puts("1");
		for(i=0;i<n/2;i++)
		{
			printf("01");
		}
		puts("");
		return 0;
	}
	for(i=1;i<20;i++)
	{
		x=(1<<i);
		if(ck(x))
		{
			printf("%d\n",x);
			puts(ans+1);
			return 0;
		}
	}
	puts("-1");
	return 0;
}
/*
2 2 4
3 3 6
2 2 6 1 1
2 2 12 1 1
*/
