int evensum(int n){
    if(n==0)
        return 0;
    if(n%2==0){
        return (n%10)+evensum(n/10);
    }
    else
        return evensum(n/10);
}