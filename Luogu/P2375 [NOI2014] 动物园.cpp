#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e6+10;
const ll mod=1e9+7;
struct KMP
{
	int nex[MAX],len;
	char t[MAX];
	void get_next(char *s)
	{
		int i,j;
		len=strlen(s+1);
		for(i=1;i<=len;i++) t[i]=s[i];
		t[len+1]='\0';
		nex[0]=nex[1]=0;
		j=0;
		for(i=2;i<=len;i++)
		{
			while(j&&t[j+1]!=s[i]) j=nex[j];
			if(t[j+1]==s[i]) j++;
			nex[i]=j;
		}
	}
	
	// s[1..n], return all pos t in s 
	vector<int> match(char *s)
	{
		int n,i,j;
		vector<int> res;
		n=strlen(s+1);
		for(i=1,j=0;i<=n;i++)
		{
			while(j&&t[j+1]!=s[i]) j=nex[j];
			if(t[j+1]==s[i]) j++;
			if(j==len)
			{
				res.push_back(i-len+1);
				j=nex[j];
			}
		}
		return res;
	}
}kmp;// kmp.get_next(s); s[1..len]
char s[MAX];
int dep[MAX];
int main()
{
	int t,n,i,d,x;
	ll ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		kmp.get_next(s);
		dep[0]=1;
		ans=1;
		for(i=1;i<=n;i++)
		{
			dep[i]=dep[kmp.nex[i]]+1;
			if(kmp.nex[i]>=i/2)
			{
				d=i-kmp.nex[i];
				x=i-i/2/d*d;
				if(x*2==i) ans=ans*(dep[kmp.nex[x]]+1)%mod;
				else ans=ans*dep[kmp.nex[x]]%mod;
			}
			else ans=ans*dep[kmp.nex[i]]%mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
