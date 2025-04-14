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
fun go()
{
	var n=readint()
	require(n>=1 && n<=1e5)
	var a=readline_int()
	require(a.size==n)
	var d=readline_int()
	require(d.size==n)
	var res=mutableListOf<pair>()
	var sumd=0L
	for(i in 0..n-1)
	{
		require(a[i]>=1 && a[i]<=1e9)
		require(d[i]>=1 && d[i]<=n-1)
		sumd=sumd+d[i]
		res.add(pair(a[i],d[i]))
	}
	require(sumd>=2*(n-1))
	res.sortBy({it.fi})
	var ans=0L
	var p=1
	for(i in 0..n-1)
	{
		for(j in 1..res[i].se)
		{
			if(p==n) break
			ans+=res[i].fi
			p++
		}
		if(p==n) break;
	}
	println("${ans}")
}

