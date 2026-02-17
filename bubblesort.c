#include<stdio.h>
int main()
{
    int temp,n;
    int arr[50];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
  
    for(int i=0;i<n-1;i++)
        {
            for(int j=0;j<n-i-1;j++)
                {
                    if (arr[j]>arr[j+1])
                        {
                            temp=arr[j];
                            arr[j]=arr[j+1];
                            arr[j+1]=temp;
                        }
                        
                }
                
        }
    for(int i=0;i<n;i++)
        {
            printf("\n%d",arr[i]);
        }
    return 0;
}