//
// Created by Jarrid on 4/18/2026.
//

#include "buffer.h"


void stepLeft(GapBuffer *buffer) {
    if (buffer->gap_start==0){return;}
    buffer->gap_start--;
    buffer->gap_end--;

    buffer->data[buffer->gap_end] = buffer->data[buffer->gap_start];
}

void stepRight(GapBuffer *buffer) {
    if (buffer->gap_end == buffer->capacity){return;}

    buffer->data[buffer->gap_start] = buffer->data[buffer->gap_end];

    buffer->gap_start++;
    buffer->gap_end++;

}