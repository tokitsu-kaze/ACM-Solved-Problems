#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int p[MAX],n;
int work1()
{
	int i,res;
	res=0;
	for(i=1;i<=n;i++) res+=(p[i]==i);
	return (res+1)/2;
}
int work2()
{
	if(!(n&1)) return INF;
	int i,res,pos;
	res=0;
	pos=(n+1)/2;
	if(p[(n+1)/2]!=(n+1)/2)
	{
		res++;
		for(i=1;i<=n;i++)
		{
			if(p[i]==(n+1)/2)
			{
				swap(p[i],p[(n+1)/2]);
				pos=i;
				break;
			}
		}
	}
	for(i=1;i<=n/2;i++) res+=(p[i]<=n/2);
	swap(p[pos],p[(n+1)/2]);
	return res;
}
int main()
{
	int T,i;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&p[i]);
		printf("%d\n",min(work1(),work2()));
	}
	return 0;
}

