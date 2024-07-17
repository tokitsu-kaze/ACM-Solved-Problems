#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2e5+10;
int a[MAX];
int cal(int n,ll h,vector<int> tmp)
{
	int i,j,res;
	res=0;
	j=0;
	for(i=1;i<=n;i++)
	{
		if(a[i]<h)
		{
			res++;
			h+=a[i]/2;
		}
		else
		{
			if(j==tmp.size()) return res;
			h*=tmp[j++];
			i--;
		}
	}
	return res;
}
int main()
{
	int t,n,h,i,ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&h);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		vector<int> tmp={2,2,3};
		ans=0;
		do
		{
			ans=max(ans,cal(n,h,tmp));
		}while(next_permutation(tmp.begin(),tmp.end()));
		printf("%d\n",ans);
	}
	return 0;
}
