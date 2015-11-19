#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

LinkedList * findMthElementFromEnd (LinkedList *, int);
void findMthElementFromEndTest ();

LinkedList * BuildFromEnd (int);
void buildFromEndTest ();

LinkedList * BuildFromEndWithDummy (int);
void buildFromEndWithDummyTest ();

LinkedList * BuildFromEndWithLocalRef (int);
void buildFromEndWithLocalRefTest ();

int Count (LinkedList *, int);
void countTest ();

int GetNth (LinkedList *, int);
void GetNthTest ();

int Pop (LinkedList **);
void PopTest ();

void insertNth (LinkedList **, int, int);
void insertNthTest ();

void sortedInsert (LinkedList **, LinkedList *);
void sortedInsertTest ();

void insertSort (LinkedList **);
void insertSortTest ();

void append (LinkedList **, LinkedList **);
void appendTest ();

void splitFrontBack (LinkedList *, LinkedList **, LinkedList **);
void splitFrontBackTest ();

void removeDuplicates (LinkedList *);
void removeDuplicatesTest ();

void moveNode (LinkedList **, LinkedList **);
void moveNodeTest ();

void alternatingSplit (LinkedList *, LinkedList **, LinkedList **);
void alternatingSplitTest ();

LinkedList* shuffleMerge (LinkedList *, LinkedList *);
void shuffleMergeTest ();

LinkedList* sortedMerge (LinkedList*, LinkedList*);
void sortedMergeTest ();

void mergeSort (LinkedList**);
void mergeSortTest ();

LinkedList* sortedIntersect (LinkedList*, LinkedList*);
void sortedIntersectTest ();

void reverse (LinkedList**);
void reverseTest ();

void recursiveReverse (LinkedList**);
void recursiveReverseTest ();

int main () {
  findMthElementFromEndTest();

  buildFromEndTest();
  buildFromEndWithDummyTest();    
  buildFromEndWithLocalRefTest();

  countTest();

  GetNthTest();

  PopTest();

  insertNthTest();

  sortedInsertTest();

  insertSortTest();
  
  appendTest();

  splitFrontBackTest();

  removeDuplicatesTest();

  moveNodeTest();
  
  alternatingSplitTest();

  shuffleMergeTest();

  sortedMergeTest();

  mergeSortTest();

  sortedIntersectTest();

  reverseTest();

  recursiveReverseTest();
   
  return 0;
}

/*
Write a findMth function that takes a linked list and an integer index and 
returns the data value stored in the node at that index position.
*/
LinkedList * findMthElementFromEnd (LinkedList *list, int m) {
  LinkedList *currentNode = list;
  int i;
  for( i = 0; i < m; i++ ) {
    if ( currentNode != 0 ) {
      currentNode = currentNode->next;
    }
    else {
      return 0;
    }
  }

  LinkedList *mthNode = list;
  while( currentNode != 0 ) {
    mthNode = mthNode->next;
    currentNode = currentNode->next;
  }

  return mthNode;
}

void findMthFromEndTest () {
LinkedList *list = 0;
  int i;
  for( i = 8; i >= 0; i-- ) {
    LinkedList *node = createList( i, list );
    list = node;
  }

  LinkedList *temp = list;
  printf( "----findMthFromEndTest----\n\n**** Input List ****\n\t" );
  printList( temp );
  printf( "\n" );

  temp = list;
  int m = 8;
  LinkedList *mthElement = findMthElementFromEnd( temp, m );
  
  int mthItem = -1;
  if( mthElement != 0 ) {
    mthItem = mthElement->data;
  }

  printf( "**** %i'th Element From End****\n\t%i\n", m, mthItem );
  printf( "\n\n");
    
  deleteList( list );
}

// Build a linked list with n elements by appending nodes onto the end.
// @returns The head of the list.
LinkedList * buildFromEnd (int n) {
  LinkedList *head = 0;
  LinkedList *tail = 0;
  int i;

  // special case for head node
  push( &head, 0 );
  tail = head;

  // build the rest of the list
  for( i = 1 ; i < n; i++ ) {
    push( &(tail->next), i );
    tail = tail->next;
  }

  return head;
}

void buildFromEndTest () {
  int n = 6;
  printf( "----buildFromEndTest----\n\n**** Output List ****\n\t" );
  printList( buildFromEnd( n ) );
  printf( "\n" );
}

// Build a linked list with n elements by appending nodes onto the end
//  using a dummy node
// @param n The number of nodes to create
// @returns The head of the list
LinkedList * buildFromEndWithDummy (int n) {
  LinkedList dummy; // dummy is temporarily the first node
  LinkedList *tail = &dummy; // build the list on dummy.next (aka tail->next)

  int i;
  dummy.next = 0;

  for( i = 0; i < n; i++ ) {
    push( &(tail->next), i );
    tail = tail->next;
  }

  return dummy.next;
}

void buidFromEndWithDummyTest () {
  int n = 6;
  printf( "----buildFromEndWithDummy----\n\n**** Output List ****\n\t" );
  printList( buildFromEndWithDummy( n ) );
  printf( "\n" );
}

// Build a linked list with n elements by appending nodes onto the end
//  using a local reference pointer.
// @param n The number of nodes to create
// @returns The head of the list
LinkedList * buildFromEndWithLocalRef (int n) {
  LinkedList *head = 0; 
  LinkedList **lastPtrRef = &head; // Start by pointing to head
  int i;

  for( i = 0; i < n; i++ ) {
    push( lastPtrRef, i ); // add node to the last pointer in the list
    lastPtrRef = &( (*lastPtrRef)->next ); // advance to the new last pointer
  }

  return head;
}

void buildFromEndWithLocalRefTest () {
  int n = 6;
  printf( "----buildFromEndWithLocalRefTest----\n\n**** Output List ****\n\t" );
  printList( buildFromEndWithLocalRef( n ) );
  printf( "\n" );
}

// Given an input list, return the number of nodes that contain searchData
// @param list The linked list to search
// @param searchData The int to search for
// @returns The number of times searchData appears in the given list
int Count (LinkedList *list, int searchData) {
  int count = 0;
  LinkedList *current = list;
  
  while( current != 0 ) {
    if( searchData == current->data ) {
      count++;
    }

    current = current->next;
  }

  return count;
}

void countTest() {
  printf( "----countTest----\n\n****Input List****\n\t" );
  LinkedList *list = buildOneTwoThree();
  int searchData = 2;

  printList( list );
  printf( "\nSearch Element: %i\n", searchData );
  int count = Count( list, searchData );
  printf( "Count for searchData: %i\n\n", count );

  deleteList( list );
}

// Given an list and an index, return the data in the nth
// node of the list. If the index is outside the range of 
// the list, return -1
int GetNth (LinkedList *list, int index) {
  int i;
  for( i = 0; i < index; i++ ) {
    if( list != 0 ) {
      list = list->next;
    }
    else {
      return -1;  // TODO: handle error more robustly
                  //  (what if the node actually contains -1?)
    }
  }

  return list->data;
}

void GetNthTest () {
  LinkedList *list = buildOneTwoThree();
  int index = 2;

  printf( "---GetNthTest---\n\t");

  if( GetNth( list, index ) == 3 ) {
    printf("Passed!\n\n");
  }
  else {
    printf("Failed :(\n\n");
  }

  deleteList( list );
}

// The opposite of Push. Takes a non-empty list, removes the first
// node and returns that node's data. Assert() fails when given an
// empty list.
int Pop (LinkedList **listRef) {
  LinkedList *temp = *listRef;

  if( temp == 0 ) {
    return -1; // TODO: create actual Assert() function
  }

  // update the head of the list
  *listRef = (*listRef)->next;

  int headData = temp->data;

  free( temp );

  return headData;
}

void PopTest () {
  LinkedList *list = buildOneTwoThree();

  printf( "----PopTest----\n\t" );

  int i;
  for( i = 1; i < 4; i++ ) {
    int data = Pop( &list );

    if( data != i ) {
      printf( "Failed: expected %i, but actual was %i\n\n", i, data );
      return;
    }
  }

  printf( "Passed!\n\n" );

  deleteList( list );
}

// A more general version of Push.
// Given a reference to a list, an index between 0-Length(list), and
// input data, add a new node at the nth index of the list.
void insertNth (LinkedList **listRef, int index, int data) {
  int i;
  LinkedList *current = *listRef;
  LinkedList *prev = 0;

  for( i = 0; i < index; i++ ) {
    if( current != 0 ) {
      prev = current;
      current = current->next;
    }
    else {
      printf( "WARNING: index out of bounds, node will not be added\n" );
      return;
    }
  }

  LinkedList *node = createList( data, current );

  // Inserting somewhere other than the head
  if( prev != 0 ) {
    prev->next = node;
  }
  else {
       *listRef = node;  // Inserting at the head, update references
  }
}

void insertNthTest () {
  LinkedList *list = buildOneTwoThree();
  int data = 4;
  int index = 3;

  printf( "---insertNthTest\n" );
  
  insertNth( &list, index, data );
  printf( "\tExpected: \t[1][2][3][4]\n\tActual: \t" );
  printList( list );
  printf( "\n\n" );

  insertNth( &list, 0, 5 );
  printf( "\tExpected: \t[5][1][2][3][4]\n\tActual: \t" );
  printList( list );
  printf( "\n\n" );

  insertNth( &list, 2, 6 );
  printf( "\tExpected: \t[5][1][6][2][3][4]\n\tActual: \t" );
  printList( list );
  printf( "\n\n" );

  deleteList( list );
}

// Given a sorted list and a single node, insert the node into the
// appropriate place.
void sortedInsert (LinkedList **headRef, LinkedList *node) {
  int nodeData = node->data;
  LinkedList *current = *headRef;
  LinkedList *prev = 0;

  while( current != 0 && nodeData > current->data ) {
    prev = current;
    current = current->next;
  }

  if( prev != 0 ) {
    prev->next = node;
    node->next = current;
  }
  else {
    node->next = current;
    *headRef = node;
  }
}

void sortedInsertTest () {
   LinkedList *list = buildOneTwoThree();
   LinkedList *node1 = createList( 5, 0 );

   printf( "----sortedInsertTest----\n" );
   
   sortedInsert( &list, node1);
   printf( "\tExpected: \t[1][2][3][5]\n\tActual: \t" );
   printList( list );
   printf( "\n\n" );

   LinkedList *node2 = createList( 0, 0 );

   sortedInsert( &list, node2 );
   printf( "\tExpected: \t[0][1][2][3][5]\n\tActual: \t" );
   printList( list );
   printf( "\n\n" );

   LinkedList *node3 = createList( 4, 0 );

   sortedInsert( &list, node3 );
   printf( "\tExpected: \t[0][1][2][3][4][5]\n\t Actual: \t" );
   printList( list );
   printf( "\n\n" );

   deleteList( list );
}

// Given a list, rearrange the nodes so they are sorted in
//  increasing order.
void insertSort (LinkedList **headRef) {
  LinkedList *sortedList = 0;
  LinkedList *current = *headRef;

  while( *headRef != 0 ) {
    int data = Pop( headRef );
    LinkedList *node = createList( data, 0 );
    sortedInsert( &sortedList, node );
  }

  *headRef = sortedList;
}

void insertSortTest () {
  LinkedList *list = buildOneTwoThree();
  push( &list, 5 );
  push( &list, 4 );
  push( &list, 6 );

  printf( "----insertSortedTest\n\tInput: " );
  printList( list );

  insertSort( &list );

  printf( "\n\tExpected: \t[1][2][3][4][5][6]\n\tActual: \t" );
  printList( list );
  printf( "\n\n" );

  deleteList( list );
}

// Append 'b' onto the end of 'a', and then set 'b' to null.
void append (LinkedList **aRef, LinkedList **bRef) {
  // if 'a' is null, make it point to 'b'
  if( *aRef == 0 ) {
    *aRef = *bRef;
  }
  else {
    // find the end of 'a' and append 'b'
    LinkedList *temp = *aRef;
    while( temp->next != 0 ) {
      temp = temp->next;
    }

    temp->next = *bRef;
  }

  *bRef = 0;
}

void appendTest () {
  LinkedList *listA = buildOneTwoThree();
  LinkedList *listB = buildOneTwoThree();
  LinkedList *listC = 0;

  printf( "----appendTest----\n" );
  printf( "\tExpected: \t[1][2][3]\n" );
  
  append( &listC, &listA );

  printf( "\tActual: \t" );
  printList( listC );
  printf( "\n\n" );

  printf( "\tExpected: \t[1][2][3][1][2][3]\n" );
  
  append( &listC, &listB );

  printf( "\tActual: \t" );
  printList( listC );
  printf( "\n\n" );

  deleteList( listC );
}

/* Split the nodes of the given list into front and back halves,
 and return the two lists using the reference parameters.
  If the length is odd, the extra node should go in the front list.
  */
void splitFrontBack (LinkedList *source, LinkedList **front
  , LinkedList **back ) {
  // Check against edge cases
  if( source == 0 ) {
    return;
  }
  else if( source->next == 0 ) {
    // Only one node, only set the front
    *front = source;
    
    return;
  }
  else {
    LinkedList *slow = source;
    LinkedList *fast = source->next;
    int lengthIsEven = 0;

    // If there are only 2 nodes, split in half now
    if( fast->next == 0 ) {
      *back = fast;
      slow->next = 0;
      *front = slow;
      return;
    }

    LinkedList *temp = slow;

    while( fast != 0 ) {
      temp = slow;
      slow = slow->next;
      fast = fast->next;

      if( fast != 0 ) fast = fast->next;
      else lengthIsEven = 1;  // list is broken up differently if the list
                                // is odd or even
    }

    // Set up the back
    if( lengthIsEven ) {
      *back = slow;
      temp->next = 0;
    }
    else {
      *back = slow->next;
      slow->next = 0;
    }

    // Set up the front
    *front = source;
  }
}

void splitFrontBackTest () {
  printf( "----splitFrondBackTest----\n" );
  
  LinkedList *list = 0;
  LinkedList *front = 0;
  LinkedList *back = 0;
  push( &list, 1 );

  printf( "\tExpected: \tFront: [1] \tBack: []\n" );
  printf( "\tActual: " );

  splitFrontBack( list, &front, &back );

  printf( "\tFront: " );
  printList( front );
  printf( "\tBack: " );
  if( back == 0 ) {
    printf( "[]\n\n" );
  }
  else {
    printList( back );
    printf( "\n\n" );
  }

  push( &list, 2 );

  printf( "\tExpected: \tFront: [2] \tBack: [1]\n" );
  printf( "\tActual: " );

  splitFrontBack( list, &front, &back );
  printf( "\tFront: " );
  printList( front );
  printf( "\tBack: " );
  printList( back );
  printf( "\n\n" );

  list = buildOneTwoThree();

  printf( "\tExpected: \tFront: [1][2] \tBack: [3]\n" );
  printf( "\tActual: " );

  splitFrontBack( list, &front, &back );
  printf( "\tFront: " );
  printList( front );
  printf( "\tBack: " );
  printList( back );
  printf( "\n\n" );

  list = buildOneTwoThree();
  push( &list, 4 );

  printf( "\tExpected: \tFront: [4][1] \tBack: [2][3]\n" );
  printf( "\tActual: " );

  splitFrontBack( list, &front, &back );
  printf( "\tFront: " );
  printList( front );
  printf( "\tBack: " );
  printList( back );
  printf( "\n\n" );

  deleteList( list );
}

/*
Takes a list sorted in increasing order and
deletes any duplicate nodes from the list
*/
void removeDuplicates (LinkedList *list) {
  // handle edge cases
  if( list == 0 || list->next == 0 ) { // only 0 or 1 nodes
    return;
  }
  
  LinkedList *prev = 0;
  
  while( list != 0 ) {
    prev = list;
    list = list->next;

    if( list && prev->data == list->data ) {
      // found a duplicate, remove from the list
      LinkedList *temp = list;
      list = list->next;
      prev->next = list;

      free( temp );
    }
  }
}

void removeDuplicatesTest () {
  LinkedList *list = buildOneTwoThree();

  printf( "----removeDuplicatesTest----\n\n" );
  printf( "\tInput: \t" );
  printList( list );
  printf( "\n\tExpected: \t[1][2][3]" );
  printf( "\n\tActual: \t" );
  
  removeDuplicates( list );
  printList( list );
  printf( "\n\n" );

  push( &list, 1 );

  printf( "\tInput: \t" );
  printList( list );
  printf( "\n\tExpected: \t[1][2][3]" );
  printf( "\n\tActual: \t" );
  
  removeDuplicates( list );
  printList( list );
  printf( "\n\n" );

  // Test #3
  list = 0;
  push( &list, 1 );
  push( &list, 1 );
  push( &list, 2 );
  push( &list, 3 );
  push( &list, 4 );
  push( &list, 4 );

  printf( "\tInput: \t" );
  printList( list );
  printf( "\n\tExpected: \t[4][3][2][1]" );
  printf( "\n\tActual: \t" );
  
  removeDuplicates( list );
  printList( list );
  printf( "\n\n" );
   
  deleteList( list );
}

/*
 Take the node from the front of the source, and move it to
 the front of the dest.
 It is an error to call this with the source list empty.
*/
void moveNode(LinkedList** destRef, LinkedList** sourceRef) {
  // move the node from source to destination
  LinkedList *node = *sourceRef;

  // update source Ref
  *sourceRef = (*sourceRef)->next;

  // update the destination Ref
  node->next = *destRef;
  *destRef = node;
}

void moveNodeTest () {
  printf( "----moveNodeTest----\n\n" );

  LinkedList *sourceList = buildOneTwoThree();
  LinkedList *destList = buildOneTwoThree();

  printf( "\tInput Lists: \n" );
  printf( "\t\tsourceList: \t" );
  printList( sourceList );
  printf( "\n\t\tdestList: \t" );
  printList( destList );
  printf( "\n\n\tExpected: \n" );
  printf( "\t\tsourceList: \t[2][3]\n" );
  printf( "\t\tdestList: \t[1][1][2][3]\n\n" );
  printf( "\tActual: \n" );

  moveNode( &destList, &sourceList );

  printf( "\t\tsourceList: \t" );
  printList( sourceList );
  printf( "\n\t\tdestList: \t" );
  printList( destList );
  printf( "\n\n" );

  deleteList( sourceList );
  deleteList( destList );
}

/*
 Given the source list, split its nodes into two shorter lists.
  If we number the elements 0, 1, 2, ... then all the even elements
  should go in the first list, and all the odd elements in the second.
  The elements in the new lists may be in any order.
*/
void alternatingSplit (LinkedList* source, LinkedList** aRef,
  LinkedList** bRef) {
  LinkedList *current = source;
  int isEven = 1;

  while( current != 0 ) {
    if( isEven ) {
      moveNode( aRef, &current );
      isEven = 0;
    }
    else {
      moveNode( bRef, &current );
      isEven = 1;
    }
  }
}

void alternatingSplitTest () {
  printf( "----alternatingSplitTest----\n\n" );
  printf( "Input: \t" );

  LinkedList *list = buildOneTwoThree();
  LinkedList *aList = 0;
  LinkedList *bList = 0;

  printList( list );
  printf( "\n\n" );
  
  printf( "\tExpected: \n" );
  printf( "\t\taList: \t[3][1]\n" );
  printf( "\t\tbList: \t[2]\n\n" );

  printf( "\tActual: \n" );
  
  alternatingSplit( list, &aList, &bList );

  printf( "\t\taList: \t" );
  printList( aList );
  printf( "\n\t\tbList: \t" );
  printList( bList );
  printf( "\n\n" );

  deleteList( aList );
  deleteList( bList );
}

/*
 Merge the nodes of the two lists into a single list taking a node
  alternately from each list, and return the new list.
*/
LinkedList* shuffleMerge (LinkedList* a, LinkedList *b) {
  LinkedList* head = 0;
  LinkedList** headRef = &head;
  int isEven = 1;

  while( a && b ) {
    // alternate which list we get the node from
    if( isEven ) {
      moveNode( headRef, &a );
      isEven = 0;
    } else {
      moveNode( headRef, &b );
      isEven = 1;
    }
    headRef = &( (*headRef)->next );
  }

  // get any remaining nodes from the non-empty list
  while( a ) {
    moveNode( headRef, &a );
    headRef = &( (*headRef)->next );
  }
  while( b ) {
    moveNode( headRef, &b );
    headRef = &( (*headRef)->next );
  }

  return head;
}

void shuffleMergeTest () {
  printf( "----shuffleMergeTest----\n\n" );
  printf( "\tInput lists: \n" );

  LinkedList* a = buildOneTwoThree();
  LinkedList* b = buildOneTwoThree();

  printf( "\t\tList a: \t" );
  printList( a );
  printf( "\n\t\tList b: \t" );
  printList( b );
  printf( "\n\n\tExpected: \t[1][1][2][2][3][3]\n" );
  printf( "\tActual: \t" );

  LinkedList *result = shuffleMerge( a, b );
  printList( result );
  printf( "\n\n" );

  printf( "\tInput lists: \n" );

  a = buildOneTwoThree();
  b = buildOneTwoThree();
  push( &a, 4 );
  push( &a, 5 );

  printf( "\t\tList a: \t" );
  printList( a );
  printf( "\n\t\tList b: \t" );
  printList( b );
  printf( "\n\n\tExpected: \t[5][1][4][2][1][3][2][3]\n" );
  printf( "\tActual: \t" );

  result = shuffleMerge( a, b );
  printList( result );
  printf( "\n\n" );

  deleteList( result );
}

/*
 Takes two lists sorted in increasing order, and
  splices their nodes together to make one big
  sorted list which is returned.
*/
LinkedList* sortedMerge (LinkedList* a, LinkedList* b) {
  LinkedList* head = 0;
  LinkedList** headRef = &head;

  while( a && b ) {
    // compare the head nodes of a and b
    if( a->data < b->data ) {
      moveNode( headRef, &a );
    } else {
      moveNode( headRef, &b );
    }

    headRef = &( (*headRef)->next );
  }

  // insert any remaining nodes in a or b
  while( a ) {
    moveNode( headRef, &a );
    headRef = &( (*headRef)->next );
  }
  while( b ) {
    moveNode( headRef, &b );
    headRef = &( (*headRef)->next );
  }

  return head;
}

void sortedMergeTest () {
  printf( "----sortedMergeTest----\n\n" );
  printf( "\tInput lists: \n" );

  LinkedList* a = buildOneTwoThree();
  LinkedList* b = buildOneTwoThree();

  printf( "\t\tList a: \t" );
  printList( a );
  printf( "\n\t\tList b: \t" );
  printList( b );
  printf( "\n\n\tExpected: \t[1][1][2][2][3][3]\n" );
  printf( "\tActual: \t" );

  LinkedList *result = sortedMerge( a, b );
  printList( result );
  printf( "\n\n" );

  printf( "\tInput lists: \n" );

  a = buildOneTwoThree();
  b = buildOneTwoThree();
  LinkedList* node1 = createList( 5, 0 );
  LinkedList* node2 = createList( 4, node1 );
  append( &b, &node2 );

  printf( "\t\tList a: \t" );
  printList( a );
  printf( "\n\t\tList b: \t" );
  printList( b );
  printf( "\n\n\tExpected: \t[1][1][2][2][3][3][4][5]\n" );
  printf( "\tActual: \t" );

  result = sortedMerge( a, b );
  printList( result );
  printf( "\n\n" );

  deleteList( result );
}

// Given an input list, recursively sort the list
void mergeSort (LinkedList** source) {
  // Base case; if there is only one element, it's sorted
  if( (*source)->next == 0 ) {
    return;
  }

  // recursively sort the list
  LinkedList* front = 0;
  LinkedList* back = 0;

  splitFrontBack( *source, &front, &back );

  mergeSort( &front );
  mergeSort( &back );

  *source = sortedMerge( front, back );

  return;
}

void mergeSortTest () {
  printf( "----sortedMergeTest----\n\n" );

  // Test: one node 
  printf( "\tInput list: \t" );
  LinkedList* list = 0;
  push( &list, 4 );
  printList( list );

  printf( "\n\tExpected: \t[4]" );
  printf( "\n\tActual: \t" );

  mergeSort( &list );
  printList( list );
  printf( "\n\n" );

  // Test: two nodes
  printf( "\tInput list: \t" );
  push( &list, 5 );
  printList( list );

  printf( "\n\tExpected: \t[4][5]" );
  printf( "\n\tActual: \t" );

  mergeSort( &list );
  printList( list );
  printf( "\n\n" );

  // Test: three nodes
  printf( "\tInput list: \t" );
  push( &list, 6 );
  printList( list );

  printf( "\n\tExpected: \t[4][5][6]" );
  printf( "\n\tActual: \t" );

  mergeSort( &list );
  printList( list );
  printf( "\n\n" );

  // Test: six nodes
  printf( "\tInput list: \t" );
  list = buildOneTwoThree();
  push( &list, 4 );
  push( &list, 5 );
  push( &list, 6 );
  printList( list );

  printf( "\n\tExpected: \t[1][2][3][4][5][6]" );
  printf( "\n\tActual: \t" );

  mergeSort( &list );
  printList( list );
  printf( "\n\n" );

  deleteList( list );
}

/*
 Compute a new sorted list that represents the intersection
  of the two given sorted lists.
*/
LinkedList* sortedIntersect (LinkedList* a, LinkedList* b) {
  LinkedList* result = 0;
  LinkedList** resultRef = &result;

  while( a && b ) {
    if( a->data == b->data ) {
      push( resultRef, a->data );
      resultRef = &( (*resultRef)->next );
      a = a->next;
      b = b->next;
    } else if( a->data < b->data ) {
      a = a->next;
    } else {
      b = b->next;
    }
  }

  return result;
}

void sortedIntersectTest () {
  printf( "----sortedIntersectTest----\n\n" );
  
  // Test case #1
  printf( "\tInput lists:" );
  
  LinkedList* listA = buildOneTwoThree();
  LinkedList* listB = buildOneTwoThree();
  printf( "\n\t\tList A: \t" );
  printList( listA );
  printf( "\n\t\tList B: \t" );
  printList( listB );

  printf( "\n\n\tExpected: \t[1][2][3]" );
  printf( "\n\tActual: \t" );

  LinkedList* result = sortedIntersect( listA, listB );
  printList( result );

  printf( "\n\n" );

  deleteList( listA );
  deleteList( listB );
  deleteList( result );

  // Test case #2
  printf( "\tInput lists:" );
  
  listA = buildOneTwoThree();
  listB = 0;
  printf( "\n\t\tList A: \t" );
  printList( listA );
  printf( "\n\t\tList B: \t" );
  printList( listB );

  printf( "\n\n\tExpected: \t" );
  printf( "\n\tActual: \t" );

  result = sortedIntersect( listA, listB );
  printList( result );

  printf( "\n\n" );

  deleteList( listA );
  deleteList( listB );
  deleteList( result );

  // Test case #2
  printf( "\tInput lists:" );
  
  listA = buildOneTwoThree();
  listB = 0;
  push( &listB, 6 );
  push( &listB, 3 );
  push( &listB, 1 );
  push( &listB, 0 );
  printf( "\n\t\tList A: \t" );
  printList( listA );
  printf( "\n\t\tList B: \t" );
  printList( listB );

  printf( "\n\n\tExpected: \t[1][3]" );
  printf( "\n\tActual: \t" );

  result = sortedIntersect( listA, listB );
  printList( result );

  printf( "\n\n" );

  deleteList( listA );
  deleteList( listB );
  deleteList( result );

}

// Given a reference to a list, reverse that list.
void reverse (LinkedList** listRef) {
  LinkedList* result = 0;
  LinkedList* input = *listRef;

  while( input ) {
    // update the input list
    LinkedList* temp = input;
    input = input->next;
    
    // push the current element onto the result list
    temp->next = result;
    result = temp;
  }

  // point the original list to the reversed list
  *listRef = result;
}

void reverseTest () {
  printf( "----reverseTest----\n\n" );
  printf( "\tInput list: \t" );

  LinkedList* list = buildOneTwoThree();
  printList( list );

  printf( "\n\tExpected: \t[3][2][1]" );
  printf( "\n\tActual: \t" );

  reverse( &list );
  printList( list );
  printf( "\n\n" );

  deleteList( list );
}

/*
 Recursively reverses the given linked list by changing its .next
  pointers and its head pointer in one pass of the list.
*/
void recursiveReverse (LinkedList** headRef) {
  // base case
  if( (*headRef) == 0 || (*headRef)->next == 0 ) {
    return;
  }

  // Set up local pointers
  LinkedList* prev = *headRef;
  LinkedList* current = prev->next;

  // Disconnect the first node
  prev->next = 0;

  // update the head reference
  *headRef = current;

  recursiveReverse( headRef );

  // as we wind back up the call stack, re-connect the list
  current->next = prev;
}

void recursiveReverseTest () {
  printf( "----recursiveReverseTest----\n\n" );
  // Test #1
  printf( "\tInput list: \t" );

  LinkedList* list = 0;
  push( &list, 1 );
  push( &list, 2 );
  printList( list );

  printf( "\n\tExpected: \t[1][2]" );
  printf( "\n\tActual: \t" );

  recursiveReverse( &list );
  printList( list );
  printf( "\n\n" );

  deleteList( list );

  // Test #2
  printf( "\tInput list: \t" );

  list = buildOneTwoThree();
  printList( list );

  printf( "\n\tExpected: \t[3][2][1]" );
  printf( "\n\tActual: \t" );

  recursiveReverse( &list );
  printList( list );
  printf( "\n\n" );

  deleteList( list );

  // Test #3
  printf( "\tInput list: \t" );

  list = buildOneTwoThree();
  push( &list, 4 );
  push( &list, 5 );
  printList( list );

  printf( "\n\tExpected: \t[3][2][1][4][5]" );
  printf( "\n\tActual: \t" );

  recursiveReverse( &list );
  printList( list );
  printf( "\n\n" );

  deleteList( list );
}
