#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Set87_Headers.h"

void problem1();
int * findNextGreater( int *input, int length);

void problem2();
iNode * reverseListK( iNode *inputList, int k );

void problem3();
void kthParent( bNode *root, iNode *parent, iNode **returnList, int k);

int main() {
    // Problem #1
    problem1();

    // Problem #2
    problem2();

    // Problem #3
    problem3();

    return 0;
}


/*
    1) Given an array of numbers find the next greater number to the right of each element
    ex. Input   12 15 22 09 07 02 18 23 27
        Output  15 22 27 18 18 18 23 27 -1

*/
void problem1() {
    printf( "###### Problem 1 ######\n\n" );
    int findNextGreaterInput[] = { 12, 15, 22, 9, 7, 2, 18, 23, 27 };
    int findNextGreaterLength = 9;
    int i;

    printf( "Input:\t" );
    for( i = 0; i < findNextGreaterLength; i++ ) {
        printf( "%i\t", findNextGreaterInput[i] );
    }
    printf( "\n" );

    int *findNextGreaterOutput = findNextGreater( findNextGreaterInput, findNextGreaterLength );

    printf( "Output:\t" );
    for( i = 0; i < findNextGreaterLength; i++ ) {
        printf( "%i\t", findNextGreaterOutput[i] );
    }
    free( findNextGreaterOutput );
    printf( "\n\n" );
}

int * findNextGreater( int *input, int length) {
    int *output = calloc( length, sizeof( int ) );// Where we will store the results
    int i;
    int j;

    for( i = 0; i < length; i++ ) {
        for( j = i+1; j < length+1; j++ ) {
            if( j == length ) { // Reached end of the array
                output[i] = -1;
                break;
            }
            else if( input[j] > input[i] ) { // Check if we have found the next greater element
                output[i] = input[j];
                break;
            }
        }
    }

    return output;
}


/*
    2) Given a linked list and an int k, reverse the linked list in k sized slots
    ex. Input   12 -> 13 -> 3 -> 20 -> 55 -> 87 -> 20 -> 77 -> 90  Let k = 3
        Output  3 -> 13 -> 12 -> 87 -> 55 -> 20 -> 90 -> 77 -> 20
*/

void problem2() {
    printf( "###### Problem 2 ######\n\n" );
    // Set up list for use
    iNode *j = malloc( sizeof( iNode ) );
    j->data = 90; j->next = NULL;
    iNode *h = malloc( sizeof( iNode ) );
    h->data = 77; h->next = j;
    iNode *g = malloc( sizeof( iNode ) );
    g->data = 20; g->next = h;
    iNode *f = malloc( sizeof( iNode ) );
    f->data = 87; f->next = g;
    iNode *e = malloc( sizeof( iNode ) );
    e->data = 55; e->next = f;
    iNode *d = malloc( sizeof( iNode ) );
    d->data = 20; d->next = e;
    iNode *c = malloc( sizeof( iNode ) );
    c->data = 3; c->next = d;
    iNode *b = malloc( sizeof( iNode ) );
    b->data = 13; b->next = c;
    iNode *a = malloc( sizeof( iNode ) );
    a->data = 12; a->next = b;

    printf( "Original List:\t" );
    iNode *current = a;
    while( current != 0 ) {
        printf( "%i\t", current->data );
        current = current->next;
    }
    printf( "\n" );

    printf( "Reversed List:\t" );
    iNode *reverseOutput = reverseListK ( a, 3 );
    current = reverseOutput;
    while( current != NULL ) {
        printf( "%i\t", current->data );
        current = current->next;
    }
    printf( "\n\n" );

    // Cleanup
    iNode *temp;
    current = reverseOutput;
    while( current != 0 ) {
        temp = current;
        current = current->next;
        free( temp );
    }
}

// Helper function to reverse iNode list
iNode * reverseList( iNode *input ) {
    iNode *current = input;
    iNode *next = input->next;
    iNode *temp;

    // set up end of the list
    current->next = NULL;

    while( next != 0 ) {
        temp = current;
        current = next;
        next = current->next;
        current->next = temp;
    }

    return current;

}

iNode * reverseListK( iNode *inputList, int k ) {
    if( inputList == 0 ) { // Bottom-out condition
        return inputList;
    }
    else {
        iNode *current = inputList;
        iNode *nextList = current;
        int i;

        // get to the last element of the slot
        for( i = 0; i < k; i++ ) {
            nextList = nextList->next;
        }

        iNode *next = inputList->next;
        iNode *temp;
        // save for later reference
        iNode *originalCurrent = current;

        // set up end of the list
        current->next = NULL;

        // reverse the current slot
        for( i = 0; i < k-1; i++ ) {
            temp = current;
            current = next;
            next = current->next;
            current->next = temp;
        }

        // recursive call to next slot
        originalCurrent->next = reverseListK( nextList, k );
        return current;
    }
}

void problem3() {
    printf( "###### Problem 3 ######\n\n" );
    bNode *node1 = 0;
    insert( 60, &node1 );
    insert( 41, &node1 );
    insert( 74, &node1 );
    insert( 16, &node1 );
    insert( 53, &node1 );
    insert( 65, &node1 );
    insert( 25, &node1 );
    insert( 46, &node1 );
    insert( 55, &node1 );
    insert( 63, &node1 );
    insert( 70, &node1 );
    insert( 42, &node1 );
    insert( 62, &node1 );
    insert( 64, &node1 );

    printf("Input Tree: \n");
    printTree( node1, 0 );

    int k = 3;
    iNode *returnList = 0;
    kthParent( node1, 0, &returnList, k );

    printf("Output for k = %i:\t", k );
    iNode *temp = returnList;
    while( temp != 0 ) {
      printf("\t%i", temp->data );
      temp = temp->next;
    }
    printf("\n\n");

    // cleanup returned list
    while( returnList != 0 ) {
      temp = returnList;
      returnList = returnList->next;
      free( temp );
    }

    destroy_tree( node1 );
}

void kthParent( bNode *root, iNode *parent, iNode **returnList, int k) {
  if( root->left == 0 && root->right == 0) {
    // Reached a leaf node, see if we have a kth parent
    printf("Reached a child node\n");
    int i;
    iNode *myParent = parent;
    for( i = 0; i < k-1; i++) {
      if( parent != 0 ) { // sanity check
        parent = parent->next;
      }
      else {
        // cleanup parent, we're being picky
        /*
        iNode *temp;
        while( myParent != 0 ) {
          temp = myParent;
          myParent = myParent->next;
          free( temp );
        }
        */
        break;
        //return; // less than k ancestors, exit
      }
    }

    if( i == k-1 ) {
        printf("Have a Kth appropriate ancestor\n");
        printf("Parent data: %i\n", parent->data);
        // setup return data
        iNode *node = ( iNode * ) malloc( sizeof( iNode ) );
        node->data = parent->data;
        node->next = 0;

        printf("Setup return value\n");
        // cleanup parent list
        /*
        iNode *temp = 0;
        while( myParent != 0 ) {
            temp = myParent;
            myParent = myParent->next;
            free( temp );
        }
        */

        printf("Successfully freed parent\n");

        if( *returnList != 0 ) { // append the node on to the return list
            iNode *temp = *returnList;
            iNode *prev;
            while( temp != 0 ) {
                prev = temp;
                temp = temp->next;
            }
            prev->next = node;
        }
        else { // first return value we've found
            *returnList = node;
        }
    }
  }

  else {
    if( root->left != 0 ){
      // set up parent chain
      iNode *current = (iNode *) malloc( sizeof( iNode ) );
      current->data = root->key_value;

      if( parent == 0 ) {
        current->next = 0;
        kthParent( root->left, current, returnList, k);
      }
      else {
        current->next = parent;
        kthParent( root->left, current, returnList, k);
      }
    }
    if( root->right != 0 ){
      // set up parent chain
      iNode *current = (iNode *) malloc( sizeof( iNode ) );
      current->data = root->key_value;

      if( parent == 0 ) {
        current->next = 0;
        kthParent( root->right, current, returnList, k);
      }
      else {
        current->next = parent;
        kthParent( root->right, current, returnList, k);
      }
    }
  }
}
