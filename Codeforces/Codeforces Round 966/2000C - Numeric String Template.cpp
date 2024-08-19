#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
int a[MAX];
char s[MAX];
int main()
{
	int t,n,i,m,len,ok;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		scanf("%d",&m);
		while(m--)
		{
			scanf("%s",s+1);
			len=strlen(s+1);
			if(len!=n)
			{
				puts("NO");
				continue;
			}
			map<int,char> mp;
			map<char,int> revmp;
			ok=1;
			for(i=1;i<=len;i++)
			{
				if(!mp.count(a[i])&&!revmp.count(s[i]))
				{
					mp[a[i]]=s[i];
					revmp[s[i]]=a[i];
				}
				else if(mp.count(a[i])&&revmp.count(s[i]))
				{
					if(mp[a[i]]!=s[i] || revmp[s[i]]!=a[i]) ok=0;
				}
				else ok=0;
			}
			if(ok) puts("YES");
			else puts("NO");
		}
	}
	return 0;
}
