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
/*using: xxx.sortWith(pair_cmp)*/
val pair_cmp: Comparator<pair> = Comparator{ a,b->
	if (a.fi==b.fi) a.se.compareTo(b.se)
	else a.fi.compareTo(b.fi)
}
const val INF=0x3f3f3f3f
const val LLINF=0x3f3f3f3f3f3f3f3fL
const val MAX=1e5.toInt()+10
const val mod=998244353//1e9.toInt()+7
/*------------------------------------------------------------*/
fun go()
{
	var tmp_line=readline_int()
	require(tmp_line.size==2)
	var n=tmp_line[0]
	var k=tmp_line[1]
	require(n>=1 && n<=1e5)
	require(k>=0 && k<=2e9)
	var a=readline_int()
	require(a.size==n)
	for(it in a) require(it>=-1e9 && it<=1e9)
	var cnt=0
	for(i in 1..n)
	{
		k-=cnt
		if(k<0) break
		k++
		cnt++
	}
	var now=0L
	var pre=LongArray(n+1){0}
	for(i in 1..cnt)
	{
		now+=a[i-1]
		pre[i]=max(pre[i-1],now)
	}
	now=0L
	var suf=LongArray(n+1){0}
	for(i in 1..cnt)
	{
		now+=a[n-i]
		suf[i]=max(suf[i-1],now)
	}
	var ans=0L
	for(i in 0..cnt) ans=max(ans,pre[i]+suf[cnt-i])
	println("${ans}")
}

