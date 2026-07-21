class Solution {
public:
int fibonaci(int n ){
    if(n<=1){
        return n;
    }
    else return fibonaci(n-1)+fibonaci(n-2);
}
    int fib(int n) {
       return fibonaci(n);
        
    }
};