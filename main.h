#pragma once

#include <stdio.h>

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
    DOOMmde
} modeDeJeu;

typedef enum cursorPossible
{
    GAMEOFLIFE,
    QUADLIFE,
    DOOM,
    PLAY,
    SETTING

} cursorPossible;



void initMenu();

void DrawingMenu(int cursorSelection, int mode);

void UpdateMenu