#include<stdio.h>
int main(){
    int i,j,n,temp,diskSize,intialP,request[20],TotalHeadM=0,direction;
    printf("Enter the disk size :- ");
    scanf("%d",&diskSize);
    printf("Enter no of requests :- ");
    scanf("%d",&n);
    printf("Enter the request sequence :- \n");
    for(i=0;i<n;i++){
        scanf("%d",&request[i]);
    }
    printf("Enter intial position of head :- ");
    scanf("%d",&intialP);
    printf("Enter direction of previous movement (Left to Right:- 0 else 1) :- ");
    scanf("%d",&direction);
//sorting the references
    for(i=0;i<n;i++){
        for(j=0;j<n-1-i;j++){
            if(request[j]>request[j+1]){
                temp=request[j];
                request[j]=request[j+1];
                request[j+1]=temp;
            }
        }
    }
    if(direction==0){
        TotalHeadM=(diskSize-intialP)+(diskSize-request[0]);
        printf("Total Head movement :- %d",TotalHeadM);
    }
    else if(direction==1){
        TotalHeadM=intialP+request[n-1];
        printf("Total Head movement :- %d",TotalHeadM);
    }
    else{
        printf("Enter a valid input");
    }
    return 0;
}