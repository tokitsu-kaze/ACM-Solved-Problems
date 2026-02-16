#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=50+10;
int main()
{
	int n,m,q,i,ok1,ok2,f;
	string s,t,x;
	cin>>n>>m;
	cin>>s>>t;
	cin>>q;
	while(q--)
	{
		cin>>x;
		ok1=ok2=1;
		for(auto &it:x)
		{
			f=0;
			for(auto &it2:s)
			{
				if(it==it2) f=1;
			}
			if(f==0) ok1=0;
		}
		for(auto &it:x)
		{
			f=0;
			for(auto &it2:t)
			{
				if(it==it2) f=1;
			}
			if(f==0) ok2=0;
		}
		if(ok1==1 && ok2==0) puts("Takahashi");
		else if(ok1==0 && ok2==1) puts("Aoki");
		else puts("Unknown");
	}
	return 0;
}
