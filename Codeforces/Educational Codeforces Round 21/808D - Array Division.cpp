#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+10;
int a[MAX];
ll bit[MAX];
int main()
{
	int n,i,ok;
	scanf("%d",&n);
	bit[0]=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		bit[i]=bit[i-1]+a[i];
	}
	map<ll,int> mp;
	ok=0;
	for(i=1;i<=n;i++)
	{
		if(a[i]*2==bit[n]) ok=1;
		if(mp.count(-a[i]*2)) ok=1;
		mp[bit[i]-(bit[n]-bit[i])]=1;
	}
	if(mp.count(0)) ok=1;
	mp.clear();
	for(i=n;i;i--)
	{
		if(mp.count(-a[i]*2)) ok=1;
		mp[(bit[n]-bit[i])-bit[i]]=1;
	}
	if(ok) puts("YES");
	else puts("NO");
	return 0;
}
/*
5
1 1 4 1 1
5
1 3 2 2 2
*/
