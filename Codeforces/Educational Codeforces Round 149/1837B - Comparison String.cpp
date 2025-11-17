#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int main()
{
	int T,n,i,cnt,mx;
	char s[105];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		cnt=1;
		mx=1;
		for(i=2;i<=n;i++)
		{
			if(s[i]==s[i-1]) cnt++;
			else cnt=1;
			mx=max(mx,cnt);
		}
		printf("%d\n",mx+1);
	}
	return 0;
}
