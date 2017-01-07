/***************************************************************************
                              prob_07.cpp  -
                             -------------------
    begin                : Thu 13 Oct 2016 18:43:50 CDT
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
#include <unordered_map>
#include <tuple>

struct Node {
    int data;
    struct Node *next;
};

bool intersecting( const Node * const head1, const Node * const head2 ) {
    // Your code goes here
}

const int entryBound = 100;

std::pair<Node *, Node *> _makeList( int length ) { // Returns (head, tail) pair
    if ( length == 0 )
        return std::pair<Node *, Node *>( nullptr, nullptr );
    int count = 0;
    Node *head = new Node{ rand()%entryBound, nullptr };
    Node *tail = head;
    while ( ++count < length )
        tail = ( tail->next = new Node{rand()%entryBound, nullptr} );
    return std::pair<Node*, Node*>( head, tail );
}

std::pair<Node *, Node*> makeIntersectingLists( const unsigned int maxLength ) { // Returns two heads
    if ( maxLength == 0 )
        return std::pair<Node *, Node *>( nullptr, nullptr );

    int commonPartLength = rand()%maxLength + 1;
    Node *commonPartHead = _makeList( commonPartLength ).first;
    int remainderLength = maxLength - commonPartLength;
    if ( remainderLength == 0 )
        return std::pair<Node*, Node*>( commonPartHead, commonPartHead );

    std::pair<Node *, Node*> headTail;
    Node *head1 = nullptr, *head2 = nullptr;
    headTail = _makeList( rand()%remainderLength );
    if ( headTail.first ) {
        headTail.second->next = commonPartHead;
        head1 = headTail.first;
    }
    else
        head1 = commonPartHead;
    headTail = _makeList( rand()%remainderLength );
    if ( headTail.first ) {
        headTail.second->next = commonPartHead;
        head2 = headTail.first;
    }
    else
        head2 = commonPartHead;

    assert( head1 && head2 );

    return std::pair<Node*, Node*>( head1, head2 );
}

std::pair<Node *, Node *> makeDisjointLists( const unsigned int maxLength ) {
    if ( maxLength == 0 )
        return std::pair<Node *, Node *>( nullptr, nullptr );

    return std::pair<Node *, Node *>( _makeList( rand()%( maxLength + 1 ) ).first,
                                      _makeList( rand()%( maxLength + 1 ) ).first );
}

void printListPointers( const Node *head ) {
    while ( head ) {
        std::cout << head << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    const int testCases = 4096;
    const unsigned int maxLength = 2048;
    std::srand( std::time( 0 ) );

    for ( int k = 0; k < testCases; ++k ) {
        std::pair<Node *, Node *> pairOfHeads;
        bool intersect = ( rand()%10 > 4 );
        if ( intersect )
            pairOfHeads = makeIntersectingLists( maxLength );
        else
            pairOfHeads = makeDisjointLists( maxLength );

        /*
        std::cout << "List 1: ";
        printListPointers( pairOfHeads.first );
        std::cout << "List 2: ";
        printListPointers( pairOfHeads.second );

        std::cout << "Expected answer: " << intersect << std::endl;
        std::cout << "Actual answer: " << intersecting( pairOfHeads.first, pairOfHeads.second ) << std::endl;
        */

        assert( intersect == intersecting( pairOfHeads.first, pairOfHeads.second ) );
    }
}
