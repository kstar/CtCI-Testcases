/***************************************************************************
                              prob_06.cpp  -
                             -------------------
    begin                : Thu 13 Oct 2016 06:40:20 CDT
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
//#include <cstdlib>
//#include <ctime>pp
#include <functional>

struct Node {
    char data;
    struct Node *next;
};

bool isPalindrome( Node *head ) {
    // Your code here
}

Node *parseToList( const std::string &s ) {
    Node *head = nullptr, *tail = nullptr;
    for ( auto e : s ) {
        if ( !head )
            head = tail = new Node{e, nullptr};
        else
            tail = ( tail->next = new Node{e, nullptr} );
    }
    return head;
}

int main() {
    std::cout << "Enter a string: ";
    std::string s;
    std::getline( std::cin, s );
    Node *head = parseToList( s );
    std::cout << std::string( isPalindrome( head ) ? "true" : "false" ) << std::endl;

    // De-alloc
    while ( head ) {
        Node *next = head->next;
        delete head;
        head = next;
    }
}
