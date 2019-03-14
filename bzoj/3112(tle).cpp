#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <bitset>
#include <limits>
#include <assert.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define sqr(x) (x)*(x)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef pair<int,ll> PIL;
typedef pair<ll,int> PLI;
typedef vector<int> VI;
typedef vector<ll> VL;
void go();
int main(){
	#ifdef tokitsukaze
		freopen("TEST.txt","r",stdin);
	#endif
	go();return 0;
}
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e6+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
typedef double db;
typedef vector<db> VD;
typedef vector<VD> VVD;
typedef vector<int> VI;
struct Simplex
{
	int m,n;
	VI B,N;
	VVD D;
	Simplex(){}
	Simplex(const VVD &A,const VD &b,const VD &c):m(sz(b)),n(sz(c)),N(n+1),B(m),D(m+2,VD(n+2))
	{
		int i,j;
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				D[i][j]=A[i][j];
			}
		}
		for(i=0;i<m;i++)
		{
			B[i]=n+i;
			D[i][n]=-1;
			D[i][n+1]=b[i];
		}
		for(j=0;j<n;j++)
		{
			N[j]=j;
			D[m][j]=-c[j];
		}
		N[n]=-1;
		D[m+1][n]=1;
	} 
	void Pivot(int r,int s)
	{
		int i,j;
		for(i=0;i<m+2;i++)
		{
			if(i==r) continue;
			for(j=0;j<n+2;j++)
			{
				if(j==s) continue;
				D[i][j]-=D[r][j]*D[i][s]/D[r][s];
			}
		}
		for(j=0;j<n+2;j++)
		{
			if (j!=s) D[r][j]/=D[r][s];
		}
		for(i=0;i<m+2;i++)
		{
			if(i!=r) D[i][s]/=-D[r][s];
		}
		D[r][s]=1.0/D[r][s];
		swap(B[r],N[s]);
	}
	bool simplex(int phase)
	{
		int i,j,s,r;
		int x=phase==1?m+1:m;
		while(1)
		{
			s=-1;
			for(j=0;j<=n;j++)
			{
				if(phase==2&&N[j]==-1) continue;
				if(s==-1||D[x][j]<D[x][s]||D[x][j]==D[x][s]&&N[j]<N[s]) s=j;
			}
			if(D[x][s]>-eps) return 1;
			r=-1;
			for(i=0;i<m;i++)
			{
				if(D[i][s]<eps) continue;
				if(r==-1||D[i][n+1]/D[i][s]<D[r][n+1]/D[r][s]) r=i;
				if(D[i][n+1]/D[i][s]==D[r][n+1]/D[r][s]&&B[i]<B[r]) r=i;
			}
			if(r==-1) return 0;
			Pivot(r,s);
		}
	}
	db work(VD &res)
	{
		int i,j,k,r,s;
		r=0;
		for(i=1;i<m;i++)
		{
			if(D[i][n+1]<D[r][n+1]) r=i;
		}
		if(D[r][n+1]<-eps)
		{
			Pivot(r,n);
			if(!simplex(1)||D[m+1][n+1]<-eps) return -numeric_limits<db>::infinity();//no solution 
			for(i=0;i<m;i++)
			{
				if(B[i]!=-1) continue;
				s=-1;
				for(j=0;j<=n;j++)
				{
					if(s==-1||D[i][j]<D[i][s]||D[i][j]==D[i][s]&&N[j]<N[s]) s=j;
				}
				Pivot(i,s);
			}
		}
		if(!simplex(2)) return numeric_limits<db>::infinity();//solution is INF
		res=VD(n);
		for(i=0;i<m;i++)
		{
			if(B[i]<n) res[B[i]]=D[i][n+1];
		}
		return D[m][n+1];
	}
};
void go()
{
    int n,m,i,j,l,r,k;
    db ans;
    while(~scanf("%d%d",&n,&m))
    {
	    VVD A(m,VD(n,0));
	    VD B(m);
		VD C(n);
	    for(int i=0;i<n;i++)
	    {
			scanf("%lf",&C[i]);
			C[i]=-C[i];
		}
	    for(int i=0;i<m;i++)
	    {
			scanf("%d%d",&l,&r);
			for(j=l-1;j<r;j++)
			{
				A[i][j]=-1;
			}
			scanf("%lf",&B[i]);
			B[i]=-B[i];
		}
	    VD res;
	    Simplex sp(A,B,C);
	    ans=sp.work(res);
	    printf("%lld\n",(ll)(-ans+0.5));
	}
}
