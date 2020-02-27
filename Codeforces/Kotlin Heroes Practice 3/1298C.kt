fun readint()=readLine()!!.toInt()
fun readll()=readLine()!!.toLong()
fun readline_int()=(readLine()!!.split(" ").map{it.toInt()}).toIntArray()
fun readline_ll()=(readLine()!!.split(" ").map{it.toLong()}).toLongArray()
fun main()
{
	var n=readint()
	var s=readLine()!!
	var ans=0
	var cnt=0
	for(i in 0 until n)
	{
		if(s[i]=='x') cnt++
		else
		{
			ans+=maxOf(0,cnt-2)
			cnt=0
		}
	}
	ans+=maxOf(0,cnt-2)
	cnt=0
	println("${ans}")
}
