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
	var n=readint()
	require(1<=n && n<=100000)
	var mx=IntArray(6){0}
	var pos=IntArray(6){0}
	for(i in 0..n-1)
	{
		var tmp=readline_string()
		require(tmp.size==2)
		var s=tmp[0]
		var v=tmp[1].toInt()
		require(s.length==1)
		require('A'<=s[0] && s[0]<='F')
		require(0<=v && v<=100)
		var c=(s[0]-'A').toInt()
		if(mx[c]<v)
		{
			mx[c]=v;
			pos[c]=i+1
		}
	}
	var ok=true
	var sum=0
	for(i in 0..5)
	{
		if(mx[i]<60) ok=false
		sum+=mx[i]
	}
	if(sum<6*70) ok=false
	if(ok) println(pos.joinToString(" "))
	else println("-1")
}
