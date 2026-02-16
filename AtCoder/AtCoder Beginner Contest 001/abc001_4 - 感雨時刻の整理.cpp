#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1440+10;
int flag[MAX];
int main()
{
	int n,x,y,i,j;
	scanf("%d",&n);
	memset(flag,0,sizeof flag);
	for(i=1;i<=n;i++)
	{
		scanf("%d-%d",&x,&y);
		x=(x/100)*60+(x%100);
		y=(y/100)*60+(y%100);
		while(x%5) x--;
		while(y%5) y++;
		for(j=x;j<=y;j++) flag[j]=1;
	}
	for(i=0;i<=MAX-10;i++)
	{
		if(!flag[i]) continue;
		for(j=i;j<=MAX-10;j++)
		{
			if(flag[j+1]) continue;
			printf("%02d%02d",i/60,i%60);
			printf("-%02d%02d\n",j/60,j%60);
			i=j;
			break;
		}
	}
	return 0;
}
