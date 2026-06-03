#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX],b[MAX],n;
int ck(int x)
{
	int i,cnt,pos;
	pos=2e9;
	cnt=0;
	for(i=n;i;i--)
	{
		if(b[i]<a[i]) pos=min(pos,a[i]-b[i]);
		else
		{
			if(b[i]-a[i]+1<=x) return 1;
			if(pos>a[i])
			{
				cnt++;
				if(cnt>x) return 0;
			}
		}
	}
	return 1;
}
int main()
{
	int i,l,r,mid;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=n;i++) scanf("%d",&b[i]);
	l=0;
	r=n+1;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(ck(mid)) r=mid;
		else l=mid+1;
	}
	printf("%d\n",l);
	return 0;
}
/*
bi<ai不用管。
bi>=ai，要么把机器人 i 销毁，要么将bi减少到ai-1。
二分答案很有道理啊。
先看看能不能减少，能直接成功。
否则考虑销毁。维护当前能达到的最近的位置pos。
如果pos>ai，考虑什么时候销毁。如果要马上进行销毁，
有没有一种可能，先让机器人 i 销毁别人，然后再销毁它？
首先如果能让别人销毁它，那肯定不用花费操作次数，否则必须要花费次数。
那么假设它走了k步，就需要k+1次数来销毁它，所以立马销毁肯定不劣。
*/
