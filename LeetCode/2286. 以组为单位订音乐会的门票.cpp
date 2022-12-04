typedef long long ll;
const int MAX=5e4+10;
struct Segment_Tree
{
	#define type ll
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr;
	type a[MAX],v[MAX<<2],tag[MAX<<2],sum[MAX<<2],mx[MAX<<2];
	int k,m;
	void pushup(int id)
	{
		sum[id]=sum[ls]+sum[rs];
		mx[id]=max(mx[ls],mx[rs]);
	}
	void pushdown(int id)
	{
		if(!tag[id]) return;
		v[ls]=v[rs]=0;
		mx[ls]=mx[rs]=0;
		sum[ls]=sum[rs]=0;
		tag[ls]=tag[rs]=tag[id];
		tag[id]=0;
	}
	void build(int l,int r,int id)
	{
		tag[id]=0;
		if(l==r)
		{
			//init
			sum[id]=v[id]=m;
			mx[id]=m;
			return;
		}
		int mid=(l+r)>>1;
		build(l,mid,ls);
		build(mid+1,r,rs);
		pushup(id);
	}
	
    long long summ;
	void query(int l,int r,int id)
	{
		if(l>=ql&&r<=qr)
		{
			summ+=sum[id];
			return;
		}
		pushdown(id);
		int mid=(l+r)>>1;
		if(ql<=mid) query(l,mid,ls);
		if(qr>mid) query(mid+1,r,rs);
	}
	void build(int _n,int _m){n=_n;m=_m;build(1,n,1);}
	
	void query_scatter(int l,int r,int id,int &now)
	{
		if(sum[id]<=now)
		{
			tag[id]=1;
			now-=sum[id];
			sum[id]=0;
            v[id]=mx[id]=0;
			return;
		}
        if(now==0) return;
		if(l==r)
		{
     //       printf("%d %d %d\n",l,r,now);
			v[id]-=now;
            now=0;
			assert(v[id]>=0);
			mx[id]=v[id];
			sum[id]=v[id];
			return;
		}
		pushdown(id);
		int mid=(l+r)>>1;
		if(ql<=mid) query_scatter(l,mid,ls,now);
		if(qr>mid) query_scatter(mid+1,r,rs,now);
		pushup(id);
	}
	
	bool ask_scatter(int _k,int maxrow)
	{
		k=_k;
		ql=1;
		qr=maxrow+1;
        summ=0;
		query(1,n,1);
        if(summ<_k) return 0;
		query_scatter(1,n,1,_k);
		return 1;
	}
	
	pair<int,int> gather_res;
	void query_gather(int l,int r,int id)
	{
      //  printf("%d %d %d\n",l,r,mx[id]);
		if(mx[id]<k) return;
        if(gather_res.first!=-1) return;
		if(l==r)
		{
            if(v[id]<k) return;
			gather_res=make_pair(l,m-v[id]+1);
			v[id]-=k;
			mx[id]=v[id];
			sum[id]=v[id];
			return;
		}
		pushdown(id);
		int mid=(l+r)>>1;
		if(ql<=mid) query_gather(l,mid,ls);
		if(qr>mid) query_gather(mid+1,r,rs);
		pushup(id);
	}
	
	pair<int,int> ask_gather(int _k,int maxrow)
	{
		k=_k;
		ql=1;
		qr=maxrow+1;
		gather_res=make_pair(-1,-1);
		query_gather(1,n,1);
		return gather_res;
	}
	
	
	#undef type
	#undef ls
	#undef rs
}tr;
class BookMyShow {
public:
    BookMyShow(int n, int m) {
        tr.build(n,m);
    }
    
    vector<int> gather(int k, int maxRow) {
        pair<int,int> res=tr.ask_gather(k,maxRow);
        vector<int> ans;
        if(res.first==-1) return ans;
        ans.push_back(res.first-1);
        ans.push_back(res.second-1);
        return ans;
    }
    
    bool scatter(int k, int maxRow) {
        return tr.ask_scatter(k,maxRow);
    }
};

/**
 * Your BookMyShow object will be instantiated and called as such:
 * BookMyShow* obj = new BookMyShow(n, m);
 * vector<int> param_1 = obj->gather(k,maxRow);
 * bool param_2 = obj->scatter(k,maxRow);
 */
