/***************************************************************************
                              prob_04.cpp  -
                             -------------------
    begin                : Mon 10 Oct 2016 03:30:45 CDT
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
#include <vector>
#include <string>
#include <iostream>

bool isPalindromePermutation( const std::string &s ) {
}

int main() {
    std::string s;
    std::getline( std::cin, s );
    std::cout << std::string( isPalindromePermutation( s ) ? "true" : "false" ) << std::endl;

}
