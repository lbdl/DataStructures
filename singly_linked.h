//
//  Header.h
//
//  Created by Tim Storey on 15/12/2012.
//  Copyright (c) 2012 Tim Storey. All rights reserved.
//

#ifndef S_LIST__H
#define S_LIST__H

typedef struct{
    extern s_link_node *head;
}s_list;

s_list* createlist();
int dropList(s_list *list);

void* getEle(s_list *list, void *data);
int setEle(s_list *list, void *data);
int dropEle(s_list *list, void *data);


#endif
