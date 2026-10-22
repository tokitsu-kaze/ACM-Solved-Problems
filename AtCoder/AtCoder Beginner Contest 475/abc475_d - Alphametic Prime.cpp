#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=8000+10;
//x is a prime if prime[x]==x(x>=2)
const int V=1e7;
int p[V+5],tot,prime[V+5];
void init_prime()
{
	int i,j;
	tot=0;
	memset(prime,0,sizeof prime);
	prime[1]=1;
	for(i=2;i<=V;i++)
	{
		if(!prime[i]) prime[i]=p[tot++]=i;
		for(j=0;j<tot&&p[j]*i<=V;j++)
		{
			prime[i*p[j]]=p[j];
			if(i%p[j]==0) break;
		}
	}
}
int main()
{
	init_prime();
	int n,i,j,k,ok,ans;
	char s[11],mp1[26],mp2[12];
	scanf("%s",s);
	n=strlen(s);
	ans=-1;
	for(i=0;i<tot;i++)
	{
		string tmp=to_string(p[i]);
		if(tmp.size()<n) continue;
		if(tmp.size()>n) break;
		memset(mp1,0,sizeof mp1);
		memset(mp2,0,sizeof mp2);
		ok=1;
		for(j=0;j<n;j++)
		{
			if(mp1[s[j]-'a'] || mp2[tmp[j]-'0'])
			{
				if(mp1[s[j]-'a']!=tmp[j]) ok=0;
				if(mp2[tmp[j]-'0']!=s[j]) ok=0;
			}
			mp1[s[j]-'a']=tmp[j];
			mp2[tmp[j]-'0']=s[j];
		}
		if(ok)
		{
			ans=p[i];
			break;
		}
	}
	printf("%d\n",ans);
	return 0;
}
