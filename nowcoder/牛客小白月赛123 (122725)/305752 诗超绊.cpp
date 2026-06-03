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
const val mod=1e9.toInt()+7
/*------------------------------------------------------------*/
fun ck(n:Int,a:IntArray,m:Int,d:Int):Boolean
{
	var cnt=0L
	for(i in 1..n-1)
	{
		if(a[i-1]<a[i]) continue
		cnt+=(a[i-1]-a[i])/d+1
	}
	return cnt<=m
}
fun go()
{
	var T=readint()
	require(1<=T && T<=500)
	var sumn=0
	while(T-->0)
	{
		var tmp_line=readline_int()
		require(tmp_line.size==2)
		var n=tmp_line[0]
		var m=tmp_line[1]
		require(1<=n && n<=2e5)
		require(0<=m && m<=1e9)
		sumn+=n
		require(sumn<=2e5)
		var a=readline_int()
		require(a.size==n)
		for(it in a) require(0<=it && it<=1e9)
		var ok=1
		for(i in 1..n-1)
		{
			if(a[i]<=a[i-1]) ok=0
		}
		if(ok==1)
		{
			println("0")
			continue
		}
		var l=1
		var r=1e9.toInt()+100
		while(l<r)
		{
			var mid=(l+r) shr 1
			if(ck(n,a,m,mid)) r=mid
			else l=mid+1
		}
		if(ck(n,a,m,l)) println("${l}")
		else println("-1")
	}
}

