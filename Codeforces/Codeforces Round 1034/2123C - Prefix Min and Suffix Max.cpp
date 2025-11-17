#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX],premn[MAX],sufmx[MAX];
char s[MAX];
int main()
{
	int T,n,i;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		premn[0]=INF;
		for(i=1;i<=n;i++) premn[i]=min(premn[i-1],a[i]);
		sufmx[n+1]=-INF;
		for(i=n;i;i--) sufmx[i]=max(sufmx[i+1],a[i]);
		s[1]=s[n]='1';
		for(i=2;i<n;i++)
		{
			if(a[i]==premn[i] || a[i]==sufmx[i]) s[i]='1';
			else s[i]='0';
		}
		s[n+1]='\0';
		puts(s+1);
	}
	return 0;
}
