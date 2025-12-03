Lane Dodger Game 
This project is a simple console-based *lane dodging game* made using C. The player controls a character at the bottom of the screen and must dodge falling obstacles. The game includes *score tracking* and *increasing speed*, making it fun and progressively challenging.


# Game Overview

* The player (V) can move *left, **middle, or **right* using the *arrow keys*.
* An obstacle (X) falls from the top.
* If the obstacle reaches the bottom lane *in the same position as the player*, the game ends.
* Every time the player successfully dodges an obstacle, the *score increases*.
* Speed increases after every 5 points, making the game harder.
* The player can press *Q* anytime to quit.

#Features

* Smooth lane movement using arrow keys
* Falling obstacle animation
* Game Over detection
* Score counter
* Increasing difficulty (speed boost)
* Quit option (Q key)
* Fully console-based — ideal for beginner projects


# Code Explanation


# 1. Variables Used

* x → Player lane (0 = left, 1 = mid, 2 = right)
* step → Obstacle vertical position (0–9)
* obstaclePos → Obstacle lane (0,1,2)
* score → Counts successful dodges
* speed → Controls falling speed using Sleep()


# 2. Player Input (Movement)

The game checks for user input using _kbhit() and getch():

* (Left Arrow) → Move left if possible
* (Right Arrow) → Move right if possible
* (Q/q) → Quit instantly

This allows movement without stopping the game loop.


# 3. Obstacle Logic

* A random lane (0 to 2) is generated.
* Obstacle moves downward each frame.
* When it reaches the bottom and does *not* hit the player:

  * Score increases
  * Speed reduces slightly (faster falling)


# 4. *Collision Detection*

Collision happens when:


step == 9 and x == obstaclePos


Meaning the obstacle has reached the last row and the player is in the same lane.
Then the game ends with a *GAME OVER* message.



# 5. Game Speed Increase

Every time score is divisible by 5:


if (score % 5 == 0 && speed > 30)
    speed -= 5;


This slowly makes the game more difficult.


# Game Layout Example


|--- --- ---|    Score: 3
|     X     |
|           |
|           |
|           |
|           |
|           |
|           |
|           |
|           |
|           |
|     V     |


X = Obstacle
V = Player

---

# Requirements

* Windows OS (because of <conio.h> and Sleep())
* Any C compiler (Dev-C++, GCC, CodeBlocks, etc.)


#  Learning Outcomes

By making this project, you learn:

* Real-time input handling using _kbhit() and getch()
* Console rendering with system("cls")
* Random obstacle generation with rand()
* Basic 2D game logic
* Increasing difficulty mechanics
* Frame timing using Sleep()

#  Conclusion

This game is simple, fun, and teaches important game development logic in C. The added *score counter* and *speed increase* make the gameplay engaging and challenging.