#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int MAX=1000+10;
bool vis[MAX];
int ask(int x,int y)
{
	int res;
	cout<<"? "<<x<<" "<<y<<endl;
	cin>>res;
	return res;
}
int main()
{
	int t,n,i,j,res;
	cin>>t;
	while(t--)
	{
		cin>>n;
		set<pair<int,int>> ans;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++) vis[j]=0;
			vis[i]=1;
			j=1;
			while(1)
			{
				while(j<=n && (vis[j] ||
					 ans.count({i,j}) ||
					 ans.count({j,i}))) j++;
				if(j>n) break;
				res=ask(i,j);
				vis[j]=1;
				if(res==i)
				{
					if(i<j) ans.insert({i,j});
					else ans.insert({j,i});
					break;
				}
				j=res;
			}
		}
		cout<<"!";
		for(auto &it:ans) cout<<" "<<it.first<<" "<<it.second;
		cout<<endl;
	}
	return 0;
}
