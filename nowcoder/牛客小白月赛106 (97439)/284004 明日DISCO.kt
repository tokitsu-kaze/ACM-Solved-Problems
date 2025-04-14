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
const val MAX=300000+10
/*------------------------------------------------------------*/
var dir=arrayOf(
arrayOf(0,1),
arrayOf(1,0),
arrayOf(0,-1),
arrayOf(-1,0)
)
fun go()
{
	var n=readint()
	require(n>=1 && n<=500)
	var a=Array(n){IntArray(n)}
	for(i in 0..n-1)
	{
		a[i]=readline_int()
		require(a[i].size==n)
		for(j in 0..n-1)
		{
			require(a[i][j]>=-1e9 && a[i][j]<=1e9)
			if(a[i][j]>0) a[i][j]=1
			else if(a[i][j]<0) a[i][j]=-1
		}
	}
	var ok=1
	for(i in 0..n-1)
	{
		for(j in 0..n-1)
		{
			if(a[i][j]==0) continue
			for(k in 0..3)
			{
				var x=i+dir[k][0]
				var y=j+dir[k][1]
				if(x<0 || x>=n || y<0 || y>=n) continue
				if(a[i][j]*a[x][y]>0) ok=0
			}
		}
	}
	if(ok==1) println("YES")
	else println("NO")
}
