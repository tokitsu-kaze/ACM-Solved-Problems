#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int mod=998244353;
const int MAX=2e6+10;
char s[MAX];
int cal(int l,int r)
{
	int i,len;
	int cnt[2]={0};
	len=r-l+1;
	assert(len%3==0);
	if(len==3)
	{
		for(i=l;i<=r;i++) cnt[s[i]-'0']++;
		if(cnt[0]>cnt[1]) return 0;
		else return 1;
	}
	cnt[cal(l,l+len/3-1)]++;
	cnt[cal(l+len/3,r-len/3)]++;
	cnt[cal(r-len/3+1,r)]++;
	if(cnt[0]>cnt[1]) return 0;
	else return 1;
}
int dp[MAX][15][2];
pair<int,int> dfs(int l,int r)
{
	int i,len;
	int cnt[2]={0};
	len=r-l+1;
	assert(len%3==0);
	if(len==3)
	{
		for(i=l;i<=r;i++) cnt[s[i]-'0']++;
		if(cnt[0]>cnt[1]) return {0,2-cnt[1]};
		else return {2-cnt[0],0};
	}
	auto it1=dfs(l,l+len/3-1);
	auto it2=dfs(l+len/3,r-len/3);
	auto it3=dfs(r-len/3+1,r);
	int res0,res1;
	res0=min({it1.first+it2.first,
			  it1.first+it3.first,
			  it2.first+it3.first});
	res1=min({it1.second+it2.second,
			  it1.second+it3.second,
			  it2.second+it3.second});
	return {res0,res1};
}
int main()
{
	int n;
	scanf("%d",&n);
	scanf("%s",s+1);
	n=strlen(s+1);
	int ans=cal(1,n);
	auto res=dfs(1,n);
	if(ans) printf("%d\n",res.first);
	else printf("%d\n",res.second);
	return 0;
}
