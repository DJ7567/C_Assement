#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Exit = 0;

//stucture for the account number 
typedef struct customer
{   

    int accno;                  // account number
    char *name;                 // Name of the account holder
    float balance;              // Balance of the account holder
    struct customer *next;      // pointer to the next account
    struct customer *prev;      // pointer to the prev account

} customer;

typedef struct trans
{

    int accno;                  // account number
    char trans_type;            // transection type example withdraw,
    float amount;               // Balance of the account holder

} trans;   

//A Function to print the account details of the person
void printdetails(customer *current)
{
    printf("Account Number: %d\n", current->accno);         
    printf("Name: %s\n", current->name);                   
    printf("Balance: %.2f\n", current->balance);           
}


// function if the value entered is vaild or not
int is_vaild(int data)
{
    if(data>0)
    {
        printf("you Enter a vaild value\n");
        return 1;
    }
    else
    {
        printf("you Enter a Invaild value\n");
        return 0;
    }
}

// Function to perform the transection on the Given Account
int balance(customer *current, trans data)
{
    if(data.trans_type == 'D')                       // Press the D to add (deposite) the amount in the account
    {                                                  
        printf("Enter Amount : ");                   
        scanf("%f", &data.amount);
        if(!(is_vaild(data.amount)))
        {
           return 0;
        }
        current->balance += data.amount;             // adding the amount in the account
    }

    else if(data.trans_type == 'W')                  // Press the W to Withdraw the money from the account
    {                                                
        printf("Enter Amount : ");                   
        scanf("%f", &data.amount);
        float new_balance = current->balance - data.amount; 
        if(!(is_vaild(data.amount)))
        {
           return 0;
        } 
        if (new_balance >= 100)                      // if the balence is greater than 100 than update the account
        {
            current->balance = new_balance;
        }
        else
        {
            printf("Insufficient balance. Minimum balance Rs 100 Required.\n");
            return;                               
        }
    }
     else if(data.trans_type == 'E')                   // Print the account details.
    {
       return 1;
    }
    else if(data.trans_type == 'P')                   // Print the account details.
    {
        printf("The details of the Account :\n");     
        printdetails(current);                        // Print the account details.
        return 0;
    }
    else
    {
        printf("Invalid transaction type. \n");       
        return 0;
    }

    printf("Transaction successful.\n");
    printdetails(current);  
    return 0;                                           // if the Transection is sucessfull than print the details     

}


//Read the data from the Customer File
customer *readCustomerData()
{
    FILE *file = fopen("CUSTOMER.dat", "r");           // CUSTOMER.dat file containing the data
    if (file == NULL)
    {
        printf("Error opening CUSTOMER.DAT file.\n");  // error while opeining the file
        return NULL;
    }

    customer *head = NULL;
    customer *current = NULL;

    while (!feof(file))                           // loops run until the END of the file
    {
        customer *new_customer = (customer *)malloc(sizeof(customer));    // dynamic memory allocation 
        if (fscanf(file, "%d", &new_customer->accno) != 1)                // read account number from the file
        {
            free(new_customer);
            break;
        }

        char name[100];
        fscanf(file, "%s", name);                            // Reading the account holder name
        new_customer->name = strdup(name);
        fscanf(file, "%f", &new_customer->balance);          // Reading the account holder balance
        new_customer->next =NULL;
        new_customer->prev =NULL;

        if (current != NULL)                                 //linking the block of memory to the list
        {
            current->next = new_customer;                    //prev memory block pointing to new block 
            new_customer->prev = current;                    //new  memory block pointing to prev memory block
            current = new_customer;                          //cuurent memory block

            //printf("the next element is loaded \n");         
        }

        if (head == NULL)
        {
            head = new_customer;                             // first memory block of the linked list
            current = head;
            printf("the head loaded \n");
        }
    }
    fclose(file);                                            //closing the file
    return head;                                             //returing the head
}


//creating a new account for the new account holder 
customer *createAccount(int accno, float amount)
{

    customer *new_customer = malloc(sizeof(customer));      //memory allocation      
    new_customer->accno = accno;                           
                          //printing the new account number
    new_customer->name = NULL;
    new_customer->balance = amount;                         //add the balance
    new_customer->next = NULL;
    new_customer->prev = NULL;

    char name[100];
    printf("Enter Account Holder's Name : ");               // taking the name of new account holder
    scanf("%s", name);

    new_customer->name = strdup(name);
    printf("Account NO is : %d \n", accno); 
    //printf("Account Holder Name %s \n ", name);                        
    return new_customer;                                    // returing the address of the memory block of structure pointer
}

// This function write the data into file system//
void writeCustomerData(customer *head)
{

    FILE *file = fopen("CUSTOMER.dat", "w+");               // opening the file 
    if (file == NULL)                                          
    {
        printf("Error opening CUSTOMER.DAT file for writing.\n"); // error in opening the file 
        return;
    }
    customer *current = head;

    do
    {
        fprintf(file, "%d %s %.2f\n", current->accno, current->name, current->balance);  // writing the data into the file 
        current = current->next;                                                         // updating the pointer 
    } 
    while (current != NULL);

    fclose(file);                                           // closing the file

}


int main()
{ 
    int flag=1, Exit = 0; 
    customer *head = readCustomerData();
    customer *ptr = head;
                                      //display(head);
                                      //printf("%s\n", ptr->next);

    if(head == NULL)
    {        
        printf("No customer data found. Please create 'CUSTOMER.DAT' File.\n");  
        return 0;
    }
    trans data;

    while(1)
    {
        printf("********************************************\n"); 
        printf("Enter Account Number : ");
        scanf("%d", &data.accno);

        // printf("Enter Amount : ");
        // scanf("%f",&data.amount);

        customer *current = head;
        customer *new;
        //current = current->next;
         ptr = head;
         while(ptr != NULL)
         {
            if(data.accno == ptr->accno)
            {
               flag=0;
            }
            if(ptr->next==NULL)
            {
                new=ptr;
            }
        //     printf("the liked data is %d \n", ptr->accno);
            ptr=ptr->next;
         }

        if (flag)
        {
                printf("\n\n********************************************\n"); 
                printf("Account not found. Creating a new account.\n");
                printf("Enter initial deposit amount: ");
                scanf("%f", &data.amount);

                if (data.amount < 100)
                {
                    printf("Minimum Rs.100 Balance Required.\n ");
                    return 0;
                }
                else
                {
                    customer *new_customer;
                    new_customer = createAccount(data.accno, data.amount);
                    printf("New account created.\n");
                    new_customer->prev = new;
                    new->next = new_customer;
                    writeCustomerData(head);
                }    
                printf("********************************************\n");       
        }

        printf("Enter Trans Type (D/W/P/E) : ");
        scanf("%s", &data.trans_type);
        printf("********************************************\n"); 

        while (current != NULL)
        {
           // printf("%d\n", current->accno);
            if (data.accno == current->accno)
            {
                Exit=balance(current, data);
                break;
            }
            
            current = current->next;
        }
        if(Exit==1)
        {
            break;
        }
        printf("\n");

    }

    writeCustomerData(head);
    printf("The free the memory space used by the linked list \n");
    customer *temp;      
    ptr = head; 
    while( temp != NULL)
    {  
        temp = ptr->next;
        printf("The memory elements is %d free\n",ptr);
        free(ptr);
        ptr=temp;
    }
    printf(" \n\n program is exited \n\n");
    return 0;
}