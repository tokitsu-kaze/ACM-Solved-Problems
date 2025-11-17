#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
mt19937 rd(time(0));
set<int> s;
int cnt,tar;
int ask(int x,int y)
{
	int res=0;
	cnt++;
	printf("%d %d\n",x,y);
	fflush(stdout);
//	if(s.count(x) && s.count(y)) return 1;
	scanf("%d",&res);
	return res;
}
int main()
{
	int T,n,a,i,j,ok;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
//		scanf("%d",&a);
//		tar=n*n/a;
//		s.clear();
//		while(s.size()<a) s.insert(rd()%n+1);
		cnt=0;
		for(i=1;i<n;i++)
		{
			ok=0;
			for(j=1;j+i<=n;j++)
			{
				if(ask(j,j+i))
				{
					ok=1;
					break;
				}
			}
			if(ok) break;
		}
//		printf("%d %d\n",cnt,tar);
//		assert(cnt<=tar);
	}
	return 0;
}

