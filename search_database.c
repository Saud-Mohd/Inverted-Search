#include "inverted_search.h"
void search_database(Wlist* head, char* word)
{
    while (head != NULL)
    {
        if (!(strcmp(head->word,word)))
        {
            //print
            printf("The word %s is present in %d File/s\n", head->word, head->file_count);
            Ltable* temp = head->Tlink;
            while (temp)
            {
                printf("File: %s\t%d times\n",temp->filename, temp->word_count);
                temp = temp->table_link;
            }
            return;
        }
        head = head->link;
    }
    //if we come out of while loop that means word not present in database
    printf("Error: Word %s not present in database\n", word);
}