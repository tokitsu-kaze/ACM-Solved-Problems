#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e3+10;
int x[MAX],y[MAX];
int gao()
{
	int i,j,k,mx,mn;
	if(x[0]==x[1]&&x[1]==x[2]) return 1;
	if(y[0]==y[1]&&y[1]==y[2]) return 1;
	vector<int> tmp=vector<int>{0,1,2};
	do
	{
		i=tmp[0];
		j=tmp[1];
		k=tmp[2];
		mn=min(y[i],y[j]);
		mx=max(y[i],y[j]);
		if(x[i]==x[j]&&(y[k]<=mn||y[k]>=mx)) return 2;
		mn=min(x[i],x[j]);
		mx=max(x[i],x[j]);
		if(y[i]==y[j]&&(x[k]<=mn||x[k]>=mx)) return 2;
	}
	while(next_permutation(tmp.begin(),tmp.end()));
	return 3;
}
int main()
{
	int i;
	for(i=0;i<3;i++) scanf("%d%d",&x[i],&y[i]);
	printf("%d\n",gao());
	return 0;
}
