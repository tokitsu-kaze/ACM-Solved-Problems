#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=4e5+30;
struct node{int v,id;};
int tag[MAX],st[MAX],top;
char ans[MAX];
int main()
{
	int n,i,x;
	scanf("%d",&n);
	vector<node> res;
	for(i=1;i<=2*n;i++)
	{
		scanf("%d",&x);
		res.push_back({x,i});
	}
	sort(res.begin(),res.end(),[](node a,node b){
		return a.v<b.v;
	});
	for(i=0;i<n;i++) tag[res[i].id]=0;
	for(i=n;i<2*n;i++) tag[res[i].id]=1;
	top=0;
	for(i=1;i<=2*n;i++)
	{
		if(top==0||st[top-1]==tag[i])
		{
			ans[i]='(';
			st[top++]=tag[i];
		}
		else
		{
			ans[i]=')';
			top--;
		}
	}
	ans[2*n+1]='\0';
	puts(ans+1);
	return 0;
}
/*
最大的n个和最小的n个匹配
然后就随便匹配了
*/
