#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
int v[MAX],n;
int ck(int x,int y)
{
	int i,cnt;
	cnt=0;
	for(i=1;i<=n;i++)
	{
		if(abs(v[i]-x)>abs(v[i]-y)) cnt++;
	}
	return cnt;
}
int main()
{
	int T,a,i;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&a);
		for(i=1;i<=n;i++) scanf("%d",&v[i]);
		if(ck(a,a+1)>ck(a,a-1)) printf("%d\n",a+1);
		else printf("%d\n",a-1);
	}
	return 0;
}
