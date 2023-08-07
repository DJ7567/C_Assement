#include <stdio.h>
#include <string.h>

char* xstrstr(char *string1, char *string2)
{
    int lenght1=strlen(string1);  //string lenght 1
    int lenght2=strlen(string2);  //string lenght 2
    
    for(int i=0; i<lenght1 ;i++)
    {
        if( string1[i] == string2[0] )
        {
            int index=i; // index of the array which is used for verification of the code. //

            for(int j=0; j<lenght2; j++)
            {

                if(string1[index]==string2[j])
                {

                      if(j==(lenght2-1))
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
    
}



int main() 
{
    char str[100];          // string 1 //  
    char str1[100];         // string 2 //

    char *s;                // Pointer S which will the starting pointer of the array.//

    gets(str);              // Taking input from string 1//  
    gets(str1);             // Taking input from string 2//

    s=xstrstr(str,str1);    // calling the function xstrstr//

    printf("the address of the letter is %d and the letter is %c \n", s, *s);

    return 0;

}