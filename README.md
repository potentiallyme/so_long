# SO_LONG  
## Creating a 2D game  
  
Welcome to my game for the so_long project at 42!  
Solve the mazes, create your own, and don´t get tricked by the unique movement!  
  
This project uses the MinilibX, a simple X-Window programming API in C to render our game, thus it is recommended to use a MAC or LINUX machine to compile the game.  
  
  
### MAP CREATION
  
You can create your own map! However, it must fit the following criteria:  
1. The map contains ONE player character 'P'
2. The map is square/rectangular and is closed
3. The map contains ONE EXIT 'E'
4. The map contains at LEAST ONE collectible 'C'
5. The map has to be solvable (player can reach the exit after collecting all the collectibles)  
  
<pre>
  111111111
  1P0000011
  111111C11
  100000011
  100000111
  1101101E1
  100000001
  111111111
</pre>
This map works.  
  
<pre>
  111111111
  1P0000011
  111111C11
  100000011
  100000011
  1101101E1
  100000001
  111111111
</pre>
This map doesn't work (subtle!)  
  
I <em>highly</em> suggest you play my maps first and get a grip on how the game works before creating your own map, it's very specific!  
Tap 'I' in game to get a rundown on how to play :)  
Hope you enjoy!     
  
The sprites are heavily inspired by Tomb of the Mask.  
