#include<stdio.h>
#include<string.h>
int main(){
    int arr[10]={1,2,3,4,5,6,6,7,7,9};
    //memset(arr,'#',sizeof(arr));
    for(int i=0;i<10;i++)
    {
        for(int j=i+1;j<10;j++)
        {
            if(arr[i]==arr[j])
            {
                printf("Duplicate is %d\n",arr[i]);
                break;
            }
        }
    }
    // for(int i=0;i<10;i++)
    // {
    //     printf("%d",arr[i]);
    // }
//     typedef union pokemon{
//         int hp;
//         int attack;
//         int speed;
        
// //        int arr[23];
//         char name[10];
//     }saklain;
//     saklain guru;
//     printf("%zu",sizeof(guru));
    return 0;
}