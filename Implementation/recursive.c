#include <stdio.h>
#include <stdlib.h>

int DiagonalDifference(int n,int i,int arr[n][n]);
int main()
{
    int n,result;
    printf("Enter array size\n");
    scanf("%d",&n);
    int arr[n][n];
    printf("Enter array elements\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
            while(arr[i][j]<=-100 || arr[i][j]>=100){
                printf("Invalid input,Enter a value again\n");
                scanf("%d",&arr[i][j]);
            }
        }
    }
    result=DiagonalDifference(n,0,arr);
    if(result<0){
        result=-result;
    }
    printf("Difference is %d\n",result);
    return 0;
}
int DiagonalDifference(int n,int i,int arr[n][n]){
    if(i==n)
        return 0;
    int res = arr[i][i]-arr[i][n-1-i];
    return res + DiagonalDifference(n,i+1,arr);
}
