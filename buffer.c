//
// Created by Jarrid on 4/18/2026.
//

#include "buffer.h"
#include <stdlib.h>
#include <memory.h>

bool createGapBuffer(GapBuffer *buffer, size_t initial_capacity)
{
    if (buffer == NULL){return false;}

    buffer->data = malloc(initial_capacity);

    if (buffer->data == NULL)
    {
        buffer->capacity = 0;
        buffer->gap_start = 0;
        buffer->gap_end = 0;

        return false;
    }

    buffer->capacity = initial_capacity;
    buffer->gap_start = 0;
    buffer->gap_end = initial_capacity;

    return true;
}

void destroyGapBuffer(GapBuffer *buffer)
{
    if (buffer == NULL){return;}

    free(buffer->data);

    buffer->data = NULL;
    buffer->capacity = 0;
    buffer->gap_start = 0;
    buffer->gap_end = 0;
}

void moveLeft(GapBuffer *buffer) {
    if (buffer->gap_start==0){return;}
    buffer->gap_start--;
    buffer->gap_end--;

    buffer->data[buffer->gap_end] = buffer->data[buffer->gap_start];
}

void moveRight(GapBuffer *buffer) {
    if (buffer->gap_end == buffer->capacity){return;}

    buffer->data[buffer->gap_start] = buffer->data[buffer->gap_end];

    buffer->gap_start++;
    buffer->gap_end++;

}

void moveGapTo(GapBuffer *buffer, size_t target_index)
{
    if (buffer == NULL){return;}

    size_t buffer_length = getGapBufferLength(buffer);

    if (target_index > buffer_length){target_index = buffer_length;}

    if (target_index < buffer->gap_start)
    {
        size_t move_count = buffer->gap_start - target_index;

        memmove(
            buffer->data + buffer->gap_end - move_count,
            buffer->data + target_index,
            move_count
        );

        buffer->gap_start -= move_count;
        buffer->gap_end   -= move_count;
    }
    else if (target_index > buffer->gap_start)
    {
        size_t move_count = target_index - buffer->gap_start;

        memmove(
            buffer->data + buffer->gap_start,
            buffer->data + buffer->gap_end,
            move_count
        );

        buffer->gap_start += move_count;
        buffer->gap_end += move_count;
    }
}

void insertChar(GapBuffer *buffer, const char character)
{
}

void deleteChar(GapBuffer *buffer, const char character)
{
}


