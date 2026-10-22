#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
char s[MAX];
int main()
{
	int T,n,i,lst[26],mn;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		memset(lst,0x3f,sizeof lst);
		for(i=n;i;i--)
		{
			if(lst[s[i]-'a']>n) lst[s[i]-'a']=i;
		}
		mn=INF;
		for(i=0;i<26;i++) mn=min(mn,lst[i]);
		puts(s+mn);
	}
	return 0;
}
