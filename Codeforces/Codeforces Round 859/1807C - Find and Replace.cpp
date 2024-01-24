#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
const int mod=998244353;
char s[MAX];
int main()
{
	int t,n,i,ok,flag[33],f;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		memset(flag,0,sizeof flag);
		ok=0;
		for(i=1;i<=n;i++) flag[s[i]-'a']|=1<<(i&1);
		f=1;
		for(i=0;i<26;i++)
		{
			if(flag[i]==3) f=0;
		}
		ok|=f;
		for(i=1;i<=n;i++) flag[s[i]-'a']|=1<<(!(i&1));
		f=1;
		for(i=0;i<26;i++)
		{
			if(flag[i]==3) f=0;
		}
		ok|=f;
		if(!ok) puts("NO");
		else puts("YES");
	}
	return 0;
}
