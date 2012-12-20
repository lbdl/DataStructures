//
//  node_types.h
//
//  Created by Tim Storey on 15/12/2012.
//  Copyright (c) 2012 Tim Storey. All rights reserved.
//

#ifndef NODE_TYPES__H
#define NODE_TYPES__H

typedef struct s_node{
    struct s_node *next;
    void *data;
}S_LIST_NODE;

typedef struct d_node{
    void *data;
    struct d_node *next;
    struct d_list_node *prev;
}D_LIST_NODE;

typedef struct stack{
    int size;
    S_LIST_NODE *head;
}STACKPTR;

#endif
