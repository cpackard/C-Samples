#ifndef SET87_HEADERS
#define SET87_HEADERS

typedef struct iNode { 
    int data;
    struct iNode *next;
} iNode;

// Binary Tree definitions

typedef struct bNode { 
    int key_value;
    struct bNode *left;
    struct bNode *right;
} bNode;

void destroy_tree( bNode *leaf ) {
    if( leaf != 0 ) {
        destroy_tree( leaf->left );
        destroy_tree( leaf->right );
        free( leaf );
    }
}

void insert( int key, bNode **leaf ) {
    if( *leaf == 0 ) {
        *leaf = (bNode *) malloc( sizeof( bNode ) );
        (*leaf)->key_value = key;
        // Initialize children to null
        (*leaf)->left = 0;
        (*leaf)->right = 0;
    }
    else if( key < (*leaf)->key_value ) {
        insert( key, &(*leaf)->left );
    }
    else if( key > (*leaf)->key_value ) {
        insert( key, &(*leaf)->right );
    }
}

bNode * search( int key, bNode *leaf ) {
    if( leaf != 0 ) {
        if( key == leaf->key_value ) {
            return leaf;
        }
        else if( key < leaf->key_value ) {
            search( key, leaf->left );
        }
        else {
            search( key, leaf->right );
        }
    }
    
    return 0;
}

void printTree( bNode *node, int k ) {
    if( node != 0 ) {
        // Tab out to make it look nice
        int i;
        for( i = 0; i < k; i++ ) {
            printf( "\t" );
        }
        k++; // Increment so the next calls also format nicely
        printf( "\t%i\n", node->key_value );
        printTree( node->left, k );
        printTree( node->right, k );
    }
}

#endif
