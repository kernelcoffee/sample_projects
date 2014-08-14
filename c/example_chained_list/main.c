#include <stdlib.h>
#include <stdio.h>

typedef struct clist clist;

struct clist
{
  int value;
  clist* column;
  clist* next;
};


clist* getNext(int n)
{
  clist* set = (clist*)malloc(sizeof(clist));
  set->value = n;
  set->column = '\0';
  set->next = '\0';

  return set;
}

int main(int argc, char *argv[])
{
  clist* list = getNext(0);
  clist* first = list;

  /* Assignation phase */
  printf("assigning\n");
  for (int i = 0; i < 10; i++)
    {
      clist* temp = getNext(0);
      list->column = temp;
      for (int n = 0; n < 10; ++n)
	{
	  printf(" %d", temp->value);
	  temp->next = getNext(n + 1);
	  temp = temp->next;
	}
      printf(" %d", temp->value);
      list->next = getNext(i);
      list = list->next;
      printf("\n");
    }

  printf("showing\n");
  /* Reading phase */
  list = first;
  while (list != '\0')
    {
      clist* temp = list->column;
      while (temp != '\0')
  	{
  	  printf(" %d", temp->value);
  	  temp = temp->next;
  	}
      list = list->next;
      printf("\n");
    }

  return 0;
}
