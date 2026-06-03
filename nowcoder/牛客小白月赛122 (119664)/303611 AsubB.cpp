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
const val MAX=1e5.toInt()+10
const val mod=1e9.toInt()+7
/*------------------------------------------------------------*/
fun go()
{
	var n=readint()
	require(1<=n && n<=2000)
	var aa=readline_int()
	require(aa.size==n)
	for(it in aa) require(1<=it && it<=1e9)
	
	var a=Array(n+1){0}
	for(i in 1..n) a[i]=aa[i-1]
	var pre=Array(n+1){IntArray(n+1){0}}
	for(i in 2..n)
	{
		var k=1
		var now=0
		for(j in i..n)
		{
			while(k<i && a[k]!=a[j]) k++
			if(k<i && a[k]==a[j])
			{
				k++
				now++
			}
			pre[i][j]=now
		}
	}
	var suf=Array(n+1){IntArray(n+1){0}}
	for(i in n-1 downTo 1)
	{
		var k=n
		var now=0
		for(j in i downTo 1)
		{
			while(k>i && a[k]!=a[j]) k--
			if(k>i && a[k]==a[j])
			{
				k--
				now++
			}
			suf[j][i]=now
		}
	}
	var ans=0
	for(i in 2..n-1)
	{
		for(j in i..n-1)
		{
			if(pre[i][j]+suf[i][j]>=j-i+1) ans++
		}
	}
	println("${ans}")
}

