#include "editor_inputs.h"
#include "raylib/src/raylib.h"

void insert_character() {

}

void CheckInputs(char* buffer, float delta_time)
{
    static int buffer_length = 0;

    static float backspace_hold_time = 0.0f;
    static float backspace_repeat_delay = 0.10f;
    static float backspace_initial_delay = 0.35f;
    static bool backspace_started = false;

    int key;

    while ((key = GetCharPressed()) > 0)
    {
        buffer[buffer_length++] = (char)key;
        buffer[buffer_length] = '\0';
    }


    if (IsKeyPressed(KEY_BACKSPACE) && buffer_length > 0)
    {
        buffer[--buffer_length] = '\0';
        backspace_hold_time = 0.0f;
        backspace_started = 0;
    }


    if (IsKeyDown(KEY_BACKSPACE) && buffer_length > 0)
    {
        backspace_hold_time += delta_time;

        float threshold;
        if (!backspace_started){threshold = backspace_initial_delay;}
        else{threshold = backspace_repeat_delay;}

        if (backspace_hold_time >= threshold)
        {
            buffer[--buffer_length] = '\0';
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