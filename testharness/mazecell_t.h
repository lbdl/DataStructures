//
//  mazecell_t.h
//  OpenGL_2D
//
//  Created by Tim Storey on 14/12/2012.
//  Copyright (c) 2012 Tim Storey. All rights reserved.
//

#ifndef OpenGL_2D_MazeCell_t_h
#define OpenGL_2D_MazeCell_t_h

#include <stdint.h>

#define SOLID 0x0001
#define START 0x0002
#define END 0x0004
#define VISTED 0x0008
#define PATH 0x0016
#define BACKTRACK 0x0032

#define NORTH 0x0001
#define SOUTH 0x0002
#define EAST 0x0004
#define WEST 0x0008

typedef struct MazeCell_t{
    uint16_t flags;
    uint16_t walls;
}MAZECELL_T;


#endif
