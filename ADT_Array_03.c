#include<stdio.h>
#include<stdlib.h>

//Structure is used to create cutsom data type.
struct myArray
{
    int total_size/*memory to be reserved*/,used_size/*memory to be used*/;
    int * ptr; //ptr will point to the 1st element 
};

void createArray(struct myArray * a , int tSize , int uSize){
    //defrencing the pointer a 
    // (*a).total_size = tSize;
    // (*a).used_size = uSize;
    // (*a).ptr = (int *)malloc(tSize*sizeof(int));     //General Syntax --> Reserving memory in the heap 

    //_->More easy way.
    a->total_size = tSize;
    a->used_size = uSize;
    //Malloc is used to store the moemory in the heap so that it can be stored (when emory gets stored in stack it will be destroyed after use)
    a->ptr = (int *)malloc(tSize*sizeof(int));     //General Syntax --> Reserving memory in the heap 
}

void show(struct myArray * a){
    for (int i = 0; i < a->used_size; i++)
    {
        printf("%d\n" ,a->ptr[i] );
    }
    
}

void setVal(struct myArray *a){
    for (int i = 0; i < a->used_size; i++)
    {
        printf("Enter elements %d : " , i);
        int n;
        scanf("%d" ,&n );
        a->ptr[i] = n;
    }
}

int main(){
    struct myArray x;  //creating instance of the structure
    createArray(&x , 10 , 2);
    setVal(&x);
    show(&x);   
    return 0;
}