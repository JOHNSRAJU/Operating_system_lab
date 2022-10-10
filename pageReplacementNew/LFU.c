#include<stdio.h>
int main(){
    int n,f,i,j,k,min,flag,pag=0,pageFault,pages[30],result[10],freq[10];
    printf("Enter no. of pages :- ");
    scanf("%d",&n);
    printf("Enter no of frames :- ");
    scanf("%d",&f);
    printf("Enter the pages :- \n");
    for(i=0;i<n;i++){
        scanf("%d",&pages[i]);
    }
    for(i=0;i<f;i++){
        result[i]=-1;
        freq[i]=0;
    }
    printf("REF \t\tPages\n");
    pageFault=0;
    pag=0;
    for(i=0;i<n;i++){
       flag=0;
        for(j=0;j<f;j++){
            if(result[j]==pages[i]){
                flag=1;
                freq[j]++;
                break;
            }
        }
        if(flag==0){
            k=pag;
            min=pag;
            for(j=0;j<f;j++){
                if(freq[k]<freq[min]){
                    min=k;
                    pag=(pag+1)%f;
                }
                k=(k+1)%f;
            }
            result[min]=pages[i];
            freq[min]=1; 
            pag=(pag+1)%f;    
            pageFault++; 
            printf("%d\t\t",pages[i]);      
        }
        else{
            printf("%d *\t\t",pages[i]);
        }
        for(j=0;j<f;j++){
            if(result[j]!=-1){
                printf("%d   ",result[j]);
            }            
        }
        printf("\n");
    }
    
    printf("\nPage fault = %d\n",pageFault);
    return 0;
}