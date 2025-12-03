#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand((unsigned)time(NULL));

    int x = 1;                   // 0 = left, 1 = mid, 2 = right
    int step = 0;                // vertical position of obstacle (0..9)
    int obstaclePos = rand() % 3;
    int score = 0;
    int speed = 120;             // milliseconds for Sleep()

    while (1) {

        // ---- INPUT ----
        if (_kbhit()) {
            int ch = getch();
            if (ch == 0 || ch == 224)
                ch = getch();

            if (ch == 75 && x > 0)      
                x--;
            else if (ch == 77 && x < 2) 
                x++;
            else if (ch == 'q' || ch == 'Q') { 
                system("cls");
                printf("Quit. Final score: %d\n", score);
                break;
            }
        }

        // ---- COLLISION CHECK ----
        if (step == 9 && x == obstaclePos) {
            system("cls");
            printf("|--- --- ---|\n");
            for (int i = 0; i < 10; i++) printf("|           |\n");
            printf("|     V     |\n\n");
            printf("GAME OVER! Score: %d\n", score);
            break;
        }

        // ---- DRAW ----
        system("cls");
        printf("|--- --- ---|    Score: %d    (Press Q to Quit)\n", score);

        for (int i = 0; i < 10; i++) {
            if (i == step) {
                if (obstaclePos == 0)      printf("| X         |\n");
                else if (obstaclePos == 1) printf("|     X     |\n");
                else                       printf("|         X |\n");
            }
            else {
                printf("|           |\n");
            }
        }

        // ---- PLAYER ----
        if (x == 0)      printf("| V         |\n");
        else if (x == 1) printf("|     V     |\n");
        else             printf("|         V |\n");

        // ---- FRAME PAUSE ----
        Sleep(speed);

        // Move obstacle down
        step++;

        // Reset when reaches bottom
        if (step > 9) {
            step = 0;
            obstaclePos = rand() % 3;
            score++;

            if (score % 5 == 0 && speed > 30){ 
                speed -= 5;
            }
        }
    }
    return 0;
}
