#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
int main()
{
	int q,op,h;
	multiset<int> s;
	s.insert(2e9);
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&op,&h);
		if(op==1) s.insert(h);
		else
		{
			while(*s.begin()<=h) s.erase(s.begin());
		}
		printf("%d\n",(int)s.size()-1);
	}
	return 0;
}
