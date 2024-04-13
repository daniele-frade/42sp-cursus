/*
Assignment name  : ft_list_remove_if
Expected files   : ft_list_remove_if.c
Allowed functions: free
--------------------------------------------------------------------------------

Write a function called ft_list_remove_if that removes from the
passed list any element the data of which is "equal" to the reference data.

It will be declared as follows :

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());

cmp takes two void* and returns 0 when both parameters are equal.

You have to use the ft_list.h file, which will contain:

$>cat ft_list.h
typedef struct      s_list
{
	struct s_list   *next;
	void            *data;
}                   t_list;
$>
*/

#include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)()) 
{
	t_list	*aux;
	t_list	*temp;

	aux = *begin_list;
	while (aux != NULL)
	{
		if (cmp(aux->data, data_ref) == 0)
		{
			if (aux == *begin_list)
			{
				*begin_list = (*begin_list)->next;
				free(aux);
				aux = *begin_list;
			}
		}
		else
			break ;
	}

	while (aux->next != NULL)
	{
		if (cmp(aux->next->data, data_ref) == 0)
		{
			temp = aux->next;
			aux->next = temp->next;
			free(temp);
		}
		else
			aux = aux->next;
	}
	temp = *begin_list;
	while (temp->next != aux)
		temp = temp->next;
	if (cmp(aux->data, data_ref) == 0)
	{
		temp->next = NULL;
		free(aux);
	}
}
