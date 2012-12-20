//
//  stack.c
//
//  Created by Tim Storey on 15/12/2012.
//  Copyright (c) 2012 Tim Storey. All rights reserved.
//
//  Notes: there is no size limit to the stack as implemented here which is probably a mistake

#ifndef STACK__C
#define STACK__C

#include <stdio.h>
#include <stdlib.h>

#include "node_types.h"
#include "stack.h"

STACKPTR* allocStack(){
    STACKPTR *sptr;
    sptr = (STACKPTR*)malloc(sizeof(STACKPTR));
    sptr->head = (S_LIST_NODE*)malloc(sizeof(S_LIST_NODE));
    sptr->head->next = NULL;
    sptr->size = 0;
    //20121217 need error handling
    return sptr;
}

void destroyStack(STACKPTR *sptr){
    free(sptr->head);
    free(sptr);
}

S_LIST_NODE* getnode(STACKPTR *ptr){
    S_LIST_NODE *tmp;
    tmp = (S_LIST_NODE*)malloc(sizeof(S_LIST_NODE));
    return tmp;
}

int dropnode(S_LIST_NODE *ptr){
    if (ptr != NULL) {
        free(ptr);
        return 0;
    }else{
        return -1;
    }
}

int push(STACKPTR *s, void *ele){
    //get a node and make it point to ele
    S_LIST_NODE *c;
    S_LIST_NODE *t;
    
    //need proper exception handling
    c = getnode(s);
    
    c->data = ele;
    
    if (s->head->next == NULL) {
        //empty list
        c->next = NULL;
        s->head->next=c;
    }else{
        t = s->head->next;
        c->next = t;
        s->head->next = c;
    }
    s->size++;
    return 0;
}

void* pop(STACKPTR *s){
    //get the top of the stack, return it then delete it
    S_LIST_NODE *currNode;
    S_LIST_NODE *tmp;
    
    if(s->head->next==NULL){
        //empty list
        printf("Stack empty - returning NULL\n");
        return NULL;
    }else{
        currNode = s->head->next;
    }
    
    void *ele;
    ele = currNode->data;
    
    if (currNode->next == NULL) {
        s->head->next = NULL;
        s->size--;
        free(currNode);
    }else{
        tmp = currNode->next;
        s->head->next = tmp;
        s->size--;
        free(currNode);
    }
    return ele;
};


#endif