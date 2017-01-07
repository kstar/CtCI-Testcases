/***************************************************************************
                              prob_01.cpp  -
                             -------------------
    begin                : Tue 11 Oct 2016 20:36:35 CDT
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
#include <unordered_map>
#include <iostream>
#include <ctime>
#include <cstdlib>

/* Linked List Implementation */
struct Node {
    int data;
    struct Node *next;
} *head = nullptr; // Global head

void removeDups_ExtraSpace( Node * const head ) {
    // Your code goes here
}

void removeDups_NoExtraSpace( Node * const head ) {
    // Your code goes here
}

void push_back( int data ) {
    // O(N) push_back method
    if ( !head )
        head = new Node {data, nullptr};

    Node *curr = head;
    while ( curr->next )
        curr = curr->next;
    curr->next = new Node {data, nullptr};
}

void print_list() {
    Node *curr = head;
    while ( curr ) {
        std::cout << curr->data << " ";
        curr = curr->next;
    }
    std::cout << std::endl;
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

int main() {
    const int testCases = 1;
    const int maxItemCount = 32;
    const int maxItem = maxItemCount/3;

    std::srand( std::time( 0 ) );

    for ( int k = 0 ; k < testCases; ++k ) {
        int itemCount = rand()%maxItemCount + 1;
        for ( int i = 0; i < itemCount; ++i )
            push_back( rand()%( maxItem + 1 ) );
        std::cout << "List: "; print_list();
        removeDupsFast( head );
        std::cout << "Fast remove: "; print_list();
        clear();
        for ( int i = 0; i < itemCount; ++i )
            push_back( rand()%( maxItem + 1 ) );
        std::cout << "List: "; print_list();
        removeDupsSlow( head );
        std::cout << "Slow remove: "; print_list();

    }
}
