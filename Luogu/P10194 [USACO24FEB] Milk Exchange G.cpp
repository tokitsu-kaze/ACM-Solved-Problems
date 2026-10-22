#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1.5e6+10;
int st[MAX];
void workl(int *x,int n,int *l)
{
	int i,top;
	top=0;
	for(i=n;i;i--)
	{
		while(top && x[st[top-1]]>=x[i]) l[st[--top]]=i+1;
		st[top++]=i;
	}
	while(top>0) l[st[--top]]=1;
}
void workr(int *x,int n,int *r)
{
	int i,top;
	top=0;
	for(i=1;i<=n;i++)
	{
		while(top && x[st[top-1]]>x[i]) r[st[--top]]=i-1;
		st[top++]=i;
	}
	while(top>0) r[st[--top]]=n;
}
int a[MAX],l[MAX],r[MAX];
ll sum[MAX];
int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=n+1;i<=3*n;i++) a[i]=a[i-n];
	workl(a,n*3,l);
	workr(a,n*3,r);
	for(i=0;i<=n;i++) sum[i]=0;
	for(i=n+1;i<=2*n;i++)
	{
		sum[0]+=a[i];
		sum[i-l[i]+1]-=a[i];
		sum[r[i]-i+1]-=a[i];
		sum[r[i]-l[i]+2]+=a[i];
	}
	for(i=1;i<=n;i++) sum[i]+=sum[i-1];
	for(i=1;i<=n;i++) sum[i]+=sum[i-1];
	for(i=1;i<=n;i++) printf("%lld\n",sum[i]);
	return 0;
}
/*
给一个循环数组，对于每个 k，求所有长度为 k 的区间的最小值之和。
考虑每个 ai 对答案的贡献，用单调栈求一下范围。
细节就是，ai=aj 时，钦定左边产生贡献。
然后问题转化成：在一个区间内，所有长度为 k 并且包含 ai 的子区间，是有贡献的。
发现对 k 的贡献是分段函数，中间一段是等差数列，用二次差分更新。
*/
