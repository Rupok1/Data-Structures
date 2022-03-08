//17.02.2020
#include<stdio.h>
#include<stdlib.h>

void insort(int ara[],int n){
    int key,j,i;

    for(i=1;i<n;i++){
        key=ara[i];
        j=i-1;

        while(j>=0 && ara[j]>key){
            ara[j+1]=ara[j];
            j--;
        }
        ara[j+1]=key;
    }

    printf("Array after Insertion Sort:\n");
    for(i=0;i<n;i++) printf("%d ",ara[i]);
    printf("\n");
}

void sesort(int ara[],int n){
    int i,j,temp;

    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(ara[j]<ara[i]){
                temp=ara[j];
                ara[j]=ara[i];
                ara[i]=temp;
            }
        }
    }
    printf("Array after Selection Sort:\n");
    for(i=0;i<n;i++) printf("%d ",ara[i]);
    printf("\n");
}

int main(){
    int n,o;

    while(1){
        printf("Please enter:\n1 - Insertion Sort\n2 - Selection Sort\n0 - Exit\n");
        scanf("%d",&o);

        if(o==0) break;

        if(o==1){
            printf("Please enter array size: ");
            scanf("%d",&n);
            int ara1[n],temp;

            for(int i=0;i<n;i++){
                temp=rand()%100;
                ara1[i]=temp;
            }

            printf("Array before insertion sort:\n");
            for(int i=0;i<n;i++) printf("%d ",ara1[i]);
            printf("\n");
            insort(ara1,n);
        }

        if(o==2){
            printf("Please enter array size: ");
            scanf("%d",&n);
            int ara2[n],temp;

            for(int i=0;i<n;i++){
                temp=rand()%100;
                ara2[i]=temp;
            }

            printf("Array before selection sort:\n");
            for(int i=0;i<n;i++) printf("%d ",ara2[i]);
            printf("\n");
            sesort(ara2,n);
        }
    }
}
