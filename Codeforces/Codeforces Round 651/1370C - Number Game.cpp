#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=5e5+10;
int main()
{
	int t,n,i,sq,cnt,cnt2;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		if(n==1)
		{
			puts("FastestFinger");
			continue;
		}
		if((n&1) || n==2)
		{
			puts("Ashishgup");
			continue;
		}
		sq=sqrt(n+0.5);
		cnt=cnt2=0;
		for(i=2;i<=sq;i++)
		{
			while(n%i==0)
			{
				n/=i;
				if(i&1) cnt++;
				else if(i==2) cnt2++;
			}
		}
		if(n>1&&(n&1)) cnt++;
		if(cnt2==1 && cnt>0) cnt--;
		if(cnt) puts("Ashishgup");
		else puts("FastestFinger");
	}
	return 0;
}

