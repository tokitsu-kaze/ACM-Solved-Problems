#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int n,a[MAX],b[MAX];
int gao1()
{
	sort(b+1,b+1+n);
	return (b[1]+1)/2+(b[2]+1)/2;
}
int gao2()
{
	int i,res,tmp;
	res=1e9;
	for(i=2;i<n;i++)
	{
		tmp=min(a[i-1],a[i+1]);
		res=min(res,tmp+(a[i-1]-tmp+1)/2+(a[i+1]-tmp+1)/2);
	}
	return res;
}
int gao3()
{
	int i,res,tmp;
	res=1e9;
	for(i=2;i<=n;i++)
	{
		if(a[i-1]<=(a[i]+1)/2 || a[i]<=(a[i-1]+1)/2)
		{
			res=min(res,(max(a[i-1],a[i])+1)/2);
			continue;
		}
		res=min(res,(a[i-1]+a[i]+2)/3);
	}
	return res;
}
int main()
{
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	printf("%d\n",min({gao1(),gao2(),gao3()}));
	return 0;
}
/*
1. (最小两个+1)/2
2. a[i-1], a[i+1]
3. 相邻两个

2
5 5
*/
