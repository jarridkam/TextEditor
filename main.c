#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "editor_inputs.h"
#include "page.h"

static int screen_width;
static int screen_height;

void SetScreen(const bool fullscreen)
{
    if (fullscreen)
    {
        screen_width = GetScreenWidth();
        screen_height = GetScreenHeight();
        return;
    }
    screen_width = 800;
    screen_height = 450;
}


int main(void)
{

    SetScreen(false);
    InitWindow(screen_width, screen_height, "Text Editor");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText(text_buffer, 190, 200, 20, LIGHTGRAY);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}

