/***************************************************************************
                              prob_08.cpp  -
                             -------------------
    begin                : Thu 13 Oct 2016 21:14:41 CDT
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
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <assert.h>
#include <unordered_map>

struct Node {
    int data;
    struct Node *next;
};


const Node *findCycle( const Node * const head ) {
    // Your code goes here
}


typedef std::pair<Node *,  Node *> NodePair;

NodePair makeList( unsigned int length ) { // Returns a (head, tail) pair
    const int entryBound = 100;
    if ( length == 0 )
        return NodePair( nullptr, nullptr );

    Node *head = new Node{ rand()%entryBound, nullptr };
    Node *tail = head;
    while ( --length > 0 )
        tail = ( tail->next = new Node{ rand()%entryBound, nullptr } );

    return NodePair( head, tail );
}

NodePair makeCycle( const unsigned int length, const unsigned int cycleLength ) { // Returns a (head, cyclestart) pair
    assert( cycleLength <= length );
    NodePair list = makeList( length );
    Node *head = list.first;
    Node *cycleStart = head;
    for ( int i = 0; i < length - cycleLength; ++i )
        cycleStart = cycleStart->next;
    list.second->next = cycleStart;
    return NodePair( head, cycleStart );
}

void printList( const Node *head ) {
    std::unordered_map<const Node *, bool> seen;
    while ( head && !seen.count( head ) ) {
        std::cout << head->data << " ";
        seen[ head ] = true;
        head = head->next;
    }
    if ( head )
        std::cout << "[cycle start = " << head->data << "]";
    std::cout << std::endl;
}

void deleteList( Node *head ) {
    std::unordered_map<const Node *, bool> deleted;
    while ( head && !deleted.count( head ) ) {
        Node *next = head->next;
        deleted[head] = true;
        delete head;
        head = next;
    }
}

int main() {
    const int testCases = 4096;
    const int maxLength = 1024;
    std::srand( std::time( 0 ) );
    for ( int k = 0; k < testCases; ++k ) {
        bool cycle = ( rand()%10 > 3 );
        NodePair nodepair;
        int length = rand()%( maxLength + 1 );
        if ( cycle ) {
            nodepair = makeCycle( length + 1, rand()%( length + 1 ) + 1 );
            /*
            printList( nodepair.first );
            std::cout << "Find cycle returned cycle start: " << findCycle( nodepair.first )->data << std::endl;
            */
            assert( findCycle( nodepair.first ) == nodepair.second );
        }
        else {
            nodepair = makeList( length );
            // printList( nodepair.first );
            assert( findCycle( nodepair.first ) == nullptr );
        }
        deleteList( nodepair.first );

    }
}
