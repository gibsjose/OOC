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
    stack * st = Stack.new();

    int * value = Stack.pop(st);

    print("Value 1: %d\n", *value);

    *value = 1;

    Stack.push(st, &value);

    value = 0;
    value = Stack.pop(st);

    printf("Value 2: %d\n", *value);

    return 0;
}
