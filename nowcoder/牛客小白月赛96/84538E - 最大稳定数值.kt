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
data class pair(var fi:Long,var se:Long)
/*using: xxx.sortWith(cmp)*/
val cmp: Comparator<pair> = Comparator{ a,b->
	if (a.fi==b.fi) a.se.compareTo(b.se)
	else a.fi.compareTo(b.fi)
}
const val INF=0x3f3f3f3f
const val LLINF=0x3f3f3f3f3f3f3f3fL
const val MAX=1e5.toInt()+10
const val mod=998244353
/*------------------------------------------------------------*/
fun lower_bound_pos(a:MutableList<Long>,target:Long):Int
{
	var l=0
	var r=a.size-1
	var mid:Int
	while(l<r)
	{
		mid=(l+r) shr 1
		if(a[mid]>=target) r=mid
		else l=mid+1
	}
    if(a[l]>=target) return l
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
	fun get_pos(x:T):Int{return lower_bound_pos(a,x.toLong())+1}
	fun get_val(pos:Int):T {return a[pos-1] as T}
	fun size():Int{return a.size}
}
class Fenwick_Tree<T:Number>(var n:Int)
{
	var bit=LongArray(n+1){0}
	fun lowbit(x:Int):Int{return x and (-x)}
	fun insert(xx:Int,qv:T)
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
var mp=Array(1){mutableListOf<Int>()}
var v=LongArray(1)
var sum_clain=LongArray(1)
var sum_subtree=LongArray(1)
var res=IntArray(1)
var ans=0
var d=Discretization<Long>()
var tr=Fenwick_Tree<Int>(1)
fun dfs(x:Int,fa:Int)
{
	sum_clain[x]=sum_clain[fa]+v[x]
	sum_subtree[x]=v[x]
	for(to in mp[x])
	{
		dfs(to,x)
		sum_subtree[x]+=sum_subtree[to]
		res[x]+=res[to]
	}
	if(sum_clain[fa]>=v[x] && sum_subtree[x]-v[x]<=v[x]) res[x]+=1
	else if(sum_clain[fa]>=v[x]) d.add(sum_subtree[x]-2*v[x])
	d.add(sum_subtree[x])
}
fun dfs2(x:Int,fa:Int)
{
	var pos=d.get_pos(sum_subtree[x]-2*v[x])
	if(sum_clain[fa]>=v[x] && sum_subtree[x]-v[x]>v[x]) tr.insert(pos,1)
	for(to in mp[x])
	{
		var now=res[1]-res[to]
		now+=tr.ask(1,d.get_pos(sum_subtree[to]))
		ans=max(ans,now)
		dfs2(to,x)
	}
	if(sum_clain[fa]>=v[x] && sum_subtree[x]-v[x]>v[x]) tr.insert(pos,-1)
}
fun go()
{
	var n=readint()
	require(n>=1 && n<=1e5)
	var a=readline_ll()
	require(a.size==n)
	v=LongArray(n+5)
	for(i in 1..n)
	{
		require(a[i-1]>=1 && a[i-1]<=1e9)
		v[i]=a[i-1]
	}
	var fa=readline_int()
	mp=Array(n+2){mutableListOf<Int>()}
	require(fa.size==n)
	require(fa[0]==0)
	for(i in 2..n)
	{
		require(fa[i-1]>=1 && fa[i-1]<=i-1)
		mp[fa[i-1]].add(i)
	}
	sum_clain=LongArray(n+2){0}
	sum_subtree=LongArray(n+2){0}
	res=IntArray(n+2){0}
	d=Discretization<Long>()
	d.add(0)
	dfs(1,0)
	ans=res[1]
	d.work()
	tr=Fenwick_Tree<Int>(d.size())
	dfs2(1,0)
	println("${ans}")
}

