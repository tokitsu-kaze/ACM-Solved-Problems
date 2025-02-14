#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAX=5e6+10;
namespace fastIO{
	#define BUF_SIZE 100000
	#define ll long long
	//fread->read
	bool IOerror=0;
//	inline char nc(){char ch=getchar();if(ch==-1)IOerror=1;return ch;} 
	inline char nc(){
		static char buf[BUF_SIZE],*p1=buf+BUF_SIZE,*pend=buf+BUF_SIZE;
		if(p1==pend){
			p1=buf;pend=buf+fread(buf,1,BUF_SIZE,stdin);
			if(pend==p1){IOerror=1;return -1;}
		}
		return *p1++;
	}
	inline bool blank(char ch){return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';}
	template<class T> inline bool read(T &x){
		bool sign=0;char ch=nc();x=0;
		for(;blank(ch);ch=nc());
		if(IOerror)return false;
		if(ch=='-')sign=1,ch=nc();
		for(;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
		if(sign)x=-x;
		return true;
	}
	inline bool read(double &x){
		bool sign=0;char ch=nc();x=0;
		for(;blank(ch);ch=nc());
		if(IOerror)return false;
		if(ch=='-')sign=1,ch=nc();
		for(;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
		if(ch=='.'){
			double tmp=1; ch=nc();
			for(;ch>='0'&&ch<='9';ch=nc())tmp/=10.0,x+=tmp*(ch-'0');
		}
		if(sign)x=-x;
		return true;
	}
	inline bool read(char *s){
		char ch=nc();
		for(;blank(ch);ch=nc());
		if(IOerror)return false;
		for(;!blank(ch)&&!IOerror;ch=nc())*s++=ch;
		*s=0;
		return true;
	}
	inline bool read(char &c){
		for(c=nc();blank(c);c=nc());
		if(IOerror){c=-1;return false;}
		return true; 
	}
	template<class T,class... U>bool read(T& h,U&... t){return read(h)&&read(t...);}
	#undef ll
	#undef BUF_SIZE
};
using namespace fastIO;
struct hash_map
{
	#define type ull
	#define TA ull
    static const int p=9999929;
    TA val[MAX];
	type w[MAX];
    int tot,head[p],nex[MAX];
    int top,st[MAX];
    hash_map(){top=tot=0;}
    void clear(){tot=0;while(top) head[st[top--]]=0;}
    void add(int x,TA y){val[++tot]=y;nex[tot]=head[x];head[x]=tot;w[tot]=0;}
    bool count(TA y)
    {
        int x=y%p;
        for(int i=head[x];i;i=nex[i])
        {
			if(y==val[i]) return 1;
		}
        return 0;
    }
    type& operator [](TA y)
    {
        int x=y%p;
        for(int i=head[x];i;i=nex[i])
        {
			if(y==val[i]) return w[i];
		}
        add(x,y);
        st[++top]=x;
		return w[tot];
    }
    #undef TA
    #undef type
}mp;
int main()
{
	int n,i;
	ull x,y,ans;
	read(n);
	mp.clear();
	ans=0;
	for(i=1;i<=n;i++)
	{
		read(x,y);
		ans+=mp[x]*i;
		mp[x]=y;
	}
	printf("%llu\n",ans);
	return 0;
}
