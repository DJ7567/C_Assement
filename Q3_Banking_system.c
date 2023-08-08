#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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


// Function to perform the transection on the Given Account
void balance(customer *current, trans data)
{
    if(data.trans_type == 'D')                       // Press the D to add (deposite) the amount in the account
    {                                                  
        printf("Enter Amount : ");                   
        scanf("%f", &data.amount);
        current->balance += data.amount;             // adding the amount in the account
    }
    else if(data.trans_type == 'W')                  // Press the W to Withdraw the money from the account
    {                                                
        printf("Enter Amount : ");                   
        scanf("%f", &data.amount);
        float new_balance = current->balance - data.amount;  
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
    else if(data.trans_type == 'P')                   // Print the account details.
    {
        printf("The details of the Account :\n");
        printdetails(current); 
        return;
    }
    else
    {
        printf("Invalid transaction type. \n");
        return;
    }

    printf("Transaction successful.\n");
    printdetails(current);  
    return;                                           // if the Transection is sucessfull than print the details       
}


//Read the data from the Customer File
customer *readCustomerData()
{
    FILE *file = fopen("CUSTOMER.csv", "r");          //opening the customer.csv file 
    if (file == NULL)                                
    {
        printf("Error opening CUSTOMER.csv file\n");  //Customer.csv
        return NULL;
    }

    customer *head = NULL;                            //Head pointer for the starting of the linked list
    customer *current = NULL;                         //current pointer for the starting of the linked list

    while (!feof(file))
    {
        customer *new_customer = (customer *)malloc(sizeof(customer));
        if (fscanf( file,"%d,%s,%d\n", &new_customer->accno, new_customer->name, &new_customer->balance) != 1)
        {
            free(new_customer);
            break;
        }

        // char name[100];
        // fscanf(file, "%s", name);
        // new_customer->name = strdup(name);
        // fscanf(file, "%f", &new_customer->balance);
        new_customer->next =NULL;
        new_customer->prev =NULL;

        if (current != NULL)
        {
            current->next = new_customer;
            new_customer->prev = current;  
            current = new_customer;
            printf("the next element is loaded \n");
        }

        if (head == NULL)
        {
            head = new_customer;
            current = head;
            printf("the head loaded \n");
        }
    }
    fclose(file);
    return head;
}

customer *createAccount(int accno, float amount)
{

    customer *new_customer = malloc(sizeof(customer));
    new_customer->accno = accno;
    printf("account %d \n ", accno);
    new_customer->name = NULL;
    new_customer->balance = amount;
    new_customer->next = NULL;
    new_customer->prev = NULL;

    char name[100];
    printf("Enter Account Holder's Name : ");
    scanf("%s", name);

    new_customer->name = strdup(name);
    printf("account %s \n ", name);
    return new_customer;

}

void writeCustomerData(customer *head)
{

    FILE *file = fopen("CUSTOMER.csv", "w+");
    if (file == NULL)
    {
        printf("Error opening CUSTOMER.DAT file for writing.\n");
        return;
    }

    customer *current = head;

    do
    {
        fprintf(file, "%d %s %.2f\n", current->accno, current->name, current->balance);
        current = current->next;
    } 
    while (current != NULL);

    fclose(file);

}


int main()
{ 
    int flag=1;
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

    printf("Enter Account Number : ");
    scanf("%d", &data.accno);
    printf("Enter Trans Type (D/W) : ");
    scanf("%s", &data.trans_type);

    // printf("Enter Amount : ");
    // scanf("%f",&data.amount);

    customer *current = head;
    customer *new;
    //current = current->next;

     while(ptr != NULL)
    {
        printf("the liked data is %d \n", ptr->accno);
        ptr=ptr->next;
    }

    while (current != NULL)
    {
        printf("%d\n", current->accno);
        if (data.accno == current->accno)
        {
            balance(current, data);
            flag = 0;
            break;
        }

        if(current->next)
        {
            new=current;
        }

        current = current->next;
    }

    if (flag)
    {
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
                printf("hello \n");
                customer *new_customer;
                new_customer = createAccount(data.accno, data.amount);
                printf("New account created.\n");
                new_customer->prev = current;
                new->next =new_customer;
            }
            
    }

    printf("end \n");
    writeCustomerData(head);
    return 0;
}