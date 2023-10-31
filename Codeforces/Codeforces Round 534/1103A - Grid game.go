package main

import "fmt"
import "os"
import "bufio"
import "strconv"

func min(a,b int)int {
    var res int
    if a<b {
        res=a
    } else {
        res=b;
    }
    return res;
}

func solve(){
    var s string
    s=readString()
    var n,i,r,c int
    n=len(s)
    r=1
    c=1
    for i=0;i<n;i++{
        if s[i]=='0'{
            fmt.Println(1,c)
            c=c+1
            if c==5{
                c=1
            }
        }else{
            fmt.Println(3,r)
            r=r+2
            if r==5{
                r=1
            }
        }
    }
    
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