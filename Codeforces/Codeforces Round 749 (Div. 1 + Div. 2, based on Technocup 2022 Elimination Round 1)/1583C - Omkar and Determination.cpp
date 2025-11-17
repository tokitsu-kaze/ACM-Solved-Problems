#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
vector<string> mp;
char s[MAX];
int sum[MAX];
int main()
{
	int n,m,q,i,j,l,r;
	scanf("%d%d",&n,&m);
	mp.clear();
	for(i=0;i<n;i++)
	{
		scanf("%s",s);
		mp.push_back(s);
	}
	sum[0]=0;
	for(j=1;j<m;j++)
	{
		sum[j]=0;
		for(i=1;i<n;i++)
		{
			if(mp[i-1][j]=='X' && mp[i][j-1]=='X')
			{
				sum[j]=1;
			}
		}
		sum[j]+=sum[j-1];
	}
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&l,&r);
		if(l==r)
		{
			puts("YES");
			continue;
		}
		l--;
		r--;
		if(sum[r]-sum[l]==0) puts("YES");
		else puts("NO");
	}
	return 0;
}
