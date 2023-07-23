#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2e4+10;
struct Discretization
{
	#define type ll
	#define all(x) x.begin(),x.end()
	vector<type> a;
	void clear(){a.clear();}
	void add(type x){a.push_back(x);}
	void work(){sort(all(a));a.resize(unique(all(a))-a.begin());}
	int get_pos(type x){return lower_bound(all(a),x)-a.begin()+1;}
	type get_val(int pos){return a[pos-1];}
	int size(){return a.size();}
	#undef type
	#undef all
}d;
struct Monotone_queue
{
	#define type int
	type v[MAX][2];//0 is min, 1 is max
	int p[MAX][2];
	int l[2],r[2];
	void clear()
	{
		l[0]=r[0]=0;
		l[1]=r[1]=0;
	}
	void insert(type x,int pos)
	{
		while(r[0]-l[0]&&v[r[0]-1][0]>=x) r[0]--;
		v[r[0]][0]=x;
		p[r[0]++][0]=pos;
		while(r[1]-l[1]&&v[r[1]-1][1]<=x) r[1]--;
		v[r[1]][1]=x;
		p[r[1]++][1]=pos;
	}
	void erase(int pos)
	{
		while(r[0]-l[0]&&p[l[0]][0]<=pos) l[0]++;
		while(r[1]-l[1]&&p[l[1]][1]<=pos) l[1]++;
	}
	type get_min(){return v[l[0]][0];}
	type get_max(){return v[l[1]][1];}
	#undef type
}dq;
struct Suffix_Array
{
	int s[MAX],n,SZ;
	int c[MAX],rk[MAX],tmp[MAX],sa[MAX],h[MAX];
	void get_sa()
	{
		int m,i,j,k,tot;
		m=SZ;
		for(i=1;i<=m;i++) c[i]=0;
		for(i=1;i<=n;i++) c[rk[i]=s[i]]++;
		for(i=2;i<=m;i++) c[i]+=c[i-1]; 
		for(i=n;i;i--) sa[c[rk[i]]--]=i; 
		for(k=1;k<=n;k<<=1)
		{
			tot=0;
			for(i=n-k+1;i<=n;i++) tmp[++tot]=i;
			for(i=1;i<=n;i++)
			{
				if(sa[i]>k) tmp[++tot]=sa[i]-k;
			}
			for(i=1;i<=m;i++) c[i]=0;
			for(i=1;i<=n;i++) c[rk[i]]++;
			for(i=2;i<=m;i++) c[i]+=c[i-1];
			for(i=n;i;i--)
			{
				sa[c[rk[tmp[i]]]--]=tmp[i];
				tmp[i]=0;
			}
			swap(rk,tmp);
			rk[sa[1]]=1;
			tot=1;
			for(i=2;i<=n;i++)
			{
				if(sa[i]+k>n||sa[i-1]+k>n||
				   (!(tmp[sa[i]]==tmp[sa[i-1]]&&
					  tmp[sa[i]+k]==tmp[sa[i-1]+k]))) tot++;
				rk[sa[i]]=tot;
			}
			if(tot==n) break;
			m=tot;
		}
		h[1]=0;
		k=0;
		for(i=1;i<=n;i++)
		{
			if(rk[i]==1) continue;
			if(k>0) k--;
			j=sa[rk[i]-1];
			while(j+k<=n&&i+k<=n&&s[i+k]==s[j+k]) k++;
			h[rk[i]]=k;
		}
	}
	void work(int *_s,int _n) //s[1..n]
	{
		SZ=0; // char size
		n=_n;
		for(int i=1;i<=n;i++)
		{
			s[i]=_s[i];
			SZ=max(SZ,s[i]);
		}
		get_sa();
	}
}sa;
/*
sa[i]: s[sa[i]..n] rank is i
rk[i]: s[i..n] rank is rk[i]
h[i]: lcp(s[sa[i]..n],s[sa[i-1]..n])
lcp(s[i..n],s[j..n]) (i<j): min{h[i+1..j]}

sa.work(s,n) s[1..n]
*/
int a[MAX];
int main()
{
	int n,k,i,ans;
	scanf("%d%d",&n,&k);
	d.clear();
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		d.add(a[i]);
	}
	d.work();
	for(i=1;i<=n;i++) a[i]=d.get_pos(a[i]);
	sa.work(a,n);
	dq.clear();
	ans=0;
	for(i=2;i<=k-1;i++) dq.insert(sa.h[i],i);
	for(i=k;i<=n;i++)
	{
		dq.insert(sa.h[i],i);
		ans=max(ans,dq.get_min());
		dq.erase(i-k+2);
	}
	printf("%d\n",ans);
	return 0;
}
