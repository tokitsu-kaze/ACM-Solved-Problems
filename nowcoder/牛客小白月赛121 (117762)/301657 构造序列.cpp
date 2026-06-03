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
data class pair(var fi:Long,var se:Int)
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
const val M=500;
var pd=Array(MAX){IntArray(M){0}}
fun init_pd(n:Int)
{
	pd[0][0]=1
	for(i in 1..n)
	{
		for(j in 1..min(i,M-1))
		{
			pd[i][j]=pd[i-j][j-1]+pd[i-j][j]
			if(pd[i][j]>=mod) pd[i][j]-=mod
		}
	}
}
fun go()
{
	init_pd(MAX-10)
	var tmp_line=readline_int()
	require(tmp_line.size==2)
	var n=tmp_line[0]
	var m=tmp_line[1]
	require(1<=n && n<=1e5)
	require(1<=m && m<=1e9)
	var ans=0L
	var now=m.toLong()
	for(i in 1..M-1)
	{
		ans=(ans+pd[n][i]*now)%mod
		now=now*(m-1)%mod
	}
	println("${ans}")
}

