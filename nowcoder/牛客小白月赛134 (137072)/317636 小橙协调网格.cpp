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
fun readline_ull()=(readLine()!!.split(" ").map{it.toULong()}).toULongArray()
fun readline_db()=(readLine()!!.split(" ").map{it.toDouble()}).toDoubleArray()
fun readline_string()=(readLine()!!.split(" "))
fun main(args: Array<String>){go()}
data class pair(var fi:Int,var se:Long)
/*using: xxx.sortWith(pair_cmp)*/
val pair_cmp: Comparator<pair> = Comparator{ a,b->
	if (a.fi==b.fi) a.se.compareTo(b.se)
	else a.fi.compareTo(b.fi)
}
const val INF=0x3f3f3f3f
const val LLINF=0x3f3f3f3f3f3f3f3fL
const val MAX=1e5.toInt()+10
const val mod=998244353
/*------------------------------------------------------------*/
var mp=Array(1){IntArray(1)}
var sum=Array(1){IntArray(1)}
var n=0
var m=0
fun upd(xx1:Int,yy1:Int,xx2:Int,yy2:Int,v:Int)
{
	var x1=max(1,xx1)
	var y1=max(1,yy1)
	var x2=min(n,xx2)
	var y2=min(m,yy2)
	sum[x1][y1]+=v
	sum[x1][y2+1]-=v
	sum[x2+1][y1]-=v
	sum[x2+1][y2+1]+=v
}
fun go()
{
	var tmp_line=readline_int()
	require(tmp_line.size==2)
	n=tmp_line[0]
	m=tmp_line[1]
	require(1<=n && n<=2000)
	require(1<=m && m<=2000)
	mp=Array(n+2){IntArray(m+2)}
	for(i in 1..n)
	{
		tmp_line=readline_int()
		require(tmp_line.size==m)
		for(j in 1..m)
		{
			mp[i][j]=tmp_line[j-1]
			require(0<=mp[i][j] && mp[i][j]<=max(n,m))
		}
	}
	sum=Array(n+2){IntArray(m+2){0}}
	for(i in 1..n)
	{
		for(j in 1..m)
		{
			var x=mp[i][j]
			upd(i-x,j-x,i+x,j+x,1)
			if(x>0) upd(i-x+1,j-x+1,i+x-1,j+x-1,-1)
		}
	}
	var mx=0
	for(i in 1..n)
	{
		for(j in 1..m)
		{
			sum[i][j]+=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]
			mx=max(mx,sum[i][j])
		}
	}
	println("${n*m-mx}")
}

