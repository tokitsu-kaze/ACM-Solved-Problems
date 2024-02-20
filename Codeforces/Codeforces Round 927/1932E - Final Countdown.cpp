#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=4e5+10;
char s[MAX];
int bit[MAX];
int main()
{
	int t,n,i,now;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		bit[0]=0;
		for(i=1;i<=n;i++) bit[i]=bit[i-1]+s[i]-'0';
		vector<int> res;
		now=0;
		for(i=n;i;i--)
		{
			now+=bit[i];
			if(now) res.push_back(now%10);
			now/=10;
		}
		if(now) printf("%d",now);
		reverse(res.begin(),res.end());
		for(auto &it:res) printf("%d",it);
		puts("");
	}
	return 0;
}
