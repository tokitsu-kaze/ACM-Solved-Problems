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
/*------------------------------------------------------------*/
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
		var m=tmp_line[1]
		require(n>=1 && n<=2e5)
		require(m>=1 && m<=n)
		sumn+=n
		require(sumn>=1 && sumn<=2e5)
		var h=readline_int()
		require(h.size==n)
		var x=readline_int()
		require(x.size==n)
		var tmp=mutableListOf<pair>()
		for(i in 0..n-1)
		{
			require(h[i]>=1 && h[i]<=1e9)
			require(x[i]>=1 && x[i]<=1e9)
			tmp.add(pair(x[i],h[i]))
		}
		tmp.sortWith(cmp)
		var res=mutableListOf<Int>()
		var mx=0
		var now=0
		for(i in 0..n-1)
		{
			if(i>0) require(tmp[i].fi>tmp[i-1].fi)
			if(tmp[i].fi>mx)
			{
				if(now>0) res.add(now)
				now=1
				mx=tmp[i].fi+tmp[i].se
			}
			else
			{
				now++
				mx=max(mx,tmp[i].fi+tmp[i].se)
			}
		}
		if(now>0) res.add(now)
		res.sort()
		res.reverse()
		var ans=0
		for(i in 0..min(res.size,m)-1) ans+=res[i]
		println("${ans}")
	}
}

