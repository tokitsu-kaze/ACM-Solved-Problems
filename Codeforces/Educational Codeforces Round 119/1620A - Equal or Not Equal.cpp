#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int main()
{
	int T,n,i,cnt;
	char s[55];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		cnt=0;
		for(i=1;i<=n;i++)
		{
			if(s[i]=='N') cnt++;
		}
		if(cnt==1) puts("NO");
		else puts("YES");
	}
	return 0;
}

