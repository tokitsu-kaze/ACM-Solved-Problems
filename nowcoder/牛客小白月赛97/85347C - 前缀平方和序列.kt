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
data class pair(var fi:Long,var se:Long)
/*using: xxx.sortWith(cmp)*/
val cmp: Comparator<pair> = Comparator{ a,b->
	if (a.fi==b.fi) a.se.compareTo(b.se)
	else a.fi.compareTo(b.fi)
}
const val INF=0x3f3f3f3f
const val LLINF=0x3f3f3f3f3f3f3f3fL
const val MAX=1e5.toInt()+10
const val mod=1e9.toInt()+7
/*------------------------------------------------------------*/
var comb=Array(1002){IntArray(1002)}
fun init(n:Int,m:Int)
{
	comb[0][0]=1;
	for(i in 1..n)
	{
		comb[i][0]=1;
		for(j in 1..m)
		{
			comb[i][j]=comb[i-1][j]+comb[i-1][j-1];
			if(comb[i][j]>=mod) comb[i][j]-=mod;
		}
	}
}
fun C(n:Int,m:Int):Int
{
	if(m>n||m<0||n<0) return 0;
	return comb[n][m];
}
fun go()
{
	init(1000,1000)
	var tmp_line=readline_int()
	require(tmp_line.size==2)
	var n=tmp_line[0]
	var x=tmp_line[1]
	require(n>=1 && n<=1e3)
	require(x>=1 && x<=1e6)
	var t=1
	while(t*t<=x) t++
	t--
	println("${C(t,n)}")
}

