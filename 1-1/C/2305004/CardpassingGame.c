#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int m;
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        int t;
        scanf("%d",&t);
        t=t%n;
        if(i==0){
            printf("Initial Order: ");
            for(int i=0;i<n;i++)
            {
                printf("%d ",arr[i]);
            }
        }
        if(t>0){
            int l=0;
            int h=n-1;
            while(l<h){
                int temp=arr[l];
                arr[l]=arr[h];
                arr[h]=temp;
                l++;
                h--;
            }
            l=0;
            h=t-1;
            while(l<h){
                int temp=arr[l];
                arr[l]=arr[h];
                arr[h]=temp;
                l++;
                h--;
            }
            l=t;
            h=n-1;
            while(l<h){
                int temp=arr[l];
                arr[l]=arr[h];
                arr[h]=temp;
                l++;
                h--;
            }
        }
        else{
            int l=0;
            int h=n-1;
            while(l<h){
                int temp=arr[l];
                arr[l]=arr[h];
                arr[h]=temp;
                l++;
                h--;
            }
            l=0;
            h=n-(-t)-1;
            while(l<h){
                int temp=arr[l];
                arr[l]=arr[h];
                arr[h]=temp;
                l++;
                h--;
            }
            l=n-(-t);
            h=n-1;
            while(l<h){
                int temp=arr[l];
                arr[l]=arr[h];
                arr[h]=temp;
                l++;
                h--;
            }
        }
        printf("\nAfter instruction %d: ",i+1);
        for(int p=0;p<n;p++)
        {
            printf("%d ",arr[p]);
        }
    }
    int midx=0;
    int max=arr[0];
    for(int i=1;i<n;i++){
        if(max<arr[i]){
            max=arr[i];
            midx=i;
        }
    }
    printf("\nWinner: Child %d",midx+1);
    return 0;
}