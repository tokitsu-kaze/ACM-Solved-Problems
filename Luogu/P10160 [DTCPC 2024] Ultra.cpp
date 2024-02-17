#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e6+10;
struct node{int l,r;};
char s[MAX];
int main()
{
	int n,i,j,pre,ans;
	scanf("%s",s+1);
	n=strlen(s+1);
	vector<node> tmp;
	pre=-1;
	for(i=1;i<=n;i++)
	{
		if(pre==-1)
		{
			if(s[i]=='1') pre=i;
		}
		else
		{
			if(((s[i]-'0')^1)!=((i-pre)&1))
			{
				if(s[i]=='1')
				{
					if((i-1)-pre+1>=3) tmp.push_back({pre,i-1});
					pre=i;
				}
				else
				{
					if((i-2)-pre+1>=3) tmp.push_back({pre,i-2});
					pre=-1;
				}
			}
		}
	}
	if(s[n]=='1'&&pre!=-1&&pre!=n) tmp.push_back({pre,n});
//	for(auto &it:tmp) printf("%d %d\n",it.l,it.r);
	vector<node> res;
	if(!tmp.size())
	{
		ans=0;
		for(i=1;i<=n;i++) ans+=s[i]-'0';
		printf("%d\n",ans);
		return 0;
	}
	while(tmp[0].l>0&&s[tmp[0].l-1]=='1') tmp[0].l--;
	res.push_back(tmp[0]);
	for(i=1;i<tmp.size();i++)
	{
		while(res.back().r<tmp[i].l&&s[res.back().r+1]=='1') res.back().r++;
		while(tmp[i].l>res.back().r&&s[tmp[i].l-1]=='1') tmp[i].l--;
		if(res.back().r==tmp[i].l) res.back().r=tmp[i].r;
		else res.push_back(tmp[i]);
	}
	while(res.back().r<n&&s[res.back().r+1]=='1') res.back().r++;
	for(auto &it:res)
	{
		for(i=it.l;i<=it.r;i++) s[i]='0';
	}
	ans=res.size();
	for(i=1;i<=n;i++) ans+=s[i]-'0';
	printf("%d\n",ans);
	return 0;
}
/*
10111101
01011101
00101101
00010101
00001010
111011
110101
*/
