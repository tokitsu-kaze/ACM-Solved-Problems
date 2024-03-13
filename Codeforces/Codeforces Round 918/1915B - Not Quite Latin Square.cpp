#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int t,i,j,n;
	char mp[5][5],ans;
	scanf("%d",&t);
	n=3;
	while(t--)
	{
		for(i=0;i<n;i++)
		{
			scanf("%s",mp[i]);
			set<char> s;
			for(j=0;j<n;j++)
			{
				if(mp[i][j]!='?') s.insert(mp[i][j]);
			}
			if(s.size()!=3)
			{
				for(j=0;j<3;j++)
				{
					if(!s.count('A'+j)) ans='A'+j;
				}
			}
		}
		printf("%c\n",ans);
		
	}
	return 0;
}
