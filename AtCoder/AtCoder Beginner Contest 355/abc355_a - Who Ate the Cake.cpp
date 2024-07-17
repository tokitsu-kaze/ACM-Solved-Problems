#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=5e3+10;
int main()
{
	int a,b;
	set<int> s;
	s.insert(1);
	s.insert(2);
	s.insert(3);
	scanf("%d%d",&a,&b);
	s.erase(a);
	s.erase(b);
	if(s.size()==1) printf("%d\n",*s.begin());
	else puts("-1");
	return 0;
}
