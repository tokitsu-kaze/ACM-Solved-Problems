#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e7+10;
int a[MAX];
namespace GenHelper
{
    unsigned z1, z2, z3, z4, b;
    unsigned rand_()
    {
        b = ((z1 << 6) ^ z1) >> 13;
        z1 = ((z1 & 4294967294U) << 18) ^ b;
        b = ((z2 << 2) ^ z2) >> 27;
        z2 = ((z2 & 4294967288U) << 2) ^ b;
        b = ((z3 << 13) ^ z3) >> 21;
        z3 = ((z3 & 4294967280U) << 7) ^ b;
        b = ((z4 << 3) ^ z4) >> 12;
        z4 = ((z4 & 4294967168U) << 13) ^ b;
        return (z1 ^ z2 ^ z3 ^ z4);
    }
}
void srand_(unsigned x, int n)
{
    using namespace GenHelper;
    z1 = x;
    z2 = (~x) ^ 0x233333333U;
    z3 = x ^ 0x1234598766U;
    z4 = (~x) + 51;
    for (int i = 1; i <= n; ++i)
        a[i] = i;
    if (!x)
        return;
    for (int i = 1; i <= n; ++i)
    {
        int j = rand_() % i + 1, k;
        k = a[i], a[i] = a[j], a[j] = k;
    }
}
int pos[MAX],pre[MAX][2],nex[MAX][2],l[MAX],r[MAX];
void del(int x)
{
	r[l[x]]=r[x];
	l[r[x]]=l[x];
}
int main()
{
	int n,s,i,x,p;
	ll ans;
	scanf("%d%d",&n,&s);
	srand_(s,n);
	for(i=1;i<=n;i++)
	{
		pos[a[i]]=i;
		l[i]=i-1;
		r[i]=i+1;
	}
	for(i=1;i<=n;i++)
	{
		x=pos[i];
		pre[x][0]=l[x];
		pre[x][1]=l[l[x]];
		nex[x][0]=r[x];
		nex[x][1]=r[r[x]];
		del(x);
	}
	ans=n;
	for(i=1;i<=n;i++)
	{
		ans+=max(0,min(i-pre[i][0]-1,nex[i][0]-i-1));
		p=nex[pre[i][0]][0]-(pre[i][0]-pre[i][1]);
		if(i<=p && p<nex[i][0]) ans++;
		p=pre[nex[i][0]][0]+(nex[i][1]-nex[i][0]);
		if(pre[i][0]<p && p<=i) ans++;
	}
	printf("%lld\n",ans);
	return 0;
}
