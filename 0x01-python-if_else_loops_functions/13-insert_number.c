#include "lists.h"

/**
 * insert_mode -inserts a number into a sorted singly linked list
 * @head: address of the address of the first node in the list
 * @number: number value of th new mode
 *
 * Return: address of the new node, otherwise NULL
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new, *current, *prev;

	if (head == NULL)
		return (NULL);

	/* create new node */
	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = number;
	new->next = NULL;

	/* if the list is empty */
	if (*head == NULL)
	{
	    *head = new;
	    return (new);
	}

        /* add new node at the beginning of the list */
	if (*head == NULL || (*head)->n > number)
	{
	   new->next = *head;
	   *head = new;
	   return (new);   
	}

	/* add new node to middle of the list */
       prev = *head;
       current = *head;       
       while (current)
       {
           if (current->n > number)
		   break;
	   {
	      prev->next = new;
	      new->next = current;
	      return (new);
	   }   
	   prev = current;
	   current = current->next;
       }	       

       /* add new node at the end of the list */
       prev->next = new;
       new->next = current;
       
       return (new);
}			
