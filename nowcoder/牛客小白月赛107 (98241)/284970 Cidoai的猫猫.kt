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
	require(n>=1 && n<=5e6)
	var s=readstring()
	require(s.length==n)
	var cnt=IntArray(n+1){0}
	var now=0
	for(i in 0..n-1)
	{
		require(s[i]>='a' && s[i]<='z')
		if(i==0 || (i>0 && s[i]==s[i-1])) now++
		else
		{
			cnt[now]++
			now=1
		}
	}
	cnt[now]++
	var suf=IntArray(n+2){0}
	for(i in n downTo 1) suf[i]=suf[i+1]+cnt[i]
	var ans=0L
	var sum=0L
	for(i in 1..n)
	{
		ans=ans xor (1L*i*(sum+1L*i*suf[i]))
		sum=sum+1L*i*cnt[i]
	}
	println("${ans}")
}

