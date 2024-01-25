/* https://www.interviewbit.com/problems/verify-prime/ */

int isPrime(int a) {
    int cnt=0;
    if(a==1) return false;
    for(int i=1;i*i<=a;i++)
    {
        if(a%i==0)
        cnt++;
    }
    if(cnt==1)return true;
    
    return false;
}
