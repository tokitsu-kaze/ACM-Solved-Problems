#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=5e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
#define lowbit(k) ((k)&(-k))
template<typename T>
struct BIT{
	T c[maxn];
	int mx_idx;
	inline void clear(){memset(c,0,sizeof(T)*(mx_idx+1));}
	inline void add(int k,T v){
		for(;k<=mx_idx;k+=lowbit(k))c[k]+=v;
	}
	inline T query(int l,int r){
		T ret=0;
		for(;r;r^=lowbit(r))ret+=c[r];
		for(--l;l;l^=lowbit(l))ret-=c[l];
		return ret;
	}
};
BIT<int>t;
int n,q,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d",&n,&q);
		set<int>s1,s2,s3;
		s1.insert(n+1),s2.insert(0),s2.insert(n+1),s3.insert(0);
		t.mx_idx=n,t.clear();
		for(ri i=1;i<=n;++i){++t.c[i];if(i+lowbit(i)<=n)t.c[i+lowbit(i)]+=t.c[i];}
		for(ri i=1;i<=n;++i)assert(t.query(i,i)==1);
		while(q--){
			ri x,y;
			scanf("%d%d",&y,&x);
			if(x==1&&!s1.insert(y).second)s1.erase(y);
			if(x==2){
				if(s2.insert(y).second)t.add(y,-1);
				else s2.erase(y),t.add(y,1);
			}
			if(x==3&&!s3.insert(y).second)s3.erase(y);
			ri l=*s1.begin()-1,r=*s3.rbegin()+1;
			auto find_l=[&](int L){
				ri l=1,r=L,ret=L+1;
				while(l<=r){
					ri mid=l+r>>1;
					if(!t.query(mid,L))ret=mid,r=mid-1;
					else l=mid+1;
				}
				return ret-1;
			};
			auto find_r=[&](int R){
				ri l=R,r=n,ret=R-1;
				while(l<=r){
					ri mid=l+r>>1;
					if(!t.query(R,mid))ret=mid,l=mid+1;
					else r=mid-1;
				}
				return ret+1;
			};
			l=find_l(l),r=find_r(r);
			if(l<1||r>n){puts("0");continue;}
			if(l<r){
				auto it=s2.upper_bound(l);
				if(it!=s2.end()&&*it<=r)puts("0");
				else printf("%d\n",l+*it-*prev(it)-1+n-r+1-1);
			}
			else{
				auto it=s2.upper_bound(r);
				if(it!=s2.end()&&*it<l){
					auto it2=s2.upper_bound(l);--it2;
					ri ans=*it-*prev(it)-1+*next(it2)-*it2-1;
					if(*it+1<*it2)ans+=t.query(*it+1,*it2-1);
					printf("%d\n",find_l(l)+ans+n-find_r(r)+1-1);
				}
				else printf("%d\n",find_l(l)+*it-*prev(it)-1+n-find_r(r)+1-1);
			}
		}
	}
	return 0;
}
