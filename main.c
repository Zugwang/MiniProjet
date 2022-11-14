#include <stdio.h>
#include <string.h>
#include "main.h"
#include "raylib.h"


int main(void)
{
    // INIT 
    InitWindow(screenWidth, screenHeight, "Jeu de la vie");

    SetTargetFPS(60);


    // MAIN LOUPE 
    while (!WindowShouldClose()){

        mode = initMenu();
        //printf("mode = %d.\n",  modeJeu);
        printf("ouah");

        GameDrawUpdate(mode,etat);

        printf("oui");
    }


    // THIS IS THE END
    CloseWindow();        // Close window and OpenGL context

    return 0;
}

void ALL_DRAWING(GameScreen screen, int mode ,int cursorSelection, int etat[nbreCarreauX][nbreCarreauY] ){
    BeginDrawing();

    ClearBackground(RAYWHITE);

    switch (screen)
    {
    case MENU:
        DrawingMenu(cursorSelection, mode);
        break;
    
    case GAME:
        DrawingGame(mode,etat);
        break;
    }

    EndDrawing();
}

void GameDrawUpdate(modeDeJeu mode,int etat[nbreCarreauX][nbreCarreauY]){
    bool pause = false;
    bool endGame = false;

    printf("gen avant");
    premiereGen(etat, mode);

    printf("draw avant");
    ALL_DRAWING(GAME,mode,0,etat);
    printf("draw apres");



    // if(IsKeyPressed('P')){
    //     pause = !pause;
    //     DrawText("PAUSE", GetScreenWidth()/2 - MeasureText("PAUSE", 50)/2,250, 50, RED);
    // }

    while(!endGame){
        ALL_DRAWING(GAME,mode,0,etat);
        WaitTime(1);
        //UpdateGame(mode,etat);
    }


}


void UpdateGame(modeDeJeu mode,int etat[nbreCarreauX][nbreCarreauY]){
    etatsPossibles etat_nv[nbreCarreauX][nbreCarreauY];

    for(int i = 0 ; i < nbreCarreauX ; i ++ ){
        for(int j = 0 ; j < nbreCarreauY ; j ++ ){
            if(nbrevoisin(i,j,etat) == 2){
                etat_nv[i][j] = etat[i][j];
            }else if(nbrevoisin(i,j,etat) == 3) {
                etat_nv[i][j] = VIVANT1;
            }else{
                etat_nv[i][j] = MORT;
            }
        }
    }

    for(int i = 0 ; i < nbreCarreauX ; i ++ ){
        for(int j = 0 ; j < nbreCarreauY ; j ++ ){
            etat[i][j] = etat_nv[i][j];
        }
    }
}

void DrawingGame(modeDeJeu mode,int etat[nbreCarreauX][nbreCarreauY]){
    DrawRectangle(220,300, 100,100, RED);


    for(int i = 0 ; i < nbreCarreauX ; i ++ ){
        for(int j = 0 ; j < nbreCarreauY ; j ++ ){
            Color caseColor = RAYWHITE;
            if(etat[i][j] == VIVANT1) {Color caseColor = GREEN;}
            if(etat[i][j] == VIVANT2) {Color caseColor = BLUE;}
            if(etat[i][j] == VIVANT3) {Color caseColor = RED;}
            if(etat[i][j] == VIVANT4) {Color caseColor = YELLOW;}

            DrawRectangle(i*tailleCarreau, j*tailleCarreau, tailleCarreau, tailleCarreau, caseColor);
        }
    } 
}


void premiereGen(int etat[nbreCarreauX][nbreCarreauY], modeDeJeu mode){
    int nbreColonie = 1;

    if (mode == QUADLIFEmode){
        nbreColonie = 4;
    }


    for(int i = 0 ; i < nbreCarreauX ; i ++ ){
        for(int j = 0 ; j < nbreCarreauY ; j ++ ){
            etat[i][j] = GetRandomValue(0,nbreColonie);
        }
    }
}

int nbrevoisin(int x,int y, int etat[nbreCarreauX][nbreCarreauY]){
  int result = etat[x+1][y+1]
              +etat[x-1][y-1]
              +etat[x-1][y+1]
              +etat[x+1][y-1]
              +etat[x+1][y]
              +etat[x-1][y]
              +etat[x][y+1]
              +etat[x][y-1];
  return result;
}










modeDeJeu initMenu(){
    bool startGame = false;
    etatsPossibles etat[nbreCarreauX][nbreCarreauY];

    while(!startGame){
        UpdateMenu(&cursor, &mode, &startGame);
        ALL_DRAWING(MENU,mode,cursor,etat);
    }
    return mode;
}

void UpdateMenu(int *pCursorSelection, int *pMode, int *startGame){

    if (IsKeyPressed(KEY_UP)){
        //printf("hautavant = %d.\n", *pCursorSelection);
        if (*pCursorSelection > 0){
            (*pCursorSelection)--;
            //printf("hautapres = %d.\n", *pCursorSelection);
        }
    }

    if (IsKeyPressed(KEY_DOWN)){
        //printf("basavant = %d.\n", *pCursorSelection);
        if (*pCursorSelection < 4){
            (*pCursorSelection)++;
            //printf("basapres = %d.\n", *pCursorSelection);
        }
    }


    if(IsKeyPressed(KEY_ENTER)){
        if((*pCursorSelection) == PLAY){
            printf("espoir");
            *startGame = true;
            printf("espoir");
            return;
        }
 
        if(*pCursorSelection < PLAY){
            printf("avant%d \n", *pMode);
            *pMode = *pCursorSelection;
            printf("apres%d \n", *pMode);
        }
    }

}

void DrawingMenu(int cursorSelection, int mode){
    
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


}