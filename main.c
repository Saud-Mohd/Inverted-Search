#include "inverted_search.h"

int main(int argc, char* argv[])
{
    system("clear");
    //validating Command Line Arguments
    //if only 1 CLA passed then throw an error
    if (argc == 1)
    {
        printf("Enter valid number of Command Line Arguments\n./Slist.exe f1.txt f2.txt f3.txt\n");
        return 0;
    }
    //Declare a head pointer for file linked list
    Flist* f_head = NULL;
    file_validation_n_file_list(&f_head, argv);
    if (f_head == NULL)
    {
        printf("No files are available in the file list\nHence the process is terminated\n");
        return 1;
    }
    //Menu pop up for the user
    int choice;
    char option;
    Wlist* head[27] = {NULL};
    do
    {
        printf("1. Create Database\n2. Display Database\n3. Update Database\n4. Search\n5. Save Database\nEnter your Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create_database(f_head, head);
            break;
        case 2:
                display_database(head);
                break;

        default:
            break;
        }

        printf("Do you want to continue (y/n): ");
        getchar();
        scanf("%c",&option);
    } while (option == 'Y'|| option == 'y');
    
}