#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e6+10;
char s[MAX];
int r[MAX],id[MAX];
int main()
{
	int n,i;
	scanf("%d",&n);
	scanf("%s",s+1);
	r[n+1]=n+1;
	for(i=n;i;i--)
	{
		id[i]=i;
		if(s[i]==s[i+1]) r[i]=r[i+1];
		else r[i]=i+1;
	}
	sort(id+1,id+1+n,[&](int x,int y){
		if(r[x]==r[y]) return x<y;
		return x<y?s[x]>s[r[x]]:s[y]<s[r[y]];
	});
	for(i=1;i<=n;i++) printf("%d%c",id[i]," \n"[i==n]);
	return 0;
}
