#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
char s[MAX];
int n;
int cal(int ban)
{
	int l,r,cnt;
	cnt=0;
	l=1;
	r=n;
	while(l<r)
	{
		if(s[l]==s[r])
		{
			l++;
			r--;
		}
		else
		{
			if(s[l]-'a'==ban)
			{
				l++;
				cnt++;
			}
			else if(s[r]-'a'==ban)
			{
				r--;
				cnt++;
			}
			else return INF;
		}
	}
	return cnt;
}
int main()
{
	int T,i,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		ans=INF;
		for(i=0;i<26;i++) ans=min(ans,cal(i));
		if(ans==INF) ans=-1;
		printf("%d\n",ans);
	}
	return 0;
}
/*
枚举删哪个字符，不满足的时候就删
*/
