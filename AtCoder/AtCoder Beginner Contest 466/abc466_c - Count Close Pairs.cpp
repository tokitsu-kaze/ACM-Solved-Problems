#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
int ask(int i,int j)
{
	printf("? %d %d\n",i,j);
	fflush(stdout);
	char res[6];
	scanf("%s",res);
	return res[0]=='Y';
}
int main()
{
	int n,i,j,ans;
	scanf("%d",&n);
	ans=0;
	for(i=1,j=2;i<=n;i++)
	{
		j=max(j,i+1);
		while(j<=n && ask(i,j)) j++;
		ans+=j-i-1;
	}
	printf("! %d\n",ans);
	fflush(stdout);
	return 0;
}
