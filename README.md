# Paintball Enviro Project
Final Project for EEP520-W20

## Overview/Goal
The objective is to demonstrate knowledge and usage of C++, including classes and event handlers.

## Challenges
The biggest challenge was updating the player scores'. In the bullet classes, an event emit and flag is set when a bullet collision with the opposing player is noticed. In the player classes, the event emits are watched for and a flag is set to increment the player score.

### Future Work
#### Score Counter
At the point of this commit to the repo, the score counter does not work. It increments tick by tick until the bullet times out, or is removed by colliding with the opposing player or opposing player's bullets. The score counters need to be corrected to increment only when a collision with the opposing player is detected. 
#### Multiplayer over seperate Web Browsers
Future implementation can be made to integrate the game such that it can be played between players on different Web Browsers. This will allow ease of play, as currently the game is only playable on a single Web Browser; the players need to share the keyboard which can be cumbersome.
#### Ending the Game
At this time, the game has no "end". Future implementation can be made to end the game once a certain time limit is reached, or a certain score by a player is reached first.

## How to Install and Run the Code
1. Clone the [Paintball Enviro Project GitHub](https://github.com/nnooriuw/paintball_enviro_project.git) repository.
2. Using the terminal, cd into the `/paintball_enviro_project/` directory
3. Using the terminal, run the following docker image `docker run -p80:80 -p8765:8765 -v $PWD:/source -it klavins/enviro:v1.61 bash`
4. Using the terminal, run the command `esm start`
5. Using the terminal, run the command `make`
6. Using the terminal, run the command `enviro`
7. Using a Web Browser, navigate to `http://localhost`
8. Paintball should now have started in your Web Browser.
9. You can press `Ctrl-C` at the `bash` interface to stop the enviro server.

## How to Play
Paintball is a 2 Player game, in which the two players fire "Paintball" bullets at each other.
Player 1's player model plays on the top of the screen.
Player 2's player model plays on the bottom of the screen.
Player 1 uses `a` and `d` to move left and right, respectively.
Player 1 uses `Space` to fire bullets.
Player 2 uses `LeftArrow` and `RightArrow` to move left and right, respectively.
Player 2 uses `Shift` to fire bullets.
### Game Objective
Players must fire paintball bullets at the opposing player. Incoming paintball bullets can either dodged by moving, or destroyed by shooting the opposing players incoming bullets. Score is kept track by how many times a player's bullets collided with the opposing player model.

## Acknowledgements
The goal of the Final Project is to utilize the [Enviro](https://github.com/klavinslab/enviro.git) repository made by Dr. Eric Klavins (University of Washington Department of Electrical and Computer Engineering Professor). 
ENVIRO is The multi-agent, multi-user, multi-everything simulator.
Enviro also builds upon [Elma](https://github.com/klavinslab/elma.git), which is an event loop and process manager for embedded and reactive systems, also developed by Dr. Klavins.
Paintball was built upon utilizing the Enviro examples provided by Dr. Klavins.