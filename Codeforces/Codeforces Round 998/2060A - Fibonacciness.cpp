#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
int a[11];
int cal(int x)
{
	int i,cnt;
	cnt=0;
	a[3]=x;
	for(i=1;i<=3;i++)
	{
		if(a[i]+a[i+1]==a[i+2]) cnt++;
	}
	return cnt;
}
int main()
{
	int T,i;
	scanf("%d",&T);
	while(T--)
	{
		for(i=1;i<=5;i++)
		{
			if(i==3) continue;
			else scanf("%d",&a[i]);
		}
		printf("%d\n",max(cal(a[1]+a[2]),cal(a[5]-a[4])));
	}
	return 0;
}

