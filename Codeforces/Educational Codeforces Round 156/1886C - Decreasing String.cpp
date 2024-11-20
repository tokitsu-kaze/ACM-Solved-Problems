#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e6+10;
char s[MAX];
int l[MAX],r[MAX];
bool vis[MAX];
int main()
{
	int t,n,i,now,x;
	ll k;
	string res;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s+1);
		scanf("%lld",&k);
		n=strlen(s+1);
		for(i=0;i<=n+1;i++)
		{
			l[i]=i-1;
			r[i]=i+1;
			vis[i]=0;
		}
		priority_queue<int> q;
		for(i=1;i<n;i++)
		{
			if(s[i]>s[i+1]) q.push(-i);
		}
		now=n;
		while(!q.empty())
		{
			if(k-now<=0) break;
			k-=now;
			now--;
			x=-q.top();
			q.pop();
			if(l[x]>=1) r[l[x]]=r[x];
			if(r[x]<=n) l[r[x]]=l[x];
			vis[x]=1;
			x=l[x];
			if(x>=1 && r[x]<=n)
			{
				if(s[x]>s[r[x]]) q.push(-x);
			}
		}
		while(now>1 && k-now>0)
		{
			k-=now;
			now--;
		}
		for(i=1;i<=n;i++)
		{
			if(vis[i]) continue;
			k--;
			if(k==0)
			{
				res+=s[i];
				break;
			}
		}
	}
	cout<<res<<"\n";
	return 0;
}

