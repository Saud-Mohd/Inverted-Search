#include "inverted_search.h"
char* fname;
void create_database (Flist* f_head, Wlist* head[])
{
    //repeat till the end of the list
    while (f_head)
    {
        read_datafile(f_head, head, f_head->f_name);
        f_head = f_head->link;
    }
}

void read_datafile(Flist* file, Wlist* head[], char* filename)
{
    //store the filename
    fname = filename;
    //open the file in read only mode
    FILE* fptr = fopen(filename, "r");
    // validate
    if (fptr == NULL)
    {
        printf("Error in Openning %s file\n", filename);
    }
    //declare an array to store the word
    char word[WORD_SIZE];
    while (fscanf(fptr, "%s", word) != EOF)
    {
        int flag = 1;
        //extarcting first letter of word justr read from file and finding the position of word in between a - z
        int index = tolower(word[0]) % 97;
        //other than alphabets
        if ( !(index >= 0 && index <= 25) )
            index = 26;
        //check whether words are repeated 
        if (head[index] != NULL)
        {
            Wlist* temp = head[index];
            while (temp)
            {
                if(!(strcmp(temp->word, word)))
                {
                    update_word_count(&temp,filename);
                    flag = 0;
                    break;
                }
                temp = temp->link;
            }
        }
        if (flag == 1)    
            //if words are different   
            insert_at_last (&head[index], word); 
    }
    printf("Successful in creating database for %s file\n", filename);
}

int update_word_count(Wlist** head, char* file_name)
{
    //if word is in same file --> increment word count
    //if word is in different file --> increment file count and add link table node
    Ltable* l_temp = (*head)->Tlink, *prev = NULL;
    while (l_temp)
    {
        if (!strcmp(l_temp->filename, file_name))
        {
            //update word count
            l_temp->word_count++;
            return SUCCESS;
        }
        prev = l_temp;
        l_temp = l_temp->table_link;
    }

    //If we come out of while loop that means the repeated word is not from the already listed files
    //updating file count
    (*head)->file_count++;
    //adding new node in link table
    Ltable* new_link_table_node = malloc(sizeof(Ltable));
    //error check
    if (new_link_table_node == NULL)
        return FAILURE;
    //Updating link table values
    strcpy(new_link_table_node->filename, file_name);    
    new_link_table_node->word_count = 1;
    new_link_table_node->table_link = NULL;
    //establishing the link between prev and 
    prev->table_link = new_link_table_node;
    return SUCCESS;
}
