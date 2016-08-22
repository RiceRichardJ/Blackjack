APPROACH TO SOLVING PROBLEM

0. Read the spec first.

1. First I had to get familiar with the basics of Visual Studio. Solutions, projects, creating classes, etc. Also learning how to read errors in Visual Studio.

2. Next I had to brush up on my C++ skills, such as vectors, and how linking works with #pragma once, etc. This was kind of confusing because I had tried using the "#ifndef FILE_H_" style of header guards I had done before and it wasn't working.

3. I haven't actually played Blackjack before, so I had to get a feel for how the game works. I played a version online here http://www.247blackjack.com/. I wrote out the steps the player would take in the game so I would know what functions to create. 

4. Created the Card class and tested it's ability to store and print suit/values. Stores suits and values incase it's reused elsewhere. Values are filled with their defaults for face cards (11, 12, 13). The blackjack file is responsible for overriding facecard values with 10s.

5. Created the Deck class which wraps a vector of Cards. Tested its ability to shuffle and deal. It also takes Card Vectors as hands.

6. With the Card and Deck tested and working, I started building the game logic, in three sections: the first four cards dealt, then the player's choice to hit or stand, then the AI's choice to hit or stand. Tested as I went. Used helpers for reading and writing from console since the default way seems messy.

7. Tested game, plays well. Formatted the console prints. Cleaned up the code and added comments.

8. Learned how to create and import DLLs, which was kind of confusing. Used this tutorial https://msdn.microsoft.com/en-us/library/ms235636.aspx

9. Refactored main game into its own class instead of just a bunch of functions.

10. Used Visual Studio to create UML diagrams.

11. Tried to connect Visual Studio to my GitHub though TeamExplorer, but it didn't work so I used the GitHub GUI program. You should be able to find it here: https://github.com/RiceRichardJ/Blackjack

12. Updated this Readme file. Removed unnecessary files to reduce size, removed debug and exe files to allow this project to be zipped and sent through email.

This project was created in Visual Studio 2013.

To compile: Open up the BlackjackTestRVT.sln solution file in Visual Studio, and build the BlackjackGame and DeckLib projects. Pressing Ctrl+F5 should run it hopefully.