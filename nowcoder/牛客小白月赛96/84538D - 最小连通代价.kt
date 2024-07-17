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
fun go()
{
	var T=readint()
	require(T>=1 && T<=1000)
	var sumn=0
	while(T-->0)
	{
		var tmp_line=readline_int()
		require(tmp_line.size==3)
		var n=tmp_line[0]
		var a=tmp_line[1]
		var b=tmp_line[2]
		require(n>=1 && n<=2e5)
		sumn+=n
		require(sumn>=1 && sumn<=2e5)
		require(a>=-100 && a<=100)
		require(b>=-100 && b<=100)
		var x=readline_int()
		require(x.size==n)
		var cnt=IntArray(2){0}
		for(it in x)
		{
			require(it>=0 && it<=1e6)
			cnt[it and 1]+=1
		}
		if(cnt[0]==n||cnt[1]==n)
		{
			if(a<0) println("${n*(n-1)/2*a}")
			else println("${a*(n-1)}")
			continue
		}
		if(a<=0 && b<=0)
		{
			var ans=0L
			ans+=1L*cnt[0]*(cnt[0]-1)/2*a
			ans+=1L*cnt[1]*(cnt[1]-1)/2*a
			ans+=1L*cnt[0]*cnt[1]*b
			println("${ans}")
			continue
		}
		if(a<=0 && b>=0)
		{
			var ans=0L
			ans+=1L*cnt[0]*(cnt[0]-1)/2*a
			ans+=1L*cnt[1]*(cnt[1]-1)/2*a
			ans+=b
			println("${ans}")
			continue
		}
		if(a>=0 && b<=0)
		{
			var ans=0L
			ans+=1L*cnt[0]*cnt[1]*b
			println("${ans}")
			continue
		}
		// a>0 b>0
		var ans=b+a*(n-2)
		for(i in 2..n-1) ans=min(ans,i*b+a*(n-1-i))
		println("${ans}")
	}
}

