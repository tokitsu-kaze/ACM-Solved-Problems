fun readint()=readLine()!!.toInt()
fun readll()=readLine()!!.toLong()
fun readline_int()=(readLine()!!.split(" ").map{it.toInt()}).toIntArray()
fun readline_ll()=(readLine()!!.split(" ").map{it.toLong()}).toLongArray()
fun main()
{
	var t=readint()
	while(t-->0)
	{
		var tmp=readline_int()
		var n=tmp[0]
		var s=readLine()!!
		var p=readline_int()
		var bit=Array(n+1){0}
		for(it in p)
		{
			bit[0]++
			bit[it]--
		}
		var cnt=Array(26){0}
		for(i in 0 until n)
		{
			if(i>0) bit[i]+=bit[i-1]
			cnt[s[i]-'a']+=bit[i]+1
		}
		for(i in 0 until 26) print("${cnt[i]} ")
		println()
	}
}