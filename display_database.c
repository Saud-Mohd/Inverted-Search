#include "inverted_search.h"
void display_database (Wlist* head[])
{
    printf("[index] [word] filecount file/s : file_name word_count\n");
    printf("\n--------------------------------------------------\n");
    for (int index = 0 ; index < 27; index++)
    {
        Wlist* temp = head[index];
        while (temp != NULL)
        {
            printf("[%d] [%s] %d files:\t", index, temp->word, temp->file_count);
            Ltable* l_temp = temp->Tlink;
            while (l_temp != NULL)
            {
                printf("%s %d\t",l_temp->filename, l_temp->word_count);
                l_temp = l_temp->table_link;
            }
            printf("\n");
            //moving temp to next node
            temp = temp->link;
        }
    }
    printf("\n--------------------------------------------------\n");
}