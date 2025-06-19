#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
char s[MAX];
int main()
{
	int T,n,m,i,t,x;
	char a[3],b[3];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		scanf("%s",s+1);
		set<int> res[3][3];
		for(i=1;i<=m;i++)
		{
			scanf("%s%s",a,b);
			res[a[0]-'a'][b[0]-'a'].insert(i);
		}
		for(i=1;i<=n;i++)
		{
			if(s[i]=='a') continue;
			if(res[s[i]-'a'][0].size()>0)
			{
				res[s[i]-'a'][0].erase(*res[s[i]-'a'][0].begin());
				s[i]='a';
			}
			else
			{
				if(s[i]=='b') t=2;
				else t=1;
				if(res[s[i]-'a'][t].size()==0) continue;
				x=*res[s[i]-'a'][t].begin();
				auto it=res[t][0].lower_bound(x);
				if(it!=res[t][0].end())
				{
					res[s[i]-'a'][t].erase(x);
					res[t][0].erase(it);
					s[i]='a';
				}
			}
			if(s[i]=='c')
			{
				if(res[2][1].size()>0)
				{
					res[2][1].erase(res[2][1].begin());
					s[i]='b';
				}
			}
		}
		s[n+1]='\0';
		puts(s+1);
	}
	return 0;
}
