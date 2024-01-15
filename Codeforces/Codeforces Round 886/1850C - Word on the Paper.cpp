#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
int main()
{
	int t,n,i,j;
	char mp[11][11];
	scanf("%d",&t);
	while(t--)
	{
		n=8;
		for(i=0;i<n;i++) scanf("%s",mp[i]);
		string ans;
		for(j=0;j<n;j++)
		{
			for(i=0;i<n;i++)
			{
				if(mp[i][j]!='.') ans+=mp[i][j];
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
