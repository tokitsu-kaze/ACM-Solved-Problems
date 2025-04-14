#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,r,b,i,tmp,ret;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&r,&b);
		string res="";
		tmp=r/(b+1);
		ret=r%(b+1);
		while(b>0)
		{
			for(i=0;i<tmp;i++) res+="R";
			r-=tmp;
			if(ret>0)
			{
				res+="R";
				ret--;
				r--;
			}
			res+="B";
			b--;
		}
		for(i=0;i<r;i++) res+="R";
		assert(res.size()==n);
		cout<<res<<"\n";
	}
	return 0;
}
