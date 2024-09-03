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
const val MAX=1e5.toInt()+10
const val mod=998244353//1e9.toInt()+7
/*------------------------------------------------------------*/
var p=IntArray(1)
var prime=IntArray(1)
var tot=0
fun init_prime(n:Int)
{
	tot=0
	p=IntArray(n+1)
	prime=IntArray(n+1){0}
	prime[1]=1;
	for(i in 2..n)
	{
		if(prime[i]==0)
		{
			prime[i]=i
			p[tot++]=i
		}
		for(j in 0..tot-1)
		{
			if(p[j]*i>n) break
			prime[i*p[j]]=p[j]
			if(i%p[j]==0) break
		}
	}
}
fun go()
{
	init_prime(1e7.toInt())
	var T=readint()
	require(T>=1 && T<=5e4)
	var sumn=0
	while(T-->0)
	{
		var n=readint()
		require(n>=1 && n<=2e5)
		sumn+=n
		require(sumn>=1 && sumn<=2e5)
		var a=readline_int()
		require(a.size==n)
		var s=TreeSet<Int>()
		for(it in a)
		{
			require(it>=2 && it<=1e9)
			s.add(it)
		}
		for(i in 0..tot-1)
		{
			if(!s.contains(p[i]))
			{
				println("${p[i]}")
				break
			}
		}
	}
}

