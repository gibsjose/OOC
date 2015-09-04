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

#include <stdlib.h>
#include "stack.h"

//Methods
void stack_construct(struct stack * this) {
    this->value = 0x08;
}

stack * stack_new(void) {
    stack * this = calloc(1, sizeof(stack));
    stack_construct(this);
    return this;
}

void stack_delete(stack * this) {
    if(this != NULL) {
        free(this);
    }
}

void stack_push(struct stack * this, void * value) {
    this->value = *(int *)value;
}

void * stack_pop(struct stack * this) {
    return &(this->value);
}
