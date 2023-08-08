#include <stdio.h>
#include <string.h>


//Function for reversing of strings and storing into a array and printing on the output of the terminal.
void reverse(char *string, char *ptr)
{
    int Length ,count;              
    Length = strlen(ptr);           //taking length of the string.
    count = Length;                 //Assiging the downcounter value equal to the length of the string.

    
    // loop for storing the reverse of the into a charater array.
    for(int index=0; index<Length; index++)
    {
                                    //hello will be converted into olleh
        count--;                    // decrement count example 4 3 2 1 0
        string[count]=ptr[index];   // values  (count , index) (4,0) (3,1) (2,2) (1,3) (0,4)   
                                          
    }

    printf(" %s \n", string);       // printing the string   
    
}

void main()
{

    // The array of the Strings with all the given strings.
    char *array_string[] = { "To err is human..", "But to really mess things up..", "One needs to know C!!"};

    // 2D array to store the variable.
    char Store[3][100] ,*ptr;

    printf("\n\n Output after reversing the string: \n\n"); 
    for(int i=0 ; i<3 ;i++)
    { 
        reverse(Store[i],array_string[i]);  // reversing the string
    }

    printf("\n");
}