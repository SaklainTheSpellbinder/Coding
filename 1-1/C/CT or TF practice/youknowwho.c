#include<stdio.h>
int main(){
    int n;
    char ch;
    scanf("%c",&ch);
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++)
    {
        while(arr[i])
        {
            printf("%c",ch);
            arr[i]--;
        }
        printf("\n");
    }
    return 0;
}