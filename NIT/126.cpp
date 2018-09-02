#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <climits>
using namespace std;
int a[1000010];
void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
int main()
{
	int n,m,p,i,q,w,count;
	while(cin>>n>>m>>p)
	{
		memset(a,0,sizeof(a));
		for(i=1;i<=n;i++)
		{
			a[i]=i;
		}
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&q,&w);
			swap(&a[q],&a[w]);
			if(q==p) p=w;
			else if(w==p) p=q;
		}
		for(i=1,count=0;i<=n;i++)
		{
			if(a[i]==i) count++;
		}
		cout<<p<<" "<<count<<endl;
	}
}