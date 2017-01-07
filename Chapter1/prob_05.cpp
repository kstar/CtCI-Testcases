/***************************************************************************
                              prob_05.cpp  -
                             -------------------
    begin                : Mon 10 Oct 2016 04:50:13 CDT
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
#include <string>
#include <iostream>

bool checkOneAway( const std::string &s1, const std::string &s2 ) {
}

int main() {
    std::string s1, s2;
    std::cin >> s1 >> s2;
    std::cout << checkOneAway( s1, s2 ) << std::endl;
}
