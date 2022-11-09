package main

import "fmt"
import "os"
import "bufio"
import "strconv"

func min(a,b int)int {
    var res int;
    if a<b {
        res=a
    } else {
        res=b;
    }
    return res;
}

func solve(){
    var n,i,odd,even,x,ans int
    n=readInt()
    odd=0
    even=0
    for i=0;i<n;i++ {
        x=readInt()
        if x%2==1 {
            odd++
        } else {
            even++;
        }
    }
    ans=min(odd,even);
    odd-=ans;
    ans+=odd/3;
    fmt.Println(ans)
}


var scanner *bufio.Scanner

func main() {
	scanner = bufio.NewScanner(os.Stdin)
	const MaxTokenLength = 1024 * 1024
	scanner.Buffer(make([]byte, 0, MaxTokenLength), MaxTokenLength)
	scanner.Split(bufio.ScanWords)
	solve()
}
func readString() string {
	scanner.Scan()
	return scanner.Text()
}

func readInt() int {
	val, _ := strconv.Atoi(readString())
	return val
}

func readInt64() int64 {
	v, _ := strconv.ParseInt(readString(), 10, 64)
	return v
}