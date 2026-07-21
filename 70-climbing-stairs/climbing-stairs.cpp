class Solution {
public:
 int t[46];
int climb(int n){
   if(t[n]!=-1){
    return t[n];
   }
    if(n==1) return 1;
    if(n==2) return 2;
    return t[n]= climb(n-1)+climb(n-2);
}
    int climbStairs(int n) {
        memset(t , -1 , sizeof(t));
        return climb(n);
    }
};