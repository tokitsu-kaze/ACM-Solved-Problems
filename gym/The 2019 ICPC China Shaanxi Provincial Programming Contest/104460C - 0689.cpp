#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e6+10;
int bit[10];
char s[MAX];
int main()
{
	int t,n,i,j;
	ll ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		for(j=0;j<10;j++) bit[j]=0;
		ans=1;
		for(i=1;i<=n;i++)
		{
			bit[s[i]-'0']++;
			ans+=i;
			if(s[i]=='6') ans-=bit[9];
			else if(s[i]=='9') ans-=bit[6];
			else ans-=bit[s[i]-'0'];
		}
		if(bit[6]==n||bit[9]==n) ans--;
		printf("%lld\n",ans);
	}
	return 0;
}

