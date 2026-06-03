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
data class pair(var first:Int,var second:Int)
const val INF=0x3f3f3f3f
const val LLINF=0x3f3f3f3f3f3f3f3fL
const val MAX=1e7.toInt()+10
const val mod=1e9.toInt()+7
/*------------------------------------------------------------*/
fun go()
{
	var s=readstring()
	require(1<=s.length && s.length<=10)
	for(it in s)
	{
		if(it!='/') require('a'<=it && it<='z')
	}
	var ans=mutableListOf<Char>()
	var pre='a'
	for(it in s)
	{
		if(pre=='/' && it=='/')
		{
			ans.removeLast()
			break
		}
		pre=it
		ans.add(it)
	}
	if(ans.size==0) println("null")
	else println(ans.joinToString(""))
}
