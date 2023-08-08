#include <stdio.h>
#include <string.h>


char* xstrstr(char *string1, char *string2)
{
    int length1=strlen(string1);  //string length 1
    int length2=strlen(string2);  //string length 2

    if( length1 < length2 )
    {
       printf("-------------------------------------------------------------");
       printf("\n\n Sorry program terminated \n");
       printf("The Entered sub string is larger than  main String \n\n\n");
       printf("-------------------------------------------------------------");
       exit(1);
    }

    for(int i=0; i<length1 ;i++)
    {
        if( string1[i] == string2[0] )
        {
            int index=i; //index of the array which is used for verification of the code. //

            for(int j=0; j<length2; j++)
            {

               if(string1[index]==string2[j])
                {
                      if(j==(length2- 1))
                      {
                          string1 = string1 + i;  
                          return string1;
                      }
                }
                else
                {
                    break;
                }
                index++;

            }
        }
        
    }
    return NULL;
}



int main() 
{

    char main_string[100];                       //string 1 //  
    char sub_string[100];                        //string 2 //

    char *starting;                              //Pointer S which will the starting pointer of the array.//

    printf("Enter the Main String( MAX size is 100 ): \n");
    gets(main_string);                           //Taking input from string 1//  

    printf("Enter the sub string (Smaller than main): \n");
    gets(sub_string);                            //Taking input from string 2//
                                                 
    starting=xstrstr(main_string,sub_string);    //calling the function xstrstr//
   
    printf("______________________________________________________________________________________\n");
    printf("|                                      OUTPUT                                         |\n");
    printf("|+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|\n");


    if(starting==NULL)
    {
      printf("The Second string entered is not a sub-string  \n");
    }
    else
    {
      printf("The address of First letter of sub string is %d and the letter is %c \n",starting,*starting);
    }


    printf("______________________________________________________________________________________\n\n");
    return 0;

}