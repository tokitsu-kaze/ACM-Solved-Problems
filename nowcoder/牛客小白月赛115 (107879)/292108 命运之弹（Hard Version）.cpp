import java.util.*
import kotlin.math.*

fun readint()=readLine()!!.toInt()
fun readll()=readLine()!!.toLong()
fun readdb()=readLine()!!.toDouble()
fun readstring()=readLine()!!
fun readline_char()=readLine()!!.toCharArray()
fun readline_int()=(readLine()!!.split(" ").map{it.toInt()}).toIntArray()
fun readline_ll()=(readLine()!!.split(" ").map{it.toLong()}).toLongArray()
fun readline_db()=(readLine()!!.split(" ").map{it.toDouble()}).toDoubleArray()
fun readline_string()=(readLine()!!.split(" "))
fun main(args: Array<String>){go()}
data class pair(var fi:Int,var se:Int)
/*using: xxx.sortWith(pair_cmp)*/
val pair_cmp: Comparator<pair> = Comparator{ a,b->
	if (a.fi==b.fi) a.se.compareTo(b.se)
	else a.fi.compareTo(b.fi)
}
const val INF=0x3f3f3f3f
const val LLINF=0x3f3f3f3f3f3f3f3fL
const val MAX=1e5.toInt()+10
const val mod=998244353//1e9.toInt()+7
/*------------------------------------------------------------*/
fun upper_bound_pos(a:MutableList<Long>,target:Long):Int
{
	if(a.size==0) return 0
	var l=0
	var r=a.size-1
	var mid:Int
	while(l<r)
	{
		mid=(l+r) shr 1
		if(a[mid]<=target) l=mid+1
		else r=mid
	}
	if(a[l]>target) return l
    return a.size
}
class Discretization<T:Number>()
{
	var a=mutableListOf<Long>()
	fun add(x:T){a.add(x.toLong())}
	fun work(){
		a.sort()
		var tmp=mutableListOf<Long>()
		var pre=-1L
		if(a.size>0) pre=a[0]-1L;
		for(it in a){
			if(it!=pre) {tmp.add(it)}
			pre=it
		}
		a=tmp
	}
	fun get_pos(x:T):Int{return upper_bound_pos(a,x.toLong())}
	fun get_val(pos:Int):T {return a[pos-1] as T}
	fun size():Int{return a.size}
}
class Fenwick_Tree <T:Number> (var n:Int)
{
	var bit=LongArray(n+1){0}
	fun lowbit(x:Int):Int{return x and (-x)}
	fun upd(xx:Int,qv:T)
	{
		var x=xx
        var v=qv.toLong()
		while(x<=n)
		{
			bit[x]+=v
			x+=lowbit(x)
		}
	}
	fun get(xx:Int):Long
	{
		var res=0L
		var x=xx
		while(x>0)
		{
			res+=bit[x]
			x-=lowbit(x)
		}
		return res
	}
	fun ask(l:Int,r:Int):T
	{
        if(l>r) return 0 as T
        if(l-1<=0) return get(r) as T
		return (get(r)-get(l-1)) as T
	}
}
class Segment_Tree<T:Number>()
{
	class node<Long>(){
		var v=LLINF
	}
	var t=Array<node<Long>>(1){node()}
	var tag=LongArray(1)
	var n:Int=0
	var ql:Int=0
	var qr:Int=0
	var qv=0L
	var qop:Int=0
	
	fun merge(x:node<Long>,y:node<Long>):node<Long>
	{
		var res=node<Long>()
		res.v=min(x.v,y.v)
		return res
	}
	fun pushup(id:Int){t[id]=merge(t[id shl 1],t[id shl 1 or 1])}
	fun pushdown(l:Int,r:Int,id:Int)
	{
		if(tag[id]==0L) return
		var mid=(l+r) shr 1
		var ls=id shl 1
		var rs=id shl 1 or 1
		t[ls].v+=tag[id]
		t[rs].v+=tag[id]
		tag[ls]+=tag[id]
		tag[rs]+=tag[id]
		tag[id]=0L
	}
	fun build(l:Int,r:Int,id:Int)
	{
		tag[id]=0L
		t[id].v=0L
		if(l==r) return
		var mid=(l+r) shr 1
		build(l,mid,id shl 1)
		build(mid+1,r,id shl 1 or 1)
		pushup(id)
	}
	fun update(l:Int,r:Int,id:Int)
	{
		if(l>=ql&&r<=qr)
		{
			tag[id]+=qv
			t[id].v+=qv
			return
		}
		pushdown(l,r,id)
		var mid=(l+r) shr 1
		if(ql<=mid) update(l,mid,id shl 1)
		if(qr>mid) update(mid+1,r,id shl 1 or 1)
		pushup(id)
	}
	fun query(l:Int,r:Int,id:Int):node<Long>
	{
		if(l>=ql&&r<=qr) return t[id]
		pushdown(l,r,id)
		var mid=(l+r) shr 1
		if(qr<=mid) return query(l,mid,id shl 1)
		if(ql>mid) return query(mid+1,r,id shl 1 or 1)
		return merge(query(l,mid,id shl 1),
                     query(mid+1,r,id shl 1 or 1))
	}
	fun build(_n:Int)
	{
		n=_n;
		t=Array<node<Long>>((n+5) shl 2){node()}
		tag=LongArray((n+5) shl 2)
		build(1,n,1)
	}
	fun upd(l:Int,r:Int,v:T)
	{
		if(l>r) return
		ql=l
		qr=r
		qv=v.toLong()
		update(1,n,1)
	}
	fun ask(l:Int,r:Int):T
	{
		if(l>r) return 0 as T
		ql=l
		qr=r
		return query(1,n,1).v as T
	}
}
data class node(var v:Int,var id:Int)
val node_cmp: Comparator<node> = Comparator{ a,b->
	a.v.compareTo(b.v)
}
fun go()
{
	var n=readint()
	require(n>=1 && n<=2e5)
	var a=readline_int()
	require(a.size==n)
	for(it in a) require(it>=1 && it<=1e9)
	var q=readint()
	require(q>=1 && q<=2e5)
	var qst=mutableListOf<node>()
	for(i in 0..q-1)
	{
		var v=readint()
		require(v>=1 && v<=1e9)
		qst.add(node(v,i))
	}
	qst.sortWith(node_cmp)
	var d=Discretization<Int>()
	for(it in a) d.add(it)
	d.work()
	var bit=Fenwick_Tree<Int>(n+1)
	var tr=Segment_Tree<Int>()
	tr.build(n)
	var res=mutableListOf<node>()
	for(i in n-1 downTo 0)
	{
		var p=d.get_pos(a[i])
		tr.upd(i+1,i+1,i+bit.ask(p+1,n))
		bit.upd(p,1)
		res.add(node(a[i],i+1))
	}
	res.sortWith(node_cmp)
	var i=0
	var ans=IntArray(q){0}
	for(it in qst)
	{
		while(i<n && res[i].v<=it.v)
		{
			tr.upd(res[i].id+1,n,-1)
			i++
		}
		ans[it.id]=tr.ask(1,n)
	}
	println(ans.joinToString("\n"))
}

