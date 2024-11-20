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
	while(T-->0)
	{
		var tmp_line=readline_int()
		var n=tmp_line[0]
		var m=tmp_line[1]
		var a=readline_int()
		var dp=Array(m+2){Array(n+2){IntArray(n+2){INF}}}
		var g=Array(m+2){Array(n+2){IntArray(n+2){INF}}}
		for(i in 1..n)
		{
			for(k in 1..m)
			{
				if(a[i-1]!=k) dp[k][i][i]=1
				else dp[k][i][i]=0
				if(a[i-1]==k) g[k][i][i]=1
				else g[k][i][i]=0
			}
		}
		for(len in 2..n)
		{
			for(l in 1..n-len+1)
			{
				var r=l+len-1
				for(i in 1..m)
				{
					for(mid in l..r-1)
					{
						dp[i][l][r]=min(dp[i][l][r],dp[i][l][mid]+dp[i][mid+1][r])
						g[i][l][r]=min(g[i][l][r],g[i][l][mid]+g[i][mid+1][r])
					}
					dp[i][l][r]=min(dp[i][l][r],g[i][l][r]+1)
					for(j in 1..m)
					{
						if(i==j) continue
						g[j][l][r]=min(g[j][l][r],dp[i][l][r])
					}
				}
			}
		}
		var ans=INF
		for(i in 1..m) ans=min(ans,dp[i][1][n])
		println("${ans}")
	}
}
