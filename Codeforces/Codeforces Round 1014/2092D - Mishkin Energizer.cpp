#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,i,cnt[4],id[128],res[4],ok,pos;
	char rid[4];
	string s;
	memset(id,0,sizeof id);
	id['L']=1;
	id['I']=2;
	id['T']=3;
	rid[1]='L';
	rid[2]='I';
	rid[3]='T';
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		cin>>s;
		memset(cnt,0,sizeof cnt);
		for(i=0;i<n;i++) cnt[id[s[i]]]++;
		pos=-1;
		for(i=0;i<n-1;i++)
		{
			if(s[i]!=s[i+1])
			{
				pos=i;
				break;
			}
		}
		if(pos==-1)
		{
			puts("-1");
			continue;
		}
		for(i=1;i<=3;i++) res[i]=i;
		vector<int> ans;
		while(1)
		{
			sort(res+1,res+4,[&](int x,int y){
				return cnt[x]<cnt[y];
			});
			if(cnt[res[1]]==cnt[res[3]]) break;
			ok=0;
			for(i=0;i<s.size()-1;i++)
			{
				if(s[i]==s[i+1]) continue;
				if(id[s[i]]!=res[1] && id[s[i+1]]!=res[1])
				{
					s.insert(i+1,1,rid[res[1]]);
					ans.push_back(i);
					cnt[res[1]]++;
					ok=1;
					break;
				}
			}
			if(ok) continue;
			for(i=0;i<s.size()-1;i++)
			{
				if(s[i]==s[i+1]) continue;
				if(id[s[i]]!=res[2] && id[s[i+1]]!=res[2])
				{
					s.insert(i+1,1,rid[res[2]]);
					ans.push_back(i);
					cnt[res[2]]++;
					ok=1;
					break;
				}
			}
			assert(ok);
		}
		printf("%d\n",(int)ans.size());
		for(auto &it:ans) printf("%d\n",it+1);
	}
	return 0;
}
/*
AAAABBB
AAAACBCACACBCBCBBB
AAAACBBB
AAAACACACBCBCBCBBB

AAACACACBBBBC
BBBBAA
AACACACACBBBB
*/
