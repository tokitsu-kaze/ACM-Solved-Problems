#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e6+10;
void assert_range(ll x,ll l,ll r){assert(x>=l&&x<=r);}
char s[MAX];
int main()
{
	int n,q,l,r,i,ans;
	cin>>n>>q;
	assert_range(n,1,1e6);
	assert_range(q,1,2e5);
	cin>>s+1;
	s[0]='0';
	s[n+1]='0';
	ans=0;
	for(i=1;i<=n;i++)
	{
		ans+=(s[i]!=s[i-1]&&s[i]=='1');
		assert_range(s[i],'0','1');
	}
	while(q--)
	{
		cin>>l>>r;
		assert_range(l,1,n);
		assert_range(r,l,n);
		if(s[l]==s[r])
		{
			printf("%d\n",ans);
			continue;
		}
		if(s[l-1]==s[l]&&s[r+1]==s[r]) printf("%d\n",ans+1);
		else if(s[l-1]!=s[l]&&s[r+1]!=s[r]) printf("%d\n",ans-1);
		else printf("%d\n",ans);
		/*
		11...00
		11...01
		01...00
		01...01
		*/
	}
	return 0;
}

