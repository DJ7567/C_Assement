// Online C compiler to run C program online

#include <stdio.h>

int main() {
    unsigned int room_no=4,temp,input,exit,flag=1;    
    int data[] = {273,548,786,1096};    //2//4////6//8
    

 while(1)
 {
    flag =1;    // flag for invaild room number;
    printf("***************************************************\n");
    printf("please enter the room number to get details\n");     // Taking the input from the user
    scanf("%d",&room_no);

    for(int i=0;i<4;i++)
    {
        if (room_no == (data[i]>>7))                           // binary value of 273 is 100010001 after 
        {                                                      // after operation is 10 means decimal 2

            printf("Room no exists with data: %d\n",data[i]);
            input=data[i];
            printf("The information of the student is given Here\n");
            printf("*************************************************\n\n");
            flag =0;
        }

       
    }

    if(flag)
    {
    
            printf("The No room in the hostel with this number try agian with vaild number \n");
             printf("************************************************************************\n\n");
            input =0;
    }

    
    // Write C code here
    if((0b0000001)&input)                            // check if the studen is from 1st year
    {
        printf("This a first year student \n");
    }
    else if((0b00000010)&input)                      // check if the studen is from 2th year
    {
        printf("This a second year student \n");
    }
    else if((0b00000100)&input)                     // check if the studen is from 3th year
    {
        printf("This a third year student \n");
    }
    else if((0b00001000)&input)                     // check if the studen is from 4th year
    {
        printf("This a fourth year student \n");
    }


// which fild the student belong 

    if((0b00010000)&input)
    {
        printf("Mechanical Engineering student\n");    //Mechanical Engineering student
    }
    else if((0b00100000)&input)
    {
        printf("Chemical Engineering student\n");     //Chemical Engineering student
    }
    else if((0b01000000)&input)
    {
        printf("Mechanical Engineering student\n");   //Mechanical Engineering student
    }
    else if((0b10000000)&input)
    {
        printf("IT Engineering student\n");           //IT Engineering student
    }

    printf("Do want to exit than press : 1 or any other number to continue \n");     // Taking the input from the user
    scanf("%d",&exit);

    if(exit==1)
    {
        return 0;
    }

 }
   
}