#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int n,i,a,b;
	scanf("%d",&n);
	if(n==3||n==5)
	{
		puts("NO");
		return 0;
	}
	vector<int> res;
	if(n&1) res={1,2,-3,2,4,-5,-2};
	else res={1,2};
	while(res.size()<n)
	{
		a=res[res.size()-2];
		b=res[res.size()-1];
		res.push_back(-b);
		res.push_back(a-b);
	}
	puts("YES");
	for(i=0;i<n;i++) printf("%d%c",res[i]," \n"[i==n-1]);
	return 0;
}
