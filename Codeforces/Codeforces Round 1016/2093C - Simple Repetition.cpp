#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5000+10;
int ck(int x)
{
	if(x==1) return 0;
	int i;
	for(i=2;i*i<=x;i++)
	{
		if(x%i==0) return 0;
	}
	return 1;
}
int main()
{
	int T,x,i,k;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&x,&k);
		if(x==1)
		{
			k--;
			while(k--) x=x*10+1;
			if(ck(x)) puts("YES");
			else puts("NO");
			continue;
		}
		if(k==1)
		{
			if(ck(x)) puts("YES");
			else puts("NO");
		}
		else puts("NO");
	}
	return 0;
}

