//
//  stack.h
//  OpenGL_2D
//
//  Created by Tim Storey on 15/12/2012.
//  Copyright (c) 2012 Tim Storey. All rights reserved.
//

#ifdef __cplusplus
extern "C" {
#endif

#ifndef STACK__H
#define STACK_H

#include "node_types.h"


STACKPTR* allocStack();
void destroyStack(STACKPTR *sptr);
void* pop(STACKPTR *s);
int push(STACKPTR *s, void *ele);

#endif

#ifdef __cplusplus
}
#endif