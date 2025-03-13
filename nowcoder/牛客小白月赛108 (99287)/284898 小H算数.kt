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
/*using: xxx.sortWith(cmp)*/
val cmp: Comparator<pair> = Comparator{ a,b->
	if (a.fi==b.fi) a.se.compareTo(b.se)
	else a.fi.compareTo(b.fi)
}
const val INF=0x3f3f3f3f
const val LLINF=0x3f3f3f3f3f3f3f3fL
const val mod=998244353//1e9.toInt()+7
const val MAX=300000+10
/*------------------------------------------------------------*/
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
	var n=readint()
	require(n>=2 && n<=1e6)
	var a=readline_int()
	require(a.size==n)
	for(it in a) require(it>=1 && it<=n)
	var suf=Array<IntArray>(n+1){IntArray(2){0}}
	var pre=Array<IntArray>(n+1){IntArray(2){0}}
	var sufall=IntArray(n+1){0}
	var preall=IntArray(n+1){0}
	for(i in 1..n)
	{
		suf[a[i-1]][i and 1]++
		sufall[a[i-1]]++
	}
	var tr=Fenwick_Tree<Int>(n)
	var ans=0L
	for(i in 1..n)
	{
		var x=a[i-1]
		var t=(i and 1)
		suf[x][t]--
		sufall[x]--
		tr.upd(x,(-pre[x][t xor 1])+(-preall[x]))
		ans+=tr.ask(1,x-1)
		pre[x][t]++
		preall[x]++
		tr.upd(x,suf[x][t xor 1]+sufall[x])
	}
	println("${ans}")
}

