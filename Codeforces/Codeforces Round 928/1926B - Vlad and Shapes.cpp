#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e3+10;
int main()
{
	int t,n,i,j,cnt,cnt2,f;
	char mp[22][22];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++) scanf("%s",mp[i]);
		cnt=0;
		f=0;
		for(i=0;i<n;i++)
		{
			cnt2=0;
			for(j=0;j<n;j++)
			{
				cnt+=mp[i][j]-'0';
				cnt2+=mp[i][j]-'0';
			}
			if(cnt2==1) f=1;
		}
		if(f)
		{
			if(cnt==1) puts("SQUARE");
			else puts("TRIANGLE");
		}
		else puts("SQUARE");
	}
	return 0;
}
