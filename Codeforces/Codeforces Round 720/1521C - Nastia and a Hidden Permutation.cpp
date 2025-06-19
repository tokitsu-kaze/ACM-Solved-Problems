#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int ask(int t,int i,int j,int x)
{
	cout<<"? "<<t<<" "<<i<<" "<<j<<" "<<x<<endl;
	int ans;
	cin>>ans;
	return ans;
}
int res[MAX];
int main()
{
	int T,n,i,pos1,tmp;
	cin>>T;
	while(T--)
	{
		cin>>n;
		pos1=n;
		for(i=1;i+1<=n;i+=2)
		{
			tmp=ask(2,i,i+1,1);
			if(tmp==1)
			{
				pos1=i;
				break;
			}
			else if(tmp==2)
			{
				if(ask(2,i+1,i,1)==1)
				{
					pos1=i+1;
					break;
				}
			}
		}
		res[pos1]=1;
		for(i=1;i<=n;i++)
		{
			if(i==pos1) continue;
			res[i]=ask(1,pos1,i,n-1);
		}
		cout<<"!";
		for(i=1;i<=n;i++) cout<<" "<<res[i];
		cout<<endl;
	}
	return 0;
}
