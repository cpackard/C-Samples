#ifndef LINKED_LIST
#define LINKED_LIST

typedef struct LinkedList {
  int data;
  struct LinkedList *next;
} LinkedList;

LinkedList * createList (int data, LinkedList *next) {
  LinkedList *node = malloc( sizeof( LinkedList ) );
  node->data = data;
  node->next = next;

  return node;
}

int length (LinkedList *head) {
  int i = 0;
  LinkedList *temp = head;
  while( temp != 0 ) {
    i++;
    temp = temp->next;
  }

  return i;
}

void push (LinkedList **headRef, int newData) {
  LinkedList *node = createList( newData, *headRef );
  *headRef = node;
}

LinkedList * buildOneTwoThree () {
  int i;
  LinkedList *list = 0;
  for( i = 3; i > 0; i-- ) {
    LinkedList *node = createList( i, list );
    list = node;
  }

  return list;
}

void printList (LinkedList *list) {
  while( list != 0 ) {
    printf( "[%i]", list->data );
    list = list->next;
  }
}

void deleteList (LinkedList *list) {
  while( list != 0 ) {
    LinkedList *temp = list;
    list = list->next;
    free( temp );
  }
}

#endif
