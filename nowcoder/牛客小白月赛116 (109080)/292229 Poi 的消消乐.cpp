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
	var T=readint()
	require(T>=1 && T<=1e6)
	var sumn=0
	var res=mutableListOf<Int>()
	while(T-->0)
	{
		var n=readint()
		require(n>=1 && n<=2e6)
		sumn+=n
		require(sumn>=1 && sumn<=2e6)
		var s=readstring()
		require(s.length==n)
		var cnt=IntArray(26){0}
		for(it in s) cnt[it-'A']++
		var kd=0
		for(i in 0..25)
		{
			if(cnt[i]>0) kd++
		}
		require(kd<=2)
		if(kd==1)
		{
			res.add(1)
			continue
		}
		var pos=1
		for(i in 1..n-1)
		{
			if(s[i]!=s[0])
			{
				pos=i
				break;
			}
		}
		var ok=0
		for(i in pos+1..n-1)
		{
			if(s[i]==s[0])
			{
				ok=1
				break
			}
		}
		if(ok==1) res.add(2)
		else res.add(1+min(3,n-pos))
	}
	println(res.joinToString("\n"))
}
/*
i=j=0  k=l=1  k=1,l=2
i=j=1  k=2
AAABBBBBB ->  ABBB
ABAAABABBABABB -> ABABBBBBBB -> BABBBBBB -> BA
*/ 
