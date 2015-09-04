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

#ifndef STACK_H
#define STACK_H

typedef struct stack stack;

//Stack Object
struct stack {
    struct stackype * type;
    int value;
};

//Stack Type Object
struct stackype {
    void (* construct)(struct stack * this);
    struct stack * (* new)(void);
    void (* delete)(struct stack * this);
    void (* push)(struct stack * this, void * value);
    void * (* pop)(struct stack * this);
} Stack = {
    .construct = stack_construct,
    .new = stack_new,
    .push = stack_push,
    .pop = stack_pop
};

void stack_construct(struct stack * this);
struct stack * stack_new(void);
void stack_delete(struct stack * this);

void stack_push(struct stack * this, void * value);
void * stack_pop(struct stack * this);

#endif//STACK_H
