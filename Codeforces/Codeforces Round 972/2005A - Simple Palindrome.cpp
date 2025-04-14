#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
const int mod=998244353;
int main()
{
	string tmp="aeiou";
	int T,n,i,j;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		string res="";
		j=0;
		while(res.size()<n)
		{
			res+=tmp[j];
			j=(j+1)%5;
		}
		sort(res.begin(),res.end());
		cout<<res<<"\n";
	}
	return 0;
}
