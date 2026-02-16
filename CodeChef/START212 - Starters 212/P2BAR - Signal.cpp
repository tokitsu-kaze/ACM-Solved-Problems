#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=500+10;
int main()
{
	int T,n,i,cnt,f;
	char s[15];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		cnt=0;
		f=0;
		for(i=1;i<=n;i++)
		{
			if(s[i]=='0') f=1;
			if(f && s[i]=='1') cnt++;
		}
		printf("%d\n",cnt);
	}
	return 0;
}
