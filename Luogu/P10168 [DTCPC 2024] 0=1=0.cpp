#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2e5+10;
char s[MAX];
int main()
{
	int n,i,cnt[2],tmp[2];
	ll ans;
	scanf("%s",s+1);
	n=strlen(s+1);
	memset(tmp,0,sizeof tmp);
	for(i=1;i<=n;i++) tmp[s[i]-'0']++;
	cnt[0]=n/2;
	cnt[1]=n-n/2;
	if(tmp[1]%2!=cnt[1]%2) swap(cnt[0],cnt[1]);
	if(tmp[1]%2!=cnt[1]%2)
	{
		cnt[1]++;
		cnt[0]--;
	}
	ans=1ll*cnt[0]*cnt[1];
	vector<int> res;
	for(i=1;i<=cnt[0];i++)
	{
		if(s[i]=='1')
		{
			s[i]^=1;
			s[i+1]^=1;
			res.push_back(i);
		}
	}
	for(i=cnt[0]+1;i<n;i++)
	{
		if(s[i]=='0')
		{
			s[i]^=1;
			s[i+1]^=1;
			res.push_back(i);
		}
	}
	printf("%lld\n",ans);
	printf("%d\n",res.size());
	for(i=0;i<res.size();i++) printf("%d%c",res[i]," \n"[i==res.size()-1]);
	return 0;
}

