#pragma once

#include <stdio.h>
#include <string.h>

typedef enum etatsPossibles
{
    MORT,
    VIVANT1,
    VIVANT2,
    VIVANT3,
    VIVANT4
} etatsPossibles;

typedef enum modeDeJeu
{
    GAMEOFLIFEmode,
    QUADLIFEmode,
    DOOMmode
} modeDeJeu;

typedef enum cursorPossible
{
    GAMEOFLIFE,
    QUADLIFE,
    DOOM,
    PLAY,
    SETTING

} cursorPossible;



modeDeJeu initMenu();

void DrawingMenu(int cursorSelection, int mode);

void UpdateMenu(int *pCursorSelection, int *pMode, int *startGame);