#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
vector<int> a[MAX];
int main()
{
	int n,i,j,l,x,y;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&l);
		a[i]=vector<int>(l);
		for(auto &it:a[i]) scanf("%d",&it);
	}
	scanf("%d%d",&x,&y);
	x--;
	y--;
	printf("%d\n",a[x][y]);
	return 0;
}
