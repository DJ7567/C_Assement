#include <stdio.h>
 
 // functionn to arrange the elements in accessding and desending order

void Sort(int sort, int size) 
{
    int arr[size];         // array to store the data
    int i, j, temp;
    
    for (int i = 0; i < size; i++)          // taking inputs from the user 
    {
        printf("Enter the elements \n");
        scanf("%d", &arr[i]);               // scaning the inputs 
    }
    
    printf("value inside the original array: ");

    for (int i = 0; i < size; i++)          // printing the values taken from the user 
    {
      printf("%d ", arr[i]);                
    }
    printf("\n");
    
   switch(sort)
   { 
     case 1:                                // Arranging the data in accending form
            for (i = 0; i < size - 1; i++) 
            {
                for (j = 0; j < size - i - 1; j++) 
                {
                    if (arr[j] > arr[j + 1]) 
                    {
                        temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
            }
    break;
    
    
    case 2:
        for (i = 0; i < size - 1; i++)                    // Arranging the data in decending form
        {
            for (j = 0; j < size - i - 1; j++) 
            {
                if (arr[j] < arr[j + 1]) 
                {
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    break;
   }
   
    printf("\nSorted array in order: ");
    for (int i = 0; i < size; i++) 
    {
        printf("%d ", arr[i]);
    }
   printf("\n\n");
}


int main() 
{
  int exit;
  
  while(1)
  {
    int size,sort;
    
    printf("Enter 1 for accending, 2  desending and  3 for exit: ");
    scanf("%d",&sort);

    if(((sort==1)||(sort==2)||(sort==3)))
    {

        if(sort==3)
        {
            printf("exiting the program");
            return 0;
        }

        printf(" Enter the size: \n");
        scanf("%d",&size);
        Sort(sort,size);

    }
    else
    {
        printf(" Invaild input entered \n"); 
    }
    
  }
    return 0;

}
