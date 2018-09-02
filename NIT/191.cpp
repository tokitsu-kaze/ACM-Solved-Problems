#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
using namespace std;
typedef long long ll;
typedef double LD;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e3+10;
const ll mod=1e6;
int minn[MAX][33];
int v[MAX];
int sum[MAX];
void RMQ(int n)
{
	int i,j;
	for(j=1;1<<(j-1)<=n;j++)
	{
		int temp=(1<<j);
		for(i=1;i+temp-1<=n;i++)
		{
			int t=1<<(j-1);
			minn[i][j]=min(minn[i][j-1],minn[i+t][j-1]);
		}
	}
}
int query(int l,int r)
{
	int j=(int)(log2(r-l+1))+1;
	int i=r-(1<<(j-1))+1;
	return min(minn[l][j-1],minn[i][j-1]);
}
int main()
{
	int t,len,i,q,b,c,resa,resb;
	char a[MAX];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",a);
//		cout<<a<<endl;
		len=strlen(a);
		mem(minn,0x3f);
		sum[0]=v[0]=0;
		if(a[0]=='(') sum[1]=1;
		else if(a[0]==')') sum[1]=-1;
		else sum[1]=0;
		v[1]=sum[1];
		for(i=1;i<len;i++)
		{
			if(a[i]=='(')
			{
				sum[i+1]=sum[i]+1;
				v[i+1]=sum[i];
			}
			else if(a[i]==')')
			{
				sum[i+1]=sum[i]-1;
				v[i+1]=sum[i];
			}
			else
			{
				sum[i+1]=sum[i];
				v[i+1]=-INF;
			}
			minn[i][0]=v[i];
		}
		minn[len][0]=v[len];
		RMQ(len);
//		for(i=1;i<=len;i++) cout<<sum[i]<<endl;
		scanf("%d",&q);
		while(q--)
		{
			scanf("%d%d",&b,&c);
			resa=query(b+1,c+1)-sum[b];
	//		cout<<query(b+1,c+1)<<endl;
			if(resa>=0)
			{
				resb=sum[c+1]-sum[b];
				if(resb==0) puts("Yes");
				else puts("No");
			}
			else puts("No");	
		}
	}
	return 0;
}
/*
1000
(.).())
100
3 5
*/