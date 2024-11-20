#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
const int mod=998244353;
char s[MAX][2];
vector<int> pos[11];
string make_string(char a,char b)
{
	string res="";
	res+=a;
	res+=b;
	return res;
}
int main()
{
	int t,n,q,x,y,i,j,tot,ans,p,nowid;
	map<string,int> id;
	string tmp="BGRY";
	tot=0;
	for(i=0;i<4;i++)
	{
		for(j=i+1;j<4;j++)
		{
			tot++;
			id[make_string(tmp[i],tmp[j])]=tot;
			id[make_string(tmp[j],tmp[i])]=tot;
		}
	}
//	for(auto &it:id) cout<<it.first<<" "<<it.second<<endl;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&q);
		for(i=1;i<=tot;i++) pos[i].clear();
		for(i=1;i<=n;i++)
		{
			scanf("%s",s[i]);
			pos[id[s[i]]].push_back(i);
		}
		while(q--)
		{
			scanf("%d%d",&x,&y);
			if(x==y)
			{
				puts("0");
				continue;
			}
			if(x>y) swap(x,y);
			ans=INF;
			for(i=0;i<2;i++)
			{
				for(j=0;j<2;j++)
				{
					if(s[x][i]==s[y][j])
					{
						ans=y-x;
						continue;
					}
					nowid=id[make_string(s[x][i],s[y][j])];
					auto it=lower_bound(pos[nowid].begin(),pos[nowid].end(),x);
					if(it!=pos[nowid].end())
					{
						p=*it;
						ans=min(ans,abs(p-x)+abs(p-y));
					}
					if(it!=pos[nowid].begin())
					{
						it--;
						p=*it;
						ans=min(ans,abs(p-x)+abs(p-y));
					}
				}
			}
			if(ans==INF) ans=-1;
			printf("%d\n",ans);
		}
	}
	return 0;
}

