#include<stdio.h>
struct process{
    int no;
    int arrivalTime;
    int burstTime;
    int completionTime;
    int turnaroundTime;
    int waitingTime;
};struct process p[10],temp;
int main(){
    int n,i,j,com;
    float avgWaitingTime=0,avgTurnAroundtime=0,totalTurn=0,totalWait=0;
    printf("Enter no. of process :-  ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter Arrival Time of p[%d] :- ",i);
        scanf("%d",&p[i].arrivalTime);
        printf("Enter Burst Time of p[%d] :- ",i);
        scanf("%d",&p[i].burstTime);
        p[i].no=i;
    }
    //sorting the process 
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1-i;j++){
            if(p[j].arrivalTime > p[j+1].arrivalTime){
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
    com=0;
    for(i=0;i<n;i++){
        if(com<p[i].arrivalTime){
            com=p[i].arrivalTime;
        }
       p[i].completionTime=com+p[i].burstTime;
       com=p[i].completionTime;
       p[i].turnaroundTime=p[i].completionTime-p[i].arrivalTime;
       p[i].waitingTime=p[i].turnaroundTime-p[i].burstTime;
    }
    for(i=0;i<n;i++){
        totalTurn=totalTurn+p[i].turnaroundTime;
        totalWait=totalWait+p[i].waitingTime;
    }
    printf("\nPro    arr    bur   com    turn   wait \n");
    for(i=0;i<n;i++){
    printf("p[%d]    %d     %d    %d      %d     %d  \n",p[i].no,p[i].arrivalTime,p[i].burstTime,p[i].completionTime,p[i].turnaroundTime,p[i].waitingTime);
    }
    avgTurnAroundtime=(totalTurn/n);
    avgWaitingTime=(totalWait/n);
     printf("avg. Turnaround Time = %.2f\n",avgTurnAroundtime);
    printf("avg. Waiting Time = %.2f\n",avgWaitingTime);
    return 0;
}