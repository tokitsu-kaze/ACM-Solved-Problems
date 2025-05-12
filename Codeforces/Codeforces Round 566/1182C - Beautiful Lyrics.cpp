#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
int cal(char c)
{
	if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u') return 1;
	return 0;
}
char ss[MAX];
int main()
{
	int n,i,j,tot,cnt;
	char lst;
	scanf("%d",&n);
	map<string,int> ha;
	vector<string> rha;
	map<pair<int,char>,vector<int>> mp;
	tot=0;
	while(n--)
	{
		scanf("%s",ss);
		string s=string(ss);
		if(!ha.count(s))
		{
			ha[s]=tot++;
			rha.push_back(s);
		}
		cnt=0;
		lst='^';
		for(auto &it:s)
		{
			if(cal(it))
			{
				cnt++;
				lst=it;
			}
		}
		mp[{cnt,lst}].push_back(ha[s]);
	}
	vector<int> ra,rb,tmp;
	for(auto &it:mp)
	{
		for(i=1;i<it.second.size();i+=2)
		{
			rb.push_back(it.second[i-1]);
			rb.push_back(it.second[i]);
		}
		if(it.second.size()&1)
		{
			tmp.push_back(it.second.back());
		}
	}
	for(i=1;i<tmp.size();i++)
	{
		cnt=0;
		for(auto &it:rha[tmp[i-1]]) cnt+=cal(it);
		for(auto &it:rha[tmp[i]]) cnt-=cal(it);
		if(cnt==0)
		{
			ra.push_back(tmp[i-1]);
			ra.push_back(tmp[i]);
			i++;
		}
	}
	vector<pair<int,int>> res;
	i=j=0;
	while(i+1<ra.size() && j+1<rb.size())
	{
		res.push_back({ra[i],rb[j]});
		res.push_back({ra[i+1],rb[j+1]});
		i+=2;
		j+=2;
	}
	while(j+3<rb.size())
	{
		res.push_back({rb[j],rb[j+2]});
		res.push_back({rb[j+1],rb[j+3]});
		j+=4;
	}
	printf("%d\n",(int)res.size()/2);
	for(auto &it:res)
	{
		printf("%s ",rha[it.first].c_str());
		puts(rha[it.second].c_str());
	}
	return 0;
}

