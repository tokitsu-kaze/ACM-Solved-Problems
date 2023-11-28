#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+10;
int flag[MAX];
int main()
{
	int t,n,i,j;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) flag[i]=0;
		set<int> s;
		for(i=2;i<=n;i+=2)
		{
			s.insert(i);
			flag[i]=1;
		}
		vector<int> res;
		for(i=3;i<=n;i++)
		{
			if(flag[i]) continue;
			vector<int> tmp;
			for(j=i;j<=n;j+=i)
			{
				if(flag[j]) continue;
				tmp.push_back(j);
				flag[j]=1;
			}
			reverse(tmp.begin(),tmp.end());
			for(j=1;j<tmp.size();j+=2)
			{
				res.push_back(tmp[j-1]);
				res.push_back(tmp[j]);
			}
			if(tmp.size()&1)
			{
				if(s.count(tmp.back()*2))
				{
					res.push_back(tmp.back());
					res.push_back(tmp.back()*2);
					s.erase(tmp.back()*2);
				}
			}
		}
		for(auto &it:s) res.push_back(it);
		if(res.size()&1) res.pop_back();
		printf("%d",res.size()/2);
		for(auto &it:res) printf(" %d",it);
		puts("");
	}
	return 0;
}
