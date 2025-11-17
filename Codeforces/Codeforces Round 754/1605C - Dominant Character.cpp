#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
char ss[MAX];
const vector<string> res={
"aa",
"aba","aca",
"abca","acba",
"abbacca","accabba"
};
int main()
{
	int T,n,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",ss);
		string s=string(ss);
		ans=-1;
		for(auto &it:res)
		{
			if(s.find(it)!=s.npos)
			{
				ans=it.size();
				break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
