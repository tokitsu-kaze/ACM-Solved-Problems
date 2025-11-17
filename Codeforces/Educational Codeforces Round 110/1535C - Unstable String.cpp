#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
char s[MAX];
int nex[MAX];
int main()
{
	int T,n,i,j;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		nex[n+1]=n+1;
		for(i=n;i;i--)
		{
			if(s[i]!='?') nex[i]=i;
			else nex[i]=nex[i+1];
		}
		ans=0;
		for(i=1,j=1;i<=n;i++)
		{
			j=max(j,i);
			while(j+1<=n)
			{
				if(s[j+1]=='?')
				{
					j++;
					continue;
				}
				if(nex[i]%2==(j+1)%2)
				{
					if(s[nex[i]]==s[j+1]) j++;
					else break;
				}
				else
				{
					if(s[nex[i]]!=s[j+1]) j++;
					else break;
				}
			}
//			cout<<i<<" "<<j<<endl;
			ans+=j-i+1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}

