#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {

  List *lista=malloc(sizeof(List));
  
  lista->head=NULL;
  lista->tail=NULL;
  lista->current=NULL;
  
  return lista;
}

void * firstList(List * list) {
  

  if(list->head!=NULL)
  {
  list->current=list->head;
  return list->head->data;
  }
  return NULL;
}

void * nextList(List * list) {

  if(list->current!=NULL)
  {
  list->current=list->current->next;
  if(list->current!=NULL)
  {
    return list->current->data;
  }
  }
  return NULL;
}

void * lastList(List * list) {

  int aux=0;
  if(list->current!=NULL)
  {
    while(list->current->next!=NULL)
      {
        list->current=list->current->next;
        aux=1;
      }
    if(aux==1)
    {
      return list->current->data;
    }
    
  }
  
  
  return NULL;
}

void * prevList(List * list) {

  if(list->current!=NULL)
  {
    if(list->current->prev!=NULL)
    {
      list->current=list->current->prev;
      return list->current->data;
    }
  }
  return NULL;
}

void pushFront(List * list, void * data) {

  Node *aux=createNode(data);
  if(list->head!=NULL)
  {
  aux->next=list->head;
  list->head->prev=aux;
  list->head=aux;
  }
  else
  {
    list->head=aux;
    list->tail=list->head;
    list->current=list->head;
  }
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {

  Node *aux=createNode(data);
  if(list->current!=NULL)
  {
    if(list->current->next==NULL)
    {
      list->current->next=aux;
      aux->prev=list->current;
      list->tail=aux;
    }
    else
    {
      aux->next=list->current->next;
      list->current->next=aux;
      list->current->next->prev=list->current;
      list->current=list->current->next;
      list->current->next->prev=list->current;
    }
  }
  
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {

  if(list->current!=NULL)
  {
    
    Node *eliminado=list->current;
    if(list->current->next!=NULL)
    {
      list->current->next->prev=list->current->prev;
    }
    else
    {
      list->tail=list->current->prev;
    }
    if(list->current->prev!=NULL)
    {
      list->current->prev->next=list->current->next;
    }
    else
    {
      list->head=list->current->next;
    }
    list->current=list->current->next;
    
    return eliminado->data;
    
  }
  
  return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}