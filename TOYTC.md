# TOY
## Introduction
`TOY` is a basic `2D` game with terminal animation in `C` & `BGI`.<br>
By `@lxndroc` `'96`.
## Elements
`1` `keyboard-controlled humanoid`<br>
`1` `keyboard-controlled partner`<br>
`2` `mostly-randomly-moving monsters`<br>
`3` `floors`<br>
`1` `cage`<br>
`1` `cage key`<br>
`1` `key stand`<br>
`1` `ladder`<br>
`2` `touch-buttons`<br>
`1` `push-button`<br>
`1` `laser`<br>
`1` `exit`.
## Scenario
A partner of a humanoid is trapped in a cage and needs to be rescued by the humanoid.<br>
To win the game the player has to perform the following actions without being touched by a monster.
## Timeline
### Initial Stage
Middle and bottom floors, 1 humanoid and 1 monster on middle floor, 1 monster on bottom floor, 1 key stand, 2 touch-buttons.
### As Humanoid
`1.` Touch the 1st touch-button, middle of middle floor, to allow access to the bottom level and reveal the cage, right of top floor, and push button, left of bottom floor.<br>
`2.` Press the push-button to reveal the key of the cage, middle of top floor.<br>
`3.` Touch the 2nd touch-button, right of bottom floor, to reveal the trapped partner in the cage.<br>
`4.` Press the push-button to reveal the ladder, left of middle floor, to reach the key and the cage.<br>
`5.` Get the ladder from above.<br>
`6.` Place the ladder below the key.<br>
`7.` Climb the ladder.<br>
`8.` Get the key.<br>
`9.` Fall from the ladder.<br>
`10.` Get the ladder from the ground.<br>
`11.` Place the ladder below the cage.<br>
`12.` Climb the ladder.<br>
`13.` Free the partner, the laser appears.<br>
`14.` Fall together from the ladder, the exit appears.<br>
`15.` Touch the exit, the humanoid disappears.
### As Partner
`16.` Get the ladder from the ground.<br>
`17.` Touch the exit, the partner disappears and the game successfully ends.
## Game Controls
* `W`: Jumps above or climbs 1 ladder step.<br>
* `E`: Jumps above and right.<br>
* `A`: Moves 1 step left.<br>
* `S`: Swaps floor between middle and bottom or when applicable presses the push-button or gets the ladder from above or frees the partner.<br>
* `D`: Moves 1 step right.<br>
* `X`: Gets and places the ladder when on middle floor.
## Demo Game
![Demo Game](https://github.com/lxndroc/mini-projects/blob/main/TOY_demo.gif)
## Newer C++ Version & Graphics Files
[Pinecone](https://github.com/pinecone441248/pinecone-game/tree/main/ConsoleApplication1)
