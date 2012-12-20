//
//  main.c
//  testharness
//
//  Created by Tim Storey on 18/12/2012.
//  Copyright (c) 2012 Tim Storey. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
#include "node_types.h"
#include "mazecell_t.h"

int main (int argc, const char * argv[])
{
    STACKPTR *stack;
    stack = allocStack();
    MAZECELL_T *cell;
    cell = (MAZECELL_T*)malloc(sizeof(MAZECELL_T));
    cell->flags = (SOLID | VISTED);
    printf("cell->flags:%d\n", cell->flags);
    push(stack, cell);
    printf("size: %d\n", stack->size);
    
    for(int i =0; i<200; i++){
        MAZECELL_T *tmp = (MAZECELL_T*)malloc(sizeof(MAZECELL_T));
        tmp->flags = i;
        printf("i:%d flags:%d\n", i, tmp->flags);
        push(stack, tmp);
        printf("size: %d\n", stack->size);
    }
    
    for(int i=0; i<200; i++){
        MAZECELL_T *new;
        new = pop(stack);
        printf("size: %d\n", stack->size);
        printf("new->flags:%d\n", new->flags);
    }
    
    MAZECELL_T *tmp;
    tmp = pop(stack);
    printf("tmp->flags:%d\n", tmp->flags);
    tmp = pop(stack);
    printf("size: %d\n", stack->size);
    if (!tmp) {
        printf("null ptr\n");
        exit(-1);
    }
    printf("tmp->flags:%d\n", tmp->flags);
    free(tmp);
    free(cell);
    
    destroyStack(stack);
    
    
    return 0;
}

