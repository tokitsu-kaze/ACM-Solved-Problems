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
const val mod=998244353
/*------------------------------------------------------------*/
fun go()
{
	var tmp_line=readline_int()
	require(tmp_line.size==2)
	var n=tmp_line[0]
	var m=tmp_line[1]
	require(n>=1 && n<=3000)
	require(m>=1 && m<=5e5)
	var bit=Array(2*n+3){IntArray(2*n+3){0}}
	while(m-->0)
	{
		tmp_line=readline_int()
		require(tmp_line.size==3)
		var x=tmp_line[0]
		var y=tmp_line[1]
		var r=tmp_line[2]
		require(x>=1 && x<=n)
		require(y>=1 && y<=n)
		require(r>=0 && r<=6000)
		var xx=x+y
		var yy=x-y+n
		var a=max(1,xx-r)
		var b=max(1,yy-r)
		var c=min(2*n,xx+r)
		var d=min(2*n,yy+r)
		bit[a][b]=bit[a][b] xor 1
		bit[c+1][b]=bit[c+1][b] xor 1
		bit[a][d+1]=bit[a][d+1] xor 1
		bit[c+1][d+1]=bit[c+1][d+1] xor 1
	}
	var ans=0
	for(j in 1..2*n)
	{
		for(i in 1..2*n)
		{
			bit[i][j]=bit[i][j] xor bit[i-1][j] xor bit[i][j-1] xor bit[i-1][j-1]
			if(bit[i][j]==0) continue
			if((i+j-n)%2!=0) continue
			var x=(i+j-n)/2
			var y=i-x
			if(x>=1 && x<=n && y>=1 && y<=n) ans++
		}
	}
	println("${ans}")
}

