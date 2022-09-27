#include<stdio.h>
int main(){
    int n,f,i,j,k,flag,pag,count,pages[30],result[10],flagP[10];
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
            flagP[j]=0;
            if(result[j]==pages[i]){
                flag=1;
                break;
            }
        }
        if(flag==0){
            for(j=i;j>i-f;j--){
                for(k=0;k<f;k++){
                    if(pages[j]==result[k]){
                        flagP[k]=1;
                        break;
                    }
                }
            }
            for(j=0;j<f;j++){
                if(flagP[j]==0){
                    result[j]=pages[i];   
                    count++;
                    break;       
                }   
            }
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