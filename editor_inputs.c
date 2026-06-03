#include "editor_inputs.h"
#include "raylib/src/raylib.h"

static int key;
static float backspace_hold_time = 0.0f;
static float backspace_repeat_delay = 0.10f;
static float backspace_initial_delay = 0.35f;
static bool backspace_started = false;


void insert_character(GapBuffer *buffer) {
    while ((key = GetCharPressed()) > 0)
    {
        insertChar(buffer, (char)key);
    }
}
void remove_character(GapBuffer* buffer) {
    if (IsKeyPressed(KEY_BACKSPACE) && getGapBufferLength(buffer) > 0)
    {
        deleteChar(buffer);
        backspace_hold_time = 0.0f;
        backspace_started = false;
    }


    if (IsKeyDown(KEY_BACKSPACE) && getGapBufferLength(buffer) > 0)
    {
        backspace_hold_time += GetFrameTime();

        float threshold;
        if (!backspace_started){threshold = backspace_initial_delay;}
        else{threshold = backspace_repeat_delay;}

        if (backspace_hold_time >= threshold)
        {
            deleteChar(buffer);
            backspace_hold_time = 0.0f;
            backspace_started = true;
        }
    }
    else
    {
        backspace_hold_time = 0.0f;
        backspace_started = false;
    }
}

void CheckInputs(GapBuffer *buffer) {
    insert_character(buffer);
    remove_character(buffer);
}
