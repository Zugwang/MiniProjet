#include <stdio.h>
#include <string.h>
#include "main.h"
#include "raylib.h"


static const int screenWidth = 800;
static const int screenHeight = 450;


int main(void)
{
    // INIT 
    InitWindow(screenWidth, screenHeight, "raylib [core] example - keyboard input");

    SetTargetFPS(60);

    // MAIN LOUPE 
    while (!WindowShouldClose()){


        initMenu();
    }


    // THIS IS THE END
    CloseWindow();        // Close window and OpenGL context

    return 0;
}


void initMenu(){

    modeDeJeu mode = GAMEOFLIFEmode;
    cursorPossible cursor = PLAY;
    bool startGame = false;
    printf("cursor2 = %d.\n", cursor);

    while(!startGame){

        UpdateMenu(&cursor, &mode, &startGame);
        printf("updatemode %d \n",mode);
        DrawingMenu(cursor, mode);

    }

}

void UpdateMenu(int *pCursorSelection, int *pMode, int *startGame){

    if (IsKeyPressed(KEY_UP)){
        printf("hautavant = %d.\n", *pCursorSelection);
        if (*pCursorSelection > 0){
            (*pCursorSelection)--;
            printf("hautapres = %d.\n", *pCursorSelection);
        }
    }

    if (IsKeyPressed(KEY_DOWN)){
        printf("basavant = %d.\n", *pCursorSelection);
        if (*pCursorSelection < 4){
            (*pCursorSelection)++;
            printf("basapres = %d.\n", *pCursorSelection);
        }
    }


    if(IsKeyPressed(KEY_ENTER)){
        if(*pCursorSelection == PLAY){
            *startGame = true;
        }
 
        if(*pCursorSelection < PLAY){
            *pMode = *pCursorSelection;

        }
    }

}

void DrawingMenu(int cursorSelection, int mode){
    BeginDrawing();
        ClearBackground(RAYWHITE);

        for (int i = 0 ; i < PLAY ; i++){
            Color rectColor = DARKGRAY;
            if ( (mode == i ) && (mode <= DOOMmode)){
                rectColor = GRAY;
            }
            DrawRectangle(10, 10+(i*60), 200, 30, rectColor);
            if ( (cursorSelection == i) && (cursorSelection <= DOOMmode) ){
                DrawRectangle(15, 15+(i*60), 20, 20, RED);
            }

            if (cursorSelection == PLAY){
                DrawRectangle(GetScreenWidth()/2 - MeasureText("JOUER", 50)/2,300, MeasureText("JOUER", 50),5, RED);
            }
        }

        DrawText("Jeu De la vie", 45, 15, 20, RAYWHITE);
        DrawText("QuadLife", 45, 75, 20, RAYWHITE);
        DrawText("Doom", 45, 135, 20, RAYWHITE);



        DrawText("JOUER", GetScreenWidth()/2 - MeasureText("JOUER", 50)/2,250, 50, RED);



    EndDrawing();
}