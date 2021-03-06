# Filler

    	This is a game, where two players / algorithm are fighting on a map.

The goal of the project is to create your player program to compete against other students on the famous (or not) Filler board. 
The principle is simple: two players take on each other on a board, and take turns placing the piece that the master of the game (supplied in the form of a Ruby executable) gives them, earning points. The game stops as soon as a piece can no longer be placed.

   ## How the game works:
   • At each turn, the filler will send the updated map and a new token to the player concerned.
   • The player concerned will write on the standard output his or her piece’s coordinates to place it on the board.
   • The filler will send the map and a new piece to the other player.
   
  ### Here is an example on how a game will roll out in terminal.
  ![](https://github.com/vlkorniienko/Filler/blob/master/example.png)
 
  ### Usage:
![](https://github.com/vlkorniienko/Filler/blob/master/Usage.png)

Also I made a graphic visualization for this game using MLX graphic library. To open it you need to:
```
cd visualization
make
cd ..
./filler_vm -f resources/maps/map01 -p1 ./vkorniie.filler -p2 resources/players/abanlin.filler | ./visualization/vkorniie.visual
```

### Game example
![](https://github.com/vlkorniienko/Filler/blob/master/visual.png)
