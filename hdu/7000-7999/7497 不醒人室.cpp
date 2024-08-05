#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+10;
int b[MAX],e[MAX],s[MAX],t[MAX];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T,n,m,i,j,ok,mx;
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		for(i=1;i<=n;i++) cin>>b[i]>>e[i];
		for(i=1;i<=m;i++) cin>>s[i]>>t[i];
		j=0;
		ok=1;
		mx=-1;
		for(i=1;i<=n;i++)
		{
			while(j<=m && t[j]<=b[i])
			{
				mx=max(mx,t[j]+2*(t[j]-s[j]));
				j++;
			}
			if(mx<e[i]) ok=0;
			while(j<=m && s[j]<e[i]) j++;
		}
		cout<<(ok?"Yes\n":"No\n");
	}
	return 0;
}
