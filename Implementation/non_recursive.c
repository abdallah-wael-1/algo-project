#include <stdio.h>
#include <stdlib.h>

int DiagonalDifference(int n,int arr[n][n]);
int main()
{
    int n,result;
    printf("Enter array size\n");
    scanf("%d",&n);
    int array[n][n];
    printf("Enter array elements\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&array[i][j]);
            while(array[i][j]<=-100 || array[i][j]>=100){
                printf("Invalid input,Enter a value again");
                scanf("%d",&array[i][j]);
            }
        }
    }
    result=DiagonalDifference(n,array);
    printf("Difference is %d\n",result);
    return 0;
}
int DiagonalDifference(int n,int array[n][n]){
    int sum1=0,sum2=0,result;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            // Primary Diagonal
            if(i==j){
                sum1+=array[i][j];
            }
            // Secondary Diagonal
            if(i+j==n-1){
                sum2+=array[i][j];
            }
        }
    }
    if(sum1>sum2)
        result=sum1-sum2;
    else
        result=sum2-sum1;
    return result;
}
