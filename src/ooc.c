/**********************************************************
*   OOC
*
*   03 Sep 2015
*
*   Joe Gibson (gibsjose@mail.gvsu.edu)
*
*   License: MIT (https://user.mit-license.org)
*
*   https://www.gibsjose.com
*   https://github.com/gibsjose/OOC
**********************************************************/

#include <stdio.h>
#include "ooc.h"

int main(int argc, char * argv[]) {
    //Create a new stack object
    stack * st = Stack.new();

    for(int i = 0; i < 10; i++) {
        Stack.push(st, i);
        printf("Value pushed: %d\n", Stack.peek(st));
    }

    putchar('\n');

    while(!Stack.empty(st)) {
        printf("Value popped: %d\n", Stack.pop(st));
    }
}
