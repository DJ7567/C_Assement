#include <stdio.h>
#include <string.h>


//Function for reversing of strings and storing into a array and printing on the output of the terminal.
void reverse(char *string, char *ptr)
{
    int Length ,count;              
    Length = strlen(ptr);           //taking length of the string.
    count = Length;                 //Assiging the downcounter value equal to the length of the string.

    string[count] = '\0';
    // loop for storing the reverse of the into a charater array.

    for(int index=0; index<Length; index++)
    {
                                    //hello will be converted into olleh
        count--;                    //decrement count example 4 3 2 1 0
        string[count]=ptr[index];   //values  (count , index) (4,0) (3,1) (2,2) (1,3) (0,4)   
                                          
    }

    printf(" %s \n", string);       //printing the string   
}


//Printing the array of the strings 
void print_char_array(char **array)
{
   printf("\n Printing the original Strings \n\n"); // printing the string  

   for(int count=0;count<3;count++)
   {
        printf(" %s \n", *array);                   // printing thr string one by one 
        array++;                                    // increamenting the pointer 
   }
}

void main()
{

    // The array of the Strings with all the given strings.
    char *array_string[] = { "To err is human..", "But to really mess things up..", "One needs to know C!!"};

    // 2D array to store the variable.
    char Store[3][100] ,*ptr;

    print_char_array(array_string);                       // printing the array

    printf("\n Output after reversing the string: \n\n"); 
    for(int index=0 ; index<3 ;index++)
    { 
        reverse(Store[index],array_string[index]);        // reversing the string
    }

    printf("\n"); 
}