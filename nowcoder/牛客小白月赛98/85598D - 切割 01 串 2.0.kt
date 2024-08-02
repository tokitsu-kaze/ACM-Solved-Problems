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
var x=0
var y=0
var s=""
var dp=Array(1){IntArray(1)}
fun dfs(l:Int,r:Int):Int
{
	if(l==r) return 0
	if(dp[l][r]!=-1) return dp[l][r]
	var res=0
	var cnt0=0
	var cnt1=0
	for(i in l..r)
	{
		if(s[i]=='1') cnt1++
	}
	for(i in l..r-1)
	{
		if(s[i]=='0') cnt0++
		else cnt1--
		var tmp=abs(cnt0-cnt1)
		if(tmp>=x && tmp<=y) res=max(res,dfs(l,i)+dfs(i+1,r)+1)
	}
	dp[l][r]=res
	return dp[l][r];
}
fun go()
{
	var tmp_line=readline_int()
	require(tmp_line.size==3)
	var n=tmp_line[0]
	x=tmp_line[1]
	y=tmp_line[2]
	require(n>=1 && n<=500)
	require(x>=0 && x<=500)
	require(y>=x && y<=500)
	s=readstring()
	for(it in s) require(it=='0'||it=='1')
	dp=Array(n){IntArray(n){-1}}
	println("${dfs(0,n-1)}")
}

