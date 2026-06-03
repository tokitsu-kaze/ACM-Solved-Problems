import java.util.*
import kotlin.math.*
import kotlin.random.Random

fun readint()=readLine()!!.toInt()
fun readll()=readLine()!!.toLong()
fun readdb()=readLine()!!.toDouble()
fun readstring()=readLine()!!
fun readline_char()=readLine()!!.toCharArray()
fun readline_int()=(readLine()!!.split(" ").map{it.toInt()}).toIntArray()
fun readline_ll()=(readLine()!!.split(" ").map{it.toLong()}).toLongArray()
fun readline_ull()=(readLine()!!.split(" ").map{it.toULong()}).toULongArray()
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
const val MAX=1e7.toInt()+10
const val mod=998244353
/*------------------------------------------------------------*/
fun workl(x:IntArray,n:Int):IntArray
{
	var st=IntArray(n+1)
	var top=0
	var l=IntArray(n+1){0}
	for(i in n downTo 1)
	{
		while(top>0 && x[st[top-1]]<x[i])
		{
			l[st[top-1]]=i
			top--
		}
		st[top]=i
		top++
	}
	return l
}
fun workr(x:IntArray,n:Int):IntArray
{
	var st=IntArray(n+1)
	var top=0
	var r=IntArray(n+1){n+1}
	for(i in 1..n)
	{
		while(top>0 && x[st[top-1]]<x[i])
		{
			r[st[top-1]]=i
			top--
		}
		st[top]=i
		top++
	}
	return r
}
fun go()
{
	var T=readint()
	require(1<=T && T<=1e4)
	var sumn=0L
	while(T-->0)
	{
		var n=readint()
		require(1<=n && n<=5e5)
		sumn+=n
		require(sumn<=5e5)
		var pp=readline_int()
		require(pp.size==n)
		var vis=IntArray(n+1){0}
		for(it in pp)
		{
			require(1<=it && it<=n)
			vis[it]=1
		}
		for(i in 1..n) require(vis[i]==1)
		var p=IntArray(n+1){0}
		for(i in 0..n-1) p[i+1]=pp[i]
		var l=workl(p,n)
		var r=workr(p,n)
		var ans=0L
		var res=mutableListOf<Long>()
		for(i in 1..n) res.add(1L*(i-l[i])*(n-r[i]+1)+1L*i*(r[i]-i))
		println(res.joinToString(" "))
	}
}

