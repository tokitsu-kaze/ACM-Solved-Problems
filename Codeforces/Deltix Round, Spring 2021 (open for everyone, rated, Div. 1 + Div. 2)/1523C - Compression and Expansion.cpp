#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const double eps=1e-9;
const int MAX=1e3+10;
int a[MAX];
int main()
{
	int T,n,i,x;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		vector<int> now;
		while(n--)
		{
			scanf("%d",&x);
			if(x==1) now.push_back(1);
			else
			{
				while(now.size()>0 && now.back()!=x-1) now.pop_back();
				assert(now.size()>0);
				now.back()=x;
			}
			for(i=0;i<now.size();i++)
			{
				printf("%d%c",now[i],".\n"[i+1==now.size()]);
			}
		}
	}
	return 0;
}
