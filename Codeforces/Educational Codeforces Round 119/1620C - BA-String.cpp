#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2000+10;
char s[MAX];
ll suf[MAX];
int main()
{
	int T,n,k,i,j,cnt;
	ll x;
	string ans,tmp;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%lld",&n,&k,&x);
		scanf("%s",s+1);
		vector<int> res;
		tmp="";
		cnt=0;
		for(i=1;i<=n;i++)
		{
			if(s[i]=='a')
			{
				if(cnt*k>0)
				{
					res.push_back(cnt*k+1);
					tmp+="*";
				}
				cnt=0;
				tmp+=s[i];
			}
			else cnt++;
		}
		if(cnt*k>0)
		{
			res.push_back(cnt*k+1);
			tmp+="*";
		}
		if(res.size()==0)
		{
			puts(tmp.c_str());
			continue;
		}
		suf[res.size()]=1;
		for(i=res.size()-1;~i;i--)
		{
			if(suf[i+1]==-1) suf[i]=-1;
			else if(suf[i+1]>2*x/res[i]) suf[i]=-1;
			else suf[i]=suf[i+1]*res[i];
		}
		ans="";
		j=0;
		for(auto &it:tmp)
		{
			if(it=='*')
			{
				if(suf[j+1]==-1)
				{
					j++;
					continue;
				}
				for(i=2;i<=res[j];i++)
				{
					if(x-suf[j+1]<=0) break;
					x-=suf[j+1];
					ans+='b';
				}
				j++;
			}
			else ans+=it;
		}
		puts(ans.c_str());
	}
	return 0;
}

