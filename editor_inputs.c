#include "editor_inputs.h"
#include "raylib/src/raylib.h"

static int key;
static int buffer_length = 0;
static float backspace_hold_time = 0.0f;
static float backspace_repeat_delay = 0.10f;
static float backspace_initial_delay = 0.35f;
static bool backspace_started = false;

void insert_character() {
    while ((key = GetCharPressed()) > 0)
    {
        text_buffer[buffer_length++] = (char)key;
        text_buffer[buffer_length] = '\0';
    }
}
void remove_character() {
    if (IsKeyPressed(KEY_BACKSPACE) && buffer_length > 0)
    {
        text_buffer[--buffer_length] = '\0';
        backspace_hold_time = 0.0f;
        backspace_started = false;
    }


    if (IsKeyDown(KEY_BACKSPACE) && buffer_length > 0)
    {
        backspace_hold_time += GetFrameTime();

        float threshold;
        if (!backspace_started){threshold = backspace_initial_delay;}
        else{threshold = backspace_repeat_delay;}

        if (backspace_hold_time >= threshold)
        {
            text_buffer[--buffer_length] = '\0';
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

void CheckInputs() {
    insert_character();
    remove_character();
}
