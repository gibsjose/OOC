/**********************************************************
*   Object-Oriented Stack in C
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

#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

#define STACK_INCREMENT 1024    //Arbitrary stack incrementation size. This is the
                                //default starting size and the amount which is added
                                //each time using `realloc()` the stack is full.

typedef int stack_data_t;
typedef size_t stack_size_t;
typedef struct stack stack;

//Stack Object
struct stack {
    struct stack_object_t * object;
    stack_data_t * pointer;
    stack_size_t size;
};

//Methods
void stack_construct(struct stack * this) {
    this->pointer = (stack_data_t *)malloc(STACK_INCREMENT);
    this->size = 0;
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

void stack_push(struct stack * this, stack_data_t value) {
    this->size++;
    *(this->pointer++) = value;
}

stack_data_t stack_peek(struct stack * this) {
    stack_data_t * pointer = this->pointer;
    return *(--pointer);
}

stack_data_t stack_pop(struct stack * this) {
    this->size--;
    return *(--this->pointer);
}

int stack_empty(struct stack * this) {
    return (int)(this->size <= 0);
}

//Stack Type Object
struct stack_object_t {
    void (* construct)(struct stack * this);
    struct stack * (* new)(void);
    void (* delete)(struct stack * this);
    void (* push)(struct stack * this, stack_data_t value);
    stack_data_t (* peek)(struct stack * this);
    stack_data_t (* pop)(struct stack * this);
    int (* empty)(struct stack * this);
} Stack = {
    .construct = stack_construct,
    .new = stack_new,
    .push = stack_push,
    .peek = stack_peek,
    .pop = stack_pop,
    .empty = stack_empty
};

void stack_construct(struct stack * this);
struct stack * stack_new(void);
void stack_delete(struct stack * this);

void stack_push(struct stack * this, stack_data_t value);
stack_data_t stack_peek(struct stack * this);
stack_data_t stack_pop(struct stack * this);
int stack_empty(struct stack * this);

#endif//STACK_H
