#include<stdio.h>
//coding linear search
int linearSearch(int arr[],int size,int element){
    for (int i = 0; i < size; i++){
        if(arr[i]==element){
            return i;
            break;
        }
    }
    return -1;
    
}
//coding binarysearch
int binarySearch(int arr[],int element,int low,int high){
    int mid;
    if(low<=high){
        mid=(low+high)/2;
    if(arr[mid]==element){
            return mid;
    }
        if(arr[mid]<element){
            return binarySearch(arr,element,mid+1,high);
            //low=mid+1;
        }
            return binarySearch(arr,element,low,mid-1);
           // high=mid-1;
    }
    return -1;
}
int main(){
    int arr[]={10,20,30,40,44,50,88},element1=30,element2=44;
    int size=sizeof(arr)/sizeof(int);
    int p=linearSearch(arr,7,element1);
    printf("%d",p);
    int low=0;
    int high=size-1;
    int q=binarySearch(arr,element2,low,high);
    printf("\n%d",q);
    return 0;
}