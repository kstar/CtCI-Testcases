/***************************************************************************
                              prob_02.cpp  -
                             -------------------
    begin                : Thu 13 Oct 2016 00:34:52 CDT
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
#include <ctime>
#include <cstdlib>
#include <assert.h>

struct Node {
    int data;
    struct Node *next;
} *head = nullptr; // global head

const Node *kthToLast( const int K, const Node * const head ) {
    // Your code goes here
}

void append( const int data ) {
    if ( !head )
        head = new Node{data, nullptr};
    else {
        Node *curr = head;
        while ( curr -> next )
            curr = curr -> next;
        curr->next = new Node{data, nullptr};
    }
}

void insertInFront( const int data ) {
    Node *oldHead = head;
    head = new Node{data, oldHead};
}

void clear() {
    Node *curr = head;
    while ( curr ) {
        Node *next = curr->next;
        delete curr;
        curr = next;
    }
    head = nullptr;
}

void printQueue() {
    const Node *curr = head;
    while ( curr ) {
        std::cout << curr->data << " ";
        curr = curr->next;
    }
    std::cout << std::endl;
}

int main() {
    const int testCases = 10;
    const int maxN = 20;
    std::srand( std::time( 0 ) );
    for ( int k = 0; k < testCases; ++k ) {
        int N = rand()%maxN + 1;
        int K = rand()%maxN; // intentionally allowing K to be larger
        const Node *answer = nullptr;
        for ( int j = 0; j < N; ++j ) {
            insertInFront( rand()%100 );
            if ( j == K )
                answer = head;
        }
        std::cout << "Queue (N = " << N << "): "; printQueue();
        std::cout << "K = " << K << std::endl;
        std::cout << "Expected answer = ";
        if ( answer )
            std::cout << answer->data << std::endl;
        else
            std::cout << "Non existent" << std::endl;
        std::cout << "Actual answer = ";
        const Node *result = kthToLast( K, head );
        if ( result )
            std::cout << result->data << std::endl;
        else
            std::cout << "Non existent" << std::endl;

        assert( kthToLast( K, head ) == answer );
        clear();
    }
}
