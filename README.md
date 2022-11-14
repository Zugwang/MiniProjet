# Description du projet
- quel jeu a été modifié / étendu ou réalisé ?

j'ai essayé de mettre une interface graphique sur un jeu de la vie avec un menu et des parametres
c'est un jeu que j'ai déja codé auparavant disponible sur mon git
j'avais auparavant utilisé sfml pour la partie graphique 

- quelle(s) modifications, ... ?

en me renseignant sur les automates cellulaires j'ai eu envie de reprendre et d'implémenter QuadLife une variante permettant d'observer différentes populations entre elles.

# Comment compiler
cc main.c `pkg-config --libs --cflags raylib` -o main.o
# Comment exécuter
./main.o

ou run.sh 

# Comment utiliser le projet
Seul le menu fonctionne, j'ai de gros problème pour généraliser l'affichage malgrès l'inspiration de basic_screen_manager (raylib doc)

# URL vidéo de démo
Le projet n'etant pas fonctionnel, il n'existe pour l'instant pas de video

Par contre j'ai fait un document expliquant les majeurs difficultés rencontrés

https://shaded-mall-a2e.notion.site/Jeu-de-la-vie-7f7a604cb1ef4a23952bb98972e6886b

