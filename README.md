# Game Aliens for C++ course at MIPT
This is my project for C++ course. Some screenshots:  
![alt text](https://raw.githubusercontent.com/malmakova-na/alien_game_cpp/master/screenshots/screen1.png) ![alt text](https://raw.githubusercontent.com/malmakova-na/alien_game_cpp/master/screenshots/screen2.png)  
## How to play
You need to blow up the planets by pushing them into black holes. Use arrows to move alien dude. Press "R" for restart level, press space to make the alien start to move randomly.
## How to install on Linux
Firstly you need to install SFML library:  
```
sudo apt-get install libsfml-dev
```
Then compile:
```
g++ run.cpp Game.cpp Map.cpp Cell.cpp -o run -lsfml-graphics -lsfml-window -lsfml-system
```
And run:
```
./run
```
Enjoy!