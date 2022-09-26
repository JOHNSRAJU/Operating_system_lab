#include<stdio.h>
struct block_process {
    int no;
    int size;
    int flag;
    int proc;
};struct block_process b[10],p[10],temp;

int main(){
    int i,j,noBlock,noProcess;
    printf("Enter the no. of Memory Blocks :- ");
    scanf("%d",&noBlock);
    printf("Enter the memory block size\n");
    for(i=0;i<noBlock;i++){
        printf("b[%d] :- ",i);
        scanf("%d",&b[i].size);
        b[i].no=i;
        b[i].flag=0;
    }
    printf("Enter the no. of Processes :- ");
    scanf("%d",&noProcess);
    printf("Enter the memory block size\n");
    for(i=0;i<noProcess;i++){
        printf("p[%d] :- ",i);
        scanf("%d",&p[i].size);
        p[i].no=i;
    }
    // Sorting memory block in descending order
    for(i=0;i<noBlock;i++){
        for(j=0;j<noBlock-1-i;j++){
            if(b[j].size<b[j+1].size){
                temp=b[j];
                b[j]=b[j+1];
                b[j+1]=temp;
            }
        }
    }
    for(i=0;i<noProcess;i++){
        for(j=0;j<noBlock;j++){
            if(p[i].size<=b[j].size && b[j].flag==0){
                b[j].proc=i;
                b[j].flag=1;
                break;
            }
            
        }
    }
    printf("Block  Bsize  Proc  Psize\n");
    for(i=0;i<noBlock;i++){
        if(b[i].flag==1){
            printf("B[%d]   %d    P[%d]   %d\n",b[i].no,b[i].size,b[i].proc,p[b[i].proc].size);
        }
        else{
            printf("B[%d]   %d   Not allocated \n",b[i].no,b[i].size);
        }
    }
    return 0;
}