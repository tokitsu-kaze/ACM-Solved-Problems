#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
char s[MAX];
int main()
{
	int t,n,i;
	string res;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		res="";
		for(i=n;i;i--)
		{
			if(!res.size()||res.back()=='.') res.push_back(s[i]);
			else if(res.back()=='b'||res.back()=='c'||res.back()=='d') res.push_back(s[i]);
			else
			{
				res.push_back(s[i]);
				if(i>1) res.push_back('.');
			}
		}
		reverse(res.begin(),res.end());
		cout<<res<<"\n";
	}
	return 0;
}
