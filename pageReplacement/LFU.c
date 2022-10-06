#include<stdio.h>
int main(){
    int n,f,i,j,k,flag,pag,count,pages[30],result[10],freq[10],min=0,flag2;
    printf("Enter no. of pages :- ");
    scanf("%d",&n);
    printf("Enter no of frames :- ");
    scanf("%d",&f);
    printf("Enter the pages :- \n");
    for(i=0;i<n;i++){
        scanf("%d",&pages[i]);
    }
    count=0;
    pag=0;
    for(i=0;i<f;i++){
        result[i]=pages[i];
        freq[i]=1;
        count++;
    }
    printf("\nREF \t\tPages\n");
    for(i=0;i<f;i++){
        printf("%d\t\t",pages[i]);
        for(j=0;j<=i;j++){
            printf("%d   ",result[j]);                 
        }
        printf("\n");
    }
    for(i=f;i<n;i++){
        flag=0;
        for(j=0;j<f;j++){
            if(result[j]==pages[i]){
                flag=1;
                freq[j]++;
                
                break;
            }
        }
        if(flag==0){
            count++;
            min=pag;
            k=pag;
            for(j=0;j<f;j++){
                if(freq[min]>freq[k]){
                    min=k;
                    pag=(pag+1)%f;
                }
                k=(k+1)%f;
            }
            result[min]=pages[i];
            freq[min]=1;
            pag=(pag+1)%f;
        }
        printf("%d\t\t",pages[i]);
        for(j=0;j<f;j++){           
            printf("%d   ",result[j]);            
        }
        printf("\n");
    }
    printf("\nPage fault = %d\n",count);
    return 0;
}