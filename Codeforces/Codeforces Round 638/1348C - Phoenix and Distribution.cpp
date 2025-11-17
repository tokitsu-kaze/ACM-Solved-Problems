#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
char s[MAX];
int main()
{
	int T,n,k,i,j;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		scanf("%s",s+1);
		sort(s+1,s+1+n);
		string ans,tmp;
		ans="";
		if(s[1]==s[k])
		{
			if(k<n && s[k+1]==s[n])
			{
				for(i=1;i<=k;i++)
				{
					tmp="";
					for(j=i;j<=n;j+=k) tmp+=s[j];
					if(ans.size()==0) ans=tmp;
					else ans=max(ans,tmp);
				}
			}
			else
			{
				ans+=s[1];
				for(i=k+1;i<=n;i++) ans+=s[i];
			}
		}
		else ans+=s[k];
		puts(ans.c_str());
	}
	return 0;
}
