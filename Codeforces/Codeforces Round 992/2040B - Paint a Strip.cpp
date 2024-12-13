#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
const int mod=998244353;
int main()
{
	int T,n,i;
	vector<int> res;
	res.push_back(1);
	res.push_back(4);
	while(res.back()<=MAX) res.push_back((res.back()+1)*2);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		printf("%d\n",lower_bound(res.begin(),res.end(),n)-res.begin()+1);
	}
	return 0;
}
