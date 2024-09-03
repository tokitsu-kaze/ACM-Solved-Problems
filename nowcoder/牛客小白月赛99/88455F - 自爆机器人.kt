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
	require(T>=1 && T<=1e4)
	var sumn=0
	var sumt=0
	while(T-->0)
	{
		var tmp_line=readline_int()
		require(tmp_line.size==3)
		var n=tmp_line[0]
		var m=tmp_line[1]
		var t=tmp_line[2]
		require(n>=1 && n<=2e5)
		require(m>=1 && m<n)
		require(t>=1 && t<=2e5)
		sumn+=n
		sumt+=t
		require(sumn>=1 && sumn<=2e5)
		require(sumt>=1 && sumt<=2e5)
		var x=readline_int().sorted()
		require(x.size==m)
		for(it in x) require(it>=1 && it<n)
		for(i in 1..m-1) require(x[i]>x[i-1])
		if(t<n)
		{
			println("0")
			continue
		}
		var ans=n
		t-=n
		var tmp=mutableListOf<Int>()
		for(i in 1..m-1) tmp.add(2*(x[i]-x[i-1]))
		tmp.sort()
		var res=mutableListOf<Int>()
		for(it in tmp)
		{
			if(res.size==0 || it!=res.last()) res.add(it)
		}
		var dp=BooleanArray(t+1){false}
		dp[0]=true
		for(it in res)
		{
			for(i in it..t)
			{
				if(dp[i-it]) dp[i]=true
			}
		}
		for(i in t downTo 0)
		{
			if(dp[i])
			{
				ans+=i
				break
			}
		}
		println("${ans}")
	}
}

