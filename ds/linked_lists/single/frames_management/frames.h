/*
 * files: frames.h
 */

#ifndef _FRAMES_H
#define _FRAMES_H
#include <stdio.h>
#include "list.h"
// public interface
int alloc_frame(List *frames);
int free_frame(List *frames, int frame_num);
#endif 
