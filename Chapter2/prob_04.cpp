/***************************************************************************
                              prob_04.cpp  -
                             -------------------
    begin                : Thu 13 Oct 2016 01:55:03 CDT
    copyright            : (c) 2016 by Akarsh Simha
    email                : akarsh.simha@kdemail.net
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/


/* Project Includes */


/* STL Includes */
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <assert.h>

struct Node {
    int data;
    struct Node *next;
};

Node *partition( Node *head, int x ) {
    // Your code goes here
}


Node *append( Node *head, const int data ) {
    if ( !head ) {
        head = new Node{data, nullptr};
    }
    else {
        Node *curr = head;
        while ( curr->next )
            curr = curr->next;
        curr->next = new Node{data, nullptr};
    }
    return head;
}

Node *clear( Node *head ) {
    while ( head ) {
        Node *next = head->next;
        delete head;
        head = next;
    }
    return head;
}

void printList( const Node *head ) {
    while ( head ) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    const int testCases = 1024;
    const int maxSize = 3072;
    const int entryBound = maxSize;
    std::srand( std::time( 0 ) );

    for ( int k = 0; k < testCases; ++k ) {
        // Create testcase
        Node *head = nullptr;
        int x = rand()%entryBound;
        int N = rand()%maxSize + 1;
        for ( int j = 0; j < N; ++j )
            head = append( head, rand()%entryBound );


        // Print the testcase
        /*
        std::cout << "Before partition (N = " << N << "): ";
        printList( head );
        */

        // Partition
        head = partition( head, x );

        // Print the results
        /*
        std::cout << "After partition (x = " << x << "): ";
        printList( head );
        */

        // Verify the results
        Node *curr = head;
        while ( curr && curr->data < x )
            curr = curr->next;
        while ( curr ) {
            assert( curr->data >= x );
            curr = curr->next;
        }

        head = clear( head );
    }
}
