#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e4+10;
int main()
{
	int T,n,i,cnt,ans;
	char s[105];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		cnt=1;
		vector<int> res;
		for(i=2;i<=n;i++)
		{
			if(s[i]==s[i-1]) cnt++;
			else
			{
				if(s[i-1]=='1') res.push_back(cnt);
				cnt=1;
			}
		}
		if(s[n]=='1') res.push_back(cnt);
		sort(res.begin(),res.end());
		reverse(res.begin(),res.end());
		ans=0;
		for(i=0;i<res.size();i+=2) ans+=res[i];
		printf("%d\n",ans);
	}
	return 0;
}
