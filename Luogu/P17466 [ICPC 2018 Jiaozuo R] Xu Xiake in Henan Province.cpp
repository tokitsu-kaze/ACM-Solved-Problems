#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1000+10;
int main()
{
	int T,i,x,cnt;
	scanf("%d",&T);
	while(T--)
	{
		cnt=0;
		for(i=0;i<4;i++)
		{
			scanf("%d",&x);
			if(x>0) cnt++;
		}
		if(cnt==0) puts("Typically Otaku");
		else if(cnt==1) puts("Eye-opener");
		else if(cnt==2) puts("Young Traveller");
		else if(cnt==3) puts("Excellent Traveller");
		else puts("Contemporary Xu Xiake");
	}
	return 0;
}
