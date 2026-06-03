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
const val MAX=1e7.toInt()+10
const val mod=998244353
/*------------------------------------------------------------*/
fun qpow(aa:Long,bb:Int,p:Int):Long
{
	var res=1L
	var a=aa
	var b=bb
	while(b>0)
	{
		if((b and 1)==1) res=res*a%p
		a=a*a%p
		b=b shr 1
	}
	return res
}
fun go()
{
	var T=readint()
	require(1<=T && T<=100)
	var sumn=0
	var sumk=0
	while(T-->0)
	{
		var tmp_line=readline_int()
		var n=tmp_line[0]
		var k=tmp_line[1]
		require(1<=n && n<=5e3)
		require(1<=k && k<=5e3)
		sumn+=n
		sumk+=k
		require(sumn<=5e3)
		require(sumk<=5e3)
		var a=readline_int()
		require(a.size==n)
		for(it in a) require(0<=it && it<=n)
		var cnt=IntArray(n+2){0}
		for(it in a) cnt[it]++
		var mex=0
		while(cnt[mex]>0) mex++
		var ans=mutableListOf<Long>()
		for(x in 0..n)
		{
			if(x<mex)
			{
				ans.add(0L)
				continue
			}
			var res=0L
			for(i in 0..k)
			{
				res=(res+qpow(x.toLong(),i,mod))%mod
				if(x>mex) res=(res-qpow((x-1).toLong(),i,mod)+mod)%mod
			}
			ans.add(res)
		}
		println(ans.joinToString(" "))
	}
}
