#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=(1<<18)+10;
struct node{int rka,rkb,id;}a[MAX];
char s[MAX],res[MAX];
int rk[MAX];
int main()
{
	int n,len,i,k,ans;
	scanf("%d",&n);
	scanf("%s",s);
	len=(1<<n);
	for(i=0;i<len;i++) rk[i]=s[i]-'a';
	for(k=0;k<n;k++)
	{
		for(i=0;i<len;i++) a[i]={rk[i],rk[i^(1<<k)],i};
		sort(a,a+len,[](node x,node y){
			if(x.rka==y.rka) return x.rkb<y.rkb;
			return x.rka<y.rka;
		});
		rk[a[0].id]=0;
		for(i=1;i<len;i++)
		{
			if(a[i].rka==a[i-1].rka && a[i].rkb==a[i-1].rkb)
			{
				rk[a[i].id]=rk[a[i-1].id];
			}
			else rk[a[i].id]=rk[a[i-1].id]+1;
		}
	}
	ans=0;
	for(i=0;i<len;i++)
	{
		if(rk[i]==0) ans=i;
	}
	for(i=0;i<len;i++) res[i]=s[i^ans];
	res[len]='\0';
	puts(res);
	return 0;
}
/*
拆位，对于每一位 i，相当于在每段 2^(i+1) 长度子串中，前后交换长度 2^i 的子串。
考虑从低位到高位，每次把字典序小的交换到前面？感觉不是很对。

考虑把所有 j 对应的字符串的排名都求出来。
根据上面的性质，长串等于两个短串拼接，所以可以倍增求。
每次重新计算排名即可。类似倍增求后缀数组。
*/
