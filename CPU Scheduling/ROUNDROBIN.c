#include<stdio.h>
struct process{
    int no;
    int burstTime;
    int burstCopy;
    int completionTime;
    int turnaroundTime;
    int waitingTime;
};struct process p[10],temp;
int main(){
    int n,i,j,com,quanta,flag;
    float avgWaitingTime=0,avgTurnAroundtime=0,totalTurn=0,totalWait=0,totalBurst=0;
    printf("Enter no. of process :-  ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter Burst Time of p[%d] :- ",i);
        scanf("%d",&p[i].burstTime);
        p[i].burstCopy=p[i].burstTime;
        totalBurst=totalBurst+p[i].burstTime;
    }
    printf("Enter the quanta time");
    scanf("%d",&quanta);
    com=0;
    while(com<totalBurst){
        flag=1;
        for(i=0;i<n;i++){
            if(p[i].burstTime>0){
                flag=0;
                if(p[i].burstTime<=quanta){
                    com=com+p[i].burstTime;
                    p[i].burstTime=0;
                    p[i].turnaroundTime=com;
                    p[i].waitingTime=p[i].turnaroundTime-p[i].burstCopy;
                }
                else{
                    com=com+quanta;
                    p[i].burstTime=p[i].burstTime-quanta;
                }
            }
        }
    };

    for(i=0;i<n;i++){
        totalTurn=totalTurn+p[i].turnaroundTime;
        totalWait=totalWait+p[i].waitingTime;
    }
    printf("\nPro  bur com turn wait \n");
    for(i=0;i<n;i++){
        printf("p[%d]  %d    %d     %d     %d  \n",p[i].no,p[i].burstCopy,p[i].completionTime,p[i].turnaroundTime,p[i].waitingTime);
    }
    avgTurnAroundtime=(totalTurn/n);
    avgWaitingTime=(totalWait/n);
     printf("avg. Turnaround Time = %.2f\n",avgTurnAroundtime);
    printf("avg. Waiting Time = %.2f\n",avgWaitingTime);
    return 0;
}
