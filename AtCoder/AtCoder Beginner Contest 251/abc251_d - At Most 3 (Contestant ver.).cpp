#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e6+10;
int main()
{
	int i;
	vector<int> res;
	for(i=1;i<=99;i++) res.push_back(i);
	for(i=100;i<=9900;i+=100) res.push_back(i);
	for(i=10000;i<=990000;i+=10000) res.push_back(i);
	res.push_back(1e6);
	printf("%d\n",res.size());
	for(i=0;i<res.size();i++) printf("%d%c",res[i]," \n"[i==res.size()-1]);
	return 0;
}

