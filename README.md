# College Pong

This is a silly game I made for the final in my Object Oriented Programming class in college. It utilizes OpenGL with FreeGLUT. The graphics are crude and there are admittedly a few bugs here and there. The main point of the project was to demonstrate proper use and structuring of Object Oriented Programming concepts. 

## Installation
## Windows Users

This project can only run in your Linux subsystem (Ubuntu Shell), not natively in Windows.

- Update your apt repositories: `sudo apt update`
- Install freeglut: `sudo apt install freeglut3-dev`
- Install xming (https://sourceforge.net/projects/xming/)
- Set display environment variable: `echo "export DISPLAY=localhost:0.0" >> ~/.bashrc`
- Relaunch your VS Code

## Linux Users

If you are running Linux natively (not the Ubuntu Shell under Windows)

- Update your apt repositories: `sudo apt update`
- Install freeglut: `sudo apt install freeglut3-dev`

## Mac Users

On a Mac, the project just works


# Running the App

After all dependencies above have been installed, navigate to the project folder and:

- Compile: `make`

- Run: `./glutapp`

## How to play

The game kind of works like beer pong but much more simple. There is a cpu opponent that you play against. The goal of the game is to throw the ball into every cup on the opponent's side before they do the same to your cups. When you hit a cup you get a free shot. If you're skilled enough you can win the game in 1 turn. There is no re-racking of cups.
#### To throw the ball
Hold down the left mouse button and a power bar will charge up next to your cursor. It will oscillate back and forth until you release the left mouse button at which point the ball will be launched at that power level.