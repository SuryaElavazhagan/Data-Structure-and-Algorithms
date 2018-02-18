#include<stdio.h>
merge_sort(int array[],int i,int j);
merge(int array[],,int i,int j);
void main()
{
    int array[100], limit, inc;
    printf("Enter the limit for the array:");
    scanf("%d",&limit);
    printf("\nEnter the array elements:");
    for(inc = 0; inc < limit; inc++)
        scanf("%d",array[inc]);
    merge_sort(array, 0, limit - 1);
    printf("\nThe Sorted numbers are:");
    /*
        * PRINT THE SORTED ARRAY :)
    */
    for(inc = 0; inc < limit; inc++)
        printf("%d ,",array[inc]);
}


void merge(array,i,j)
int array[],i,j;
{
    /*
        * INITIALIZE VARIABLES FOR TEMPORARY ARRAY
    */
    int start = i;
    int index = i;
    int temp[100];
    int mid = (i + j)/2;
    int k = mid + 1;
    
    // ACTUAL LOGIC GOES HERE!

    while(i<=mid && k<=j)
    {
        /*
            * COMPARE ELEMENTS AND COPY THE LEAST TO TEMPORARY ARRAY
        */
        if(array[i] <= array[k])
            temp[index++] = array[i++];
        else
            temp[index++] = array[k++];
        
        /*
            * COPY THE REMAINING ELEMENTS TO TEMPORARY ARRAY
        */
        if(i > mid)
            for(;k <= j;)
                temp[index++] = array[k++];
        else if(k > j)
            for(;i <= mid;)
                temp[index++] = array[k++];
        
        /*
            NOW COPY BACK ALL THE ELEMENTS IN TEMPORARY ARRAY 
        */
        for(index = start; index < j; index++)
            array[index] = temp[index];
    }
}

void merge_sort(array,i,j)
int array[],i,j;
{
    /*
        *COMPUTE MID VALUE
    */
    int mid = (i + j) / 2;
    if(i >= j)
        return;
    else
    {
        /*
            * APPLY MERGE SORT FOR LEFT ARRAY
        */
        merge_sort(array, i, mid);
        /*
            * APPLY MERGE SORT FOR RIGHT ARRAY
        */
        merge_sort(array, mid+1, j);
        /*
            * MERGE BOTH THE LEFT SORTED AND RIGHT SORTED ARRAY
        */
        merge(array,i,j);
    }
}
