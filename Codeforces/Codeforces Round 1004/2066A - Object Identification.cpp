#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int mod=998244353;
const int MAX=2e5+10;
int a[MAX],pos[MAX];
int ask(int x,int y)
{
	cout<<"? "<<x<<" "<<y<<endl;
	int res;
	cin>>res;
	return res;
}
int main()
{
	int T,n,i,permu,res;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) pos[i]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			pos[a[i]]=i;
		}
		permu=1;
		for(i=1;i<=n;i++)
		{
			if(!pos[i]) permu=0;
		}
		if(permu)
		{
			res=ask(pos[1],pos[n]);
			if(res<n-1) cout<<"! A"<<endl;
			else if(res>n-1) cout<<"! B"<<endl;
			else
			{
				res=ask(pos[n],pos[1]);
				if(res==n-1) cout<<"! B"<<endl;
				else cout<<"! A"<<endl;
			}
		}
		else
		{
			for(i=1;i<=n;i++)
			{
				if(!pos[i])
				{
					if(i==1) res=ask(i,n);
					else res=ask(i,1);
					if(res==0) cout<<"! A"<<endl;
					else cout<<"! B"<<endl;
					break;
				}
			}
		}
	}
	return 0;
}
