#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int n,m,i,x,f;
	scanf("%d%d",&n,&m);
	vector<int> a(n);
	for(auto &it:a) scanf("%d",&it);
	while(m--)
	{
		vector<int> res;
		scanf("%d",&x);
		f=0;
		for(auto &it:a)
		{
			if(f==0)
			{
				if(it==x) f=1;
				else res.push_back(it);
			}
			else res.push_back(it);
		}
		swap(res,a);
	}
	for(i=0;i<a.size();i++) printf("%d%c",a[i]," \n"[i+1==a.size()]);
	return 0;
}
