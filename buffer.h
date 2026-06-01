//
// Created by Jarrid on 4/18/2026.
//

#ifndef GAP_BUFFER_H
#define GAP_BUFFER_H

#include <stddef.h>
#include <stdbool.h>

typedef struct
{
    char *data;

    size_t capacity;

    size_t gap_start;
    size_t gap_end;
} GapBuffer;

bool createGapBuffer (GapBuffer *buffer, size_t initial_capacity);
void destroyGapBuffer(GapBuffer *buffer);

size_t getGapBufferLength(const GapBuffer *buffer);
size_t getGapSize        (const GapBuffer *buffer);

void moveLeft  (GapBuffer *buffer);
void moveRight (GapBuffer *buffer);
void moveGapTo (GapBuffer *buffer, size_t target_index);
void insertChar(GapBuffer *buffer, char character);
void deleteChar(GapBuffer *buffer, char character);

#endif //TEXTEDITOR_BUFFER_H