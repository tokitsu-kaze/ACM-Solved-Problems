#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const double eps=1e-9;
const int MAX=1e3+10;
char s[MAX];
int tag[MAX];
int main()
{
	int T,n,m,i,ok;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		scanf("%s",s+1);
		s[0]=s[n+1]='0';
		while(m--)
		{
			for(i=1;i<=n;i++) tag[i]=0;
			for(i=1;i<=n;i++)
			{
				if(s[i]=='1') continue;
				if((s[i-1]=='1')+(s[i+1]=='1')==1) tag[i]=1;
			}
			ok=0;
			for(i=1;i<=n;i++)
			{
				ok+=tag[i];
				s[i]^=tag[i];
			}
			if(!ok) break;
		}
		s[n+1]='\0';
		puts(s+1);
	}
	return 0;
}
