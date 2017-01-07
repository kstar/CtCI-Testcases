/***************************************************************************
                              prob_05.cpp  -
                             -------------------
    begin                : Thu 13 Oct 2016 05:04:03 CDT
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
#include <vector>
#include <cstdlib>
#include <ctime>
#include <assert.h>

struct Node {
    int data;
    struct Node *next;
};

Node *sum( Node *head1, Node *head2 ) {
    // Your code goes here
}

void printList( Node *head ) {
    while ( head ) {
        std::cout << head->data << "";
        head = head->next;
    }
    std::cout << std::endl;
}

Node *pushBack( Node * const head, const int data ) {
    if ( !head )
        return new Node{ data, nullptr };

    Node *curr = head;
    while ( curr->next )
        curr = curr->next;
    curr->next = new Node{data, nullptr};
    return head;
}

Node *parseToList( const std::string &number ) {
    Node *head = nullptr;
    auto it = number.end();
    while ( --it >= number.begin() )
        head = pushBack( head, *it - '0' );
    return head;
}

Node *deleteList( Node *head ) {
    while ( head ) {
        Node *next = head->next;
        delete head;
        head = next;
    }
    return head;
}

Node *reverseList( Node *head ) {
    if ( !head )
        return nullptr;
    std::vector<struct Node *> vec;
    while ( head ) {
        vec.push_back( head );
        head = head->next;
    }
    Node *newHead = vec.back();
    Node *curr = newHead;
    auto it = vec.end() - 1;
    while ( --it >= vec.begin() ) {
        curr->next = *it;
        curr = curr->next;
    }
    curr->next = nullptr;
    return newHead;
}

int main() {
    std::cout << "Enter a number: ";
    std::string number1, number2;
    std::getline( std::cin, number1 );
    std::cout << "Enter another number: ";
    std::getline( std::cin, number2 );
    Node *head1 = parseToList( number1 );
    Node *head2 = parseToList( number2 );
    Node *result = sum( head1, head2 );
    std::cout << "Result: ";
    printList( reverseList( result ) );
    deleteList( head1 );
    deleteList( head2 );
    deleteList( result );
}
