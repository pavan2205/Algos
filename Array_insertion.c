#include<stdio.h>
void display(int arr[],int n){
    //code for traversal
    for (int i = 0; i < n; i++){
       printf("%d ",arr[i]);
    }
    printf("\n");
}
int indInsertion(int arr[],int size,int capacity,int element,int index ){
    //code for insertion
    if(size>= capacity){
        return -1;
    }
    for (int i = size-1; i >= index; i--){
       arr[i+1]=arr[i];
    }
    arr[index]=element;
    return 1;
}
int main(){
    int arr[100]={1,5,9,78,33,99};
    int size=6,capacity=100,element=88,index=3;
    display(arr,size);
    int p=indInsertion(arr,size,capacity,element,index);
    //printf("%d\n",p);
    size+=1;
    if(p==1){
        display(arr,size);
    }
    return 0;
}