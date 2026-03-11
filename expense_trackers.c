#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Expense
{
    char date[20];
    char category[20];
    float amount;
    char note[50];
};

float budget = 0;

void addExpense()
{
    struct Expense e;
    FILE *fp;

    fp = fopen("expense.txt", "a");

    if(fp == NULL)
    {
        printf("File error\n");
        return;
    }

    printf("Enter Date (DD/MM/YYYY): ");
    scanf("%s", e.date);

    printf("Enter Category: ");
    scanf("%s", e.category);

    printf("Enter Amount: ");
    scanf("%f", &e.amount);

    printf("Enter Note: ");
    scanf("%s", e.note);

    fprintf(fp,"%s %s %.2f %s\n", e.date, e.category, e.amount, e.note);

    fclose(fp);

    printf("Expense Added Successfully!\n");
}

void viewExpenses()
{
    struct Expense e;
    FILE *fp;

    fp = fopen("expense.txt","r");

    if(fp == NULL)
    {
        printf("No expense records found.\n");
        return;
    }

    printf("\nDate\tCategory\tAmount\tNote\n");

    while(fscanf(fp,"%s %s %f %s",e.date,e.category,&e.amount,e.note)!=EOF)
    {
        printf("%s\t%s\t%.2f\t%s\n",e.date,e.category,e.amount,e.note);
    }

    fclose(fp);
}

void totalExpense()
{
    struct Expense e;
    float total = 0;

    FILE *fp;

    fp = fopen("expense.txt","r");

    if(fp == NULL)
    {
        printf("No expense records found.\n");
        return;
    }

    while(fscanf(fp,"%s %s %f %s",e.date,e.category,&e.amount,e.note)!=EOF)
    {
        total += e.amount;
    }

    fclose(fp);

    printf("Total Expense = %.2f\n", total);

    if(budget > 0 && total > budget)
    {
        printf("Warning! Budget exceeded!\n");
    }
}

void searchCategory()
{
    struct Expense e;
    char search[20];
    int found = 0;

    FILE *fp;

    fp = fopen("expense.txt","r");

    if(fp == NULL)
    {
        printf("No records found.\n");
        return;
    }

    printf("Enter Category to search: ");
    scanf("%s",search);

    while(fscanf(fp,"%s %s %f %s",e.date,e.category,&e.amount,e.note)!=EOF)
    {
        if(strcmp(search,e.category)==0)
        {
            printf("%s %s %.2f %s\n",e.date,e.category,e.amount,e.note);
            found = 1;
        }
    }

    if(found == 0)
    {
        printf("No matching category found.\n");
    }

    fclose(fp);
}

void setBudget()
{
    printf("Enter Monthly Budget: ");
    scanf("%f",&budget);

    printf("Budget set successfully!\n");
}

int main()
{
    int choice;

    while(1)
    {
        printf("\n====== Expense Tracker ======\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Total Expense\n");
        printf("4. Search by Category\n");
        printf("5. Set Budget\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                addExpense();
                break;

            case 2:
                viewExpenses();
                break;

            case 3:
                totalExpense();
                break;

            case 4:
                searchCategory();
                break;

            case 5:
                setBudget();
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}