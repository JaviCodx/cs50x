// Implements a dictionary's functionality

#include <stdbool.h>
#include <strings.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 100000;

// Hash table
node *table[N];

// Counter for words
int COUNT = 0;


// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int key = hash(word);
    
    node *nodepointer = table[key];
    
    while (nodepointer != NULL)
    {
        
        if (strcasecmp(nodepointer->word, word) == 0)
        {
            return true;
        }
        
        nodepointer = nodepointer->next;
        
    }
    
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int hashcode = 0;
    
    for (int i = 0; word[i] != '\0'; i++)
    {
        hashcode += tolower(word[i]);
        
    }
// Has function from David Emily

    return hashcode % N;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *input = fopen(dictionary, "r");
    if (input == NULL)
    {
        return false;
    }
    
    
    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
        
    }
    
    char tmpword[LENGTH + 1];
    
    while (fscanf(input, "%s\n", tmpword) != EOF)
    {
        
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }
        
        strcpy(n->word, tmpword);
        
        int key = hash(tmpword);
        
        if (table[key] == NULL)
        {
            table[key] = n;
            n->next = NULL;
        }
        else
        {
            n->next = table[key];
            table[key] = n;
        }
        
        COUNT++;
    }
    
    

    
    fclose(input);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    
    return COUNT;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *nodepointer = table[i];
        
        while (nodepointer != NULL)
        {
            node *tmpnode = nodepointer;
            nodepointer = nodepointer->next;
            free(tmpnode);
        }
        table[i] = NULL;
    }
    return true;
}
