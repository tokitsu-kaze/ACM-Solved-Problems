#include <bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
char s[3][MAX];
int n;
int ck(int k)
{
	int i,x,y,z;
	x=y=0;
	for(i=0;i<n;i++)
	{
		if(s[0][i]==s[1][i]) x++;
		if(s[0][i]==s[2][i]) y++;
	}
	z=n;
	for(i=0;i<n;i++)
	{
		if(s[1][i]==s[2][i] && s[1][i]!=s[0][i])
		{
			if(z>k)
			{
				z--;
				x++;
				y++;
			}
		}
	}
	if(min(x,y)>=k) return 1;
	for(i=0;i<n;i++)
	{
		if(x<k)
		{
			if(s[1][i]!=s[0][i] && s[1][i]!=s[2][i])
			{
				if(z>k)
				{
					z--;
					x++;
					y--;
				}
			}
		}
		else if(y<k)
		{
			if(s[2][i]!=s[0][i] && s[1][i]!=s[2][i])
			{
				if(z>k)
				{
					z--;
					y++;
					x--;
				}
			}
		}
	}
	return min(x,y)>=k;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t,i,l,r,mid;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=0;i<3;i++) cin>>s[i];
		l=0;
		r=n;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(ck(mid+1)) l=mid+1;
			else r=mid;
		}
		cout<<l<<"\n";
	}
	return 0;
}

