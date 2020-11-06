# Cat Memory 

## Members

Alexander Brenner mr20b003   
Lucas Schmirl mr19b072   
Fabian Mühlberger mr19b068   


## Abstract

We create 2 programs, a server and a client communicating via tcp. 
The Client program has a visual representation of a Memory game on the console and can choose one card by entering `[x]` and `[y]` coordinates in the terminal. When the user flips one card, the server hands back a asci graphic of the card. 

## Playing the game 

The player can choose and flip one card to show its contents. 
The server hands over a asci graphic of the card. When a match is found, the board is marked with an `x` to represent a flipped card.

1. Choose card [x | y]
   
      1  2  2  3  4  
   a [] [] [] [] []  
   b [] [] [] [] []

2. Server checks the card and hands back the asci grapic

    [ PICTURE ]

3. User chooses a second card 

4. Server sends back the second graphic

5. If both cards have the same Picture, the player resceives the original picture from the server, and the cards will be marked as correkt 

6. repeat till all cards are flipped.

## Protocol

TCP Sockets to establish a connection from client to server.


