//
// Created by Jarrid on 4/18/2026.
//

#ifndef TEXTEDITOR_BUFFER_H
#define TEXTEDITOR_BUFFER_H
#include <stddef.h>

typedef struct {
    char text_buffer[2000];
    size_t index;
}BufferNode;

typedef struct {
    int length;
    BufferNode* head;
    BufferNode* tail;
}TextBuffer;



#endif //TEXTEDITOR_BUFFER_H