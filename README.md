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

## How to Install and Run the Code
1. Clone the [Paintball Enviro Project GitHub] (https://github.com/nnooriuw/paintball_enviro_project.git) repository

## Acknowledgements
The goal of the Final Project is to utilize the (https://github.com/klavinslab/enviro.git "Enviro") repository made by Dr. Eric Klavins (University of Washington Department of Electrical and Computer Engineering Professor). 
ENVIRO is The multi-agent, multi-user, multi-everything simulator.
