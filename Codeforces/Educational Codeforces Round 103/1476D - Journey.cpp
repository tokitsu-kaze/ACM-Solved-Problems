#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
char s[MAX];
int l[MAX],r[MAX];
int main()
{
	int T,n,i;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		l[0]=0;
		if(s[1]=='L') l[1]=1;
		else l[1]=0;
		for(i=2;i<=n;i++)
		{
			if(s[i]=='R') l[i]=0;
			else // s[i]=='L'
			{
				if(s[i-1]=='L') l[i]=1;
				else l[i]=l[i-2]+2;
			}
		}
		r[n]=0;
		if(s[n]=='R') r[n-1]=1;
		else r[n-1]=0;
		for(i=n-2;~i;i--)
		{
			if(s[i+1]=='L') r[i]=0;
			else // s[i+1]=='R'
			{
				if(s[i+2]=='R') r[i]=1;
				else r[i]=r[i+2]+2;
			}
		}
		for(i=0;i<=n;i++) printf("%d%c",l[i]+r[i]+1," \n"[i==n]);
	}
	return 0;
}

