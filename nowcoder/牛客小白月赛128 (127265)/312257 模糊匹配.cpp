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
fun go()
{
	var T=readint()
	require(1<=T && T<=1e3)
	while(T-->0)
	{
		var n=readint()
		require(1<=n && n<=100)
		var s1=readstring()
		require(s1.length==n)
		var s2=readstring()
		require(s2.length==n)
		for(it in s1)
		{
			require(('0'<=it && it<='9') ||
					('a'<=it && it<='z') ||
					('A'<=it && it<='Z'))
		}
		for(it in s2)
		{
			require(('0'<=it && it<='9') ||
					('a'<=it && it<='z') ||
					('A'<=it && it<='Z'))
		}
		var ok=1
		for(i in 0..n-1)
		{
			var ch1=s1[i]
			var ch2=s2[i]
			if(ch1==ch2) continue
			if(ch1=='0') ch1='O'
			else if(ch1=='l') ch1='I'
			else if(ch1=='1') ch1='I'
			if(ch2=='0') ch2='O'
			else if(ch2=='l') ch2='I'
			else if(ch2=='1') ch2='I'
			if(ch1!=ch2) ok=0
		}
		if(ok==1) println("YES")
		else println("NO")
	}
}

