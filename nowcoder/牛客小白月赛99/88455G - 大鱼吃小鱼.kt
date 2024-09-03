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
data class pair(var fi:Int,var se:Long)
/*using: xxx.sortWith(cmp)*/
val cmp: Comparator<pair> = Comparator{ a,b->
	if (a.fi==b.fi) a.se.compareTo(b.se)
	else a.fi.compareTo(b.fi)
}
const val INF=0x3f3f3f3f
const val LLINF=0x3f3f3f3f3f3f3f3fL
const val mod=998244353//1e9.toInt()+7
/*------------------------------------------------------------*/
fun upper_bound_pos(a:MutableList<Long>,target:Long):Int
{
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
fun go()
{
	var T=readint()
	require(T>=1 && T<=5e4)
	var sumn=0
	while(T-->0)
	{
		var tmp_line=readline_int()
		require(tmp_line.size==2)
		var n=tmp_line[0]
		var x=tmp_line[1]
		require(n>=1 && n<=1e5)
		require(x>=1 && x<=1e9)
		sumn+=n
		require(sumn>=1 && sumn<=1e5)
		var res=mutableListOf<pair>()
		var d=Discretization<Long>()
		for(i in 0..n-1)
		{
			tmp_line=readline_int()
			require(tmp_line.size==3)
			var l=tmp_line[0]
			var r=tmp_line[1]
			var y=tmp_line[2].toLong()
			require(l>=1 && l<=1e9)
			require(r>=1 && r<=1e9)
			require(l<r)
			require(y>=1 && y<=1e9)
			res.add(pair(l,y))
			res.add(pair(r,-y))
			d.add(y)
		}
		res.sortWith(cmp)
		d.work()
		var tr=Fenwick_Tree<Long>(d.size()+1)
		var p=0
		var ans=0L
		while(p<res.size)
		{
			var j=0
			for(i in p..res.size-1)
			{
				if(res[i].fi!=res[p].fi)
				{
					j=i
					break
				}
				var pos=0
				if(res[i].se<0) pos=d.get_pos(-res[i].se)
				else pos=d.get_pos(res[i].se)
				tr.upd(pos,res[i].se)
				j=i+1
			}
			p=j
			var now=0L+x
			var pre=1
			while(true)
			{
				var pos=d.get_pos(now)
				if(pos<pre) break
				now+=tr.ask(pre,pos)
				pre=pos+1
			}
			ans=max(ans,now)
		}
		println("${ans}")
	}
}

