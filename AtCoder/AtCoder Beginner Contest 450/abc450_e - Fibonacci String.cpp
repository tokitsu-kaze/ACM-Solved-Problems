#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e4+10;
char s[MAX];
int sum[3][MAX][26],tot;
ll cnt[111][26],len[111];
ll cal(ll k,int f)
{
	int i;
	ll res=0;
	for(i=tot;i>=1;i--)
	{
		if(k>len[i])
		{
			k-=len[i];
			res+=cnt[i][f];
//			cout<<i<<" "<<k<<" "<<cnt[i][f]<<endl;
		}
		else
		{
			if(i<=2)
			{
				res+=sum[i][k][f];
				break;
			}
		}
	}
	return res;
}
int main()
{
	int n,i,j,q;
	ll l,r;
	char ch[3];
	memset(cnt,0,sizeof cnt);
	memset(sum,0,sizeof sum);
	memset(len,0,sizeof len);
	scanf("%s",s+1);
	n=strlen(s+1);
	len[1]=n;
	for(i=1;i<=n;i++)
	{
		for(j=0;j<26;j++) sum[1][i][j]=sum[1][i-1][j];
		sum[1][i][s[i]-'a']++;
		cnt[1][s[i]-'a']++;
	}
	scanf("%s",s+1);
	n=strlen(s+1);
	len[2]=n;
	for(i=1;i<=n;i++)
	{
		for(j=0;j<26;j++) sum[2][i][j]=sum[2][i-1][j];
		sum[2][i][s[i]-'a']++;
		cnt[2][s[i]-'a']++;
	}
	tot=0;
	for(i=3;;i++)
	{
		len[i]=len[i-1]+len[i-2];
		for(j=0;j<26;j++) cnt[i][j]=cnt[i-1][j]+cnt[i-2][j];
		if(len[i]>1e18)
		{
			tot=i;
			break;
		}
	}
	scanf("%d",&q);
	while(q--)
	{
		scanf("%lld%lld%s",&l,&r,ch);
		printf("%lld\n",cal(r,ch[0]-'a')-cal(l-1,ch[0]-'a'));
	}
	return 0;
}
/*
cde 3
ab 2
abcde 5
abcdeab 7
abcdeababcde 12

cde
ab
3
1 9 a
1 9 c
1 10 c

*/
