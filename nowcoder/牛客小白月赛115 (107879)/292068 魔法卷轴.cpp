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
	require(T>=1 && T<=100)
	while(T-->0)
	{
		var n=readint()
		require(n>=1 && n<=2e5)
		var a=readline_int().sorted().toIntArray()
		require(a.size==n)
		var ok=1
		var mp:MutableMap<Int,Int> = mutableMapOf()
		for(i in n-1 downTo 0)
		{
			if(i>0) require(a[i]>=a[i-1])
			require(a[i]>=1 && a[i]<=1e9)
			if(!mp.containsKey(a[i]+1)) mp[a[i]+1]=mp[a[i]+1]?:1
			else if(!mp.containsKey(a[i]-1)) mp[a[i]-1]=mp[a[i]-1]?:1
			else ok=0
		}
		if(ok==0)
		{
			println("NO")
			continue
		}
		var res=mutableListOf<Int>()
		for(it in mp.keys) res.add(it)
		res.sort()
		var now=0
		var pre=0
		for(it in res)
		{
			now+=it-pre-1
			now--
			pre=it
			if(now<0) ok=0
		}
		if(ok==0) println("NO")
		else println("YES")
	}
}
/*
3
4
2 3 6 7
4
2 3 5 6
9
41 42 42 43 43 44 46 47 47
*/
