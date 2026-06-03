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
const val MAX=1e5.toInt()+10
const val mod=998244353
/*------------------------------------------------------------*/
fun go()
{
	var T=readint()
	require(1<=T && T<=100)
	var sumn=0
	while(T-->0)
	{
		var tmp_line=readline_int()
		require(tmp_line.size==2)
		var n=tmp_line[0]
		var k=tmp_line[1]
		require(2<=n && n<=2e5)
		require(1<=k && k<n)
		sumn+=n
		require(sumn<=2e5)
		var d=readline_int()
		require(d.size==n)
		for(it in d) require(1<=it && it<n)
		var tmp=mutableListOf<pair>()
		var cnt1=0
		
		for(i in 1..n)
		{
			tmp.add(pair(d[i-1],i))
			if(d[i-1]==1) cnt1++
		}
		if(k==1 || cnt1>k)
		{
			println("-1")
			continue
		}
		tmp.sortWith(pair_cmp)
		var sumd=0L+k
		for(i in k..n-1) sumd+=tmp[i].fi
		if(sumd<2*n-2)
		{
			println("-1")
			continue
		}
		var res=mutableListOf<pair>()
		for(i in k..n-1)
		{
			res.add(pair(tmp[i-1].se,tmp[i].se))
			tmp[i-1].fi--
			tmp[i].fi--
		}
		res.add(pair(tmp[0].se,tmp[n-1].se))
		tmp[n-1].fi--
		var now=n-1
		for(i in 1..k-2)
		{
			while(now>=0 && tmp[now].fi==0) now--
			res.add(pair(tmp[i].se,tmp[now].se))
			tmp[now].fi--
		}
		for(it in res) println("${it.fi} ${it.se}")
	}
}
