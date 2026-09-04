#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
const int mod=167772161;
struct Combinatorics
{
	vector<int> inv_e,fac,invfac;
	int last_n;
	Combinatorics(){last_n=0;}
	void init(int n)
	{
		if(n<=last_n) return;
		inv_e.resize(n+1);
		fac.resize(n+1);
		invfac.resize(n+1);
		if(last_n==0)
		{
			inv_e[1]=1;
			fac[0]=fac[1]=1;
			invfac[0]=invfac[1]=1;
			last_n=1;
		}
		for(int i=last_n+1;i<=n;i++)
		{
			inv_e[i]=1LL*(mod-mod/i)*inv_e[mod%i]%mod;
			fac[i]=1LL*fac[i-1]*i%mod;
			invfac[i]=1LL*invfac[i-1]*inv_e[i]%mod;
		}
		last_n=n;
	}
	int qpow(int a,ll b)
	{
		int res=1;
		while(b>0)
		{
			if(b&1) res=1LL*res*a%mod;
			a=1LL*a*a%mod;
			b>>=1;
		}
		return res;
	}
	int inv(int x)
	{
		if(x<=last_n) return inv_e[x];
		else return qpow(x,mod-2);
	}
	ll C(int n,int m)
	{
		if(m>n||m<0||n<0) return 0;
		return 1LL*fac[n]*invfac[m]%mod*invfac[n-m]%mod;
	}
	ll A(int n,int m)
	{
		if(m>n||m<0||n<0) return 0;
		return 1LL*fac[n]*invfac[n-m]%mod;
	}
}comb;
int add(const int &x,const int &y){return x+y>=mod?x+y-mod:x+y;}
int sub(const int &x,const int &y){return x-y<0?x-y+mod:x-y;}
int mul(const int &x,const int &y){return 1LL*x*y%mod;}
struct NTT
{
	const int g=3;
	const int _mod=167772161;
	int len;
	vector<int> omega,omegaInv;
	NTT(){assert(mod==_mod);len=0;}
	inline void init(int n)
	{
		int last_len=len;
		len=1;
		while(len<=n) len<<=1;
		if(last_len==len) return;
		omega.resize(len);
		omegaInv.resize(len);
		omega[0]=omegaInv[0]=1;
		const int primitive=comb.qpow(g,(mod-1)/len);
		for(int i=1;i<len;i++) omega[i]=omegaInv[len-i]=mul(omega[i-1],primitive);
	}
	void DFT(vector<int> &a)
	{
		int *w=omega.data();
		if(a.size()<len) a.resize(len);
		int *b=a.data();
		int h,t,i,j,x,y;
		for(h=(len>>1);h;h>>=1)
		{
			for(t=len/(h<<1),j=0;j<len;j+=(h<<1))
			{
				const int *wn=w;
				for(i=j;i<j+h;i++) 
				{
					x=b[i],y=b[i+h];
					b[i]=add(x,y);
					b[i+h]=mul(sub(x,y),*wn);
					wn+=t;
				}
			}
		}
	}
	void IDFT(vector<int> &a)
	{
		int *w=omegaInv.data();	
		if(a.size()<len) a.resize(len);
		int *b=a.data();
		int h,t,i,j,x,y;
		for(h=1;h<len;h<<=1)
		{
			for(t=len/(h<<1),j=0;j<len;j+=h<<1)
			{
				const int *wn=w;
				for (i=j;i<j+h;i++)
				{
					x=b[i],y=mul(b[i+h],*wn);
					b[i]=add(x,y);
					b[i+h]=sub(x,y);
					wn+=t;
				}
			}
		}
		const int tmp=mod-(mod-1)/len;
		for(i=0;i<len;i++) b[i]=mul(b[i],tmp);
	}
	void operator()(vector<int> &x,int op)
	{
		if(op==1) DFT(x);
		if(op==-1) IDFT(x);
	}
}ntt;
struct Poly
{
	vector<int> v;
	Poly(){}
	Poly(vector<int> v):v(v){}
	Poly(const Poly &x):v(x.v){}
	Poly(initializer_list<int> v):v(v){}
	int deg() const {return v.size()-1;}
	void redeg(int k){v.resize(k+1);}
	Poly slice(int k) const
	{
		if(k<v.size()) return vector<int>(v.begin(),v.begin()+k+1);
		vector<int> res(v);
		res.resize(k+1);
		return res;
	}
	Poly clone() const {return slice(deg());}
	void shrink()
	{
		int c=deg();
		while(c>=0&&v[c]==0) c--;
		v.resize(c+1);
	}
	int operator[](int k) const {return v.size()<=k?0:v[k];}
	int& operator[](int k)
	{
		if(v.size()<=k) v.resize(k+1);
		return v[k];
	}
	friend Poly operator+(const Poly &x,const Poly &y)
	{
		Poly z;
		int deg=max(x.deg(),y.deg());
		for(int i=0;i<=deg;i++) z[i]=add(x[i],y[i]);
		return z;
	}
	friend Poly operator+(const Poly &x,const int c)
	{
		Poly z=x.clone();
		z[0]=add(z[0],c);
		return z;
	}
	friend Poly operator-(const Poly &x,const Poly &y)
	{
		Poly z;
		int deg=max(x.deg(),y.deg());
		for(int i=0;i<=deg;i++) z[i]=sub(x[i],y[i]);
		return z;
	}
	friend Poly operator-(const Poly &x,const int c)
	{
		Poly z=x.clone();
		z[0]=sub(z[0],c);
		return z;
	}
	friend Poly operator*(const Poly &_x,const Poly &_y)
	{
		Poly x=_x.clone(),y=_y.clone();
		int deg=x.deg()+y.deg();
		Poly z;
		if(deg<=31)
		{
			z.redeg(deg);
			for(int i=0;i<=x.deg();i++)
			{
				for(int j=0;j<=y.deg();j++)
				{
					z[i+j]=add(z[i+j],mul(x[i],y[j]));
				}
			}
		}
		else
		{
			ntt.init(deg);
			ntt(x.v,1);
			ntt(y.v,1);
			z.v.resize(ntt.len);
			for(int i=0;i<ntt.len;i++) z[i]=mul(x[i],y[i]);
			ntt(z.v,-1);
		}
		return z.slice(deg);
	}
	Poly PolyInv(const Poly &a) const
	{
		Poly ax,z;
		int deg=a.deg();
		if(deg==0) return Poly({comb.inv(a[0])});
		z=PolyInv(a.slice(a.deg()>>1));
		ntt.init(a.deg()<<1);
		ax=a.clone();
		ntt(ax.v,1);
		ntt(z.v,1);
		for(int i=0;i<ntt.len;i++) ax[i]=sub(mul(ax[i],z[i]),1);
		for(int i=0;i<ntt.len;i++) z[i]=mul(z[i],sub(1,ax[i]));
		ntt(z.v,-1);
		z.redeg(deg);
		return z;
	}
	Poly inv() const {return PolyInv(*this).slice(deg());}
	Poly derivative() const
	{
		Poly z;
		for(int i=0;i<deg();i++) z[i]=mul(i+1,(*this)[i+1]);
		return z;
	}
	Poly integration() const
	{
		Poly z;
		comb.init(deg());
		for(int i=1;i<=deg();i++) z[i]=mul(comb.inv(i),(*this)[i-1]);
		return z;
	}
	Poly ln() const
	{
		assert((*this)[0]==1);
		return (derivative()*inv()).integration().slice(deg());
	}
	Poly PolyExp(const Poly &a) const
	{
		int deg=a.deg();
		if(deg==0) return Poly({1});
		Poly z=PolyExp(a.slice(deg>>1)).slice(deg);
		return z*(a+1-z.ln());
	}
	Poly exp() const
	{
		assert((*this)[0]==0);
		return PolyExp(*this).slice(deg());
	}
	Poly pow(ll k) const
	{
		int i,pos,deg,c,invc,powc,k0,k1;
		Poly z=(*this).clone();
		deg=z.deg();
		if(k==0)
		{
			z=Poly(vector<int>(deg+1,0));
			z[0]=1;
			return z;
		}
		k0=k%mod;
		k1=k%(mod-1);
		if(z[0]==1)
		{
			z=z.ln();
			for(i=0;i<=deg;i++) z[i]=mul(z[i],k0);
			z=z.exp();
			return z.slice(deg);
		}
		pos=z.deg()+1;
		for(i=0;i<=deg;i++)
		{
			if(z[i])
			{
				pos=i;
				break;
			}
		}
		if(pos==deg+1) return *this;
		if(pos>deg/k) return Poly(vector<int>(deg+1,0));
		for(i=0;i<=deg-pos;i++) z[i]=z[i+pos];
		for(i=deg-pos+1;i<=deg;i++) z[i]=0;
		c=z[0];
		assert(c);
		invc=comb.inv(c);
		powc=comb.qpow(c,k1);
		for(i=0;i<=deg;i++) z[i]=mul(z[i],invc);
		z=z.ln();
		for(i=0;i<=deg;i++) z[i]=mul(z[i],k0);
		z=z.exp();
		for(i=0;i<=deg;i++) z[i]=mul(z[i],powc);
		pos*=k0;
		for(int i=deg;i>=pos;i--) z[i]=z[i-pos];
		for(int i=0;i<pos;i++) z[i]=0;
		return z.slice(deg);
	}
	Poly composite(int c) const  // f(x) -> f(x+c)
	{
		int n,i,cur_c;
		Poly a,b,res,z;
		n=deg();
		if(n<0) return Poly();
		comb.init(n);
		a.redeg(n);
		b.redeg(n);
		cur_c=1;
		for(i=0;i<=n;i++)
		{
			a[i]=mul((*this)[n-i],comb.fac[n-i]);
			b[i]=mul(cur_c,comb.invfac[i]);
			cur_c=mul(cur_c,c);
		}
		res=a*b;
		z.redeg(n);
		for(i=0;i<=n;i++) z[i]=mul(res[n-i],comb.invfac[i]);
		return z;
	}
	void println(){for(int i=0;i<=deg();i++) printf("%d%c",v[i]," \n"[i==deg()]);}
};
/*
poly.inv();
poly.derivative();
poly.integration();
poly.ln();
poly.exp();
poly.pow(ll k);
poly.println();
*/
Poly stirling_number_1_row(int n)
{
	if(n==0) return Poly({1});
	int i,j;
	vector<int> st;
	while(n)
	{
		st.push_back(n);
		n>>=1;
	}
	reverse(st.begin(),st.end());
	Poly f({0,1}),g;
	n=1;
	for(i=1;i<st.size();i++)
	{
		g=f.composite(n);
		f=f*g;
		n<<=1;
		if(st[i]==n) continue;
		f.redeg(n+1); 
		for(j=n+1;j>=1;j--) f[j]=add(f[j-1],mul(f[j],n));
		f[0]=mul(f[0],n);
		n++;
	}
	return f;
}
int main()
{
	int n;
	scanf("%d",&n);
	stirling_number_1_row(n).println();
	return 0;
}
