# Keypad

![image](https://user-images.githubusercontent.com/57352823/145535302-554bbb52-d770-45b2-a8c7-0b1aa909c2e3.png)

When creating the project, we decided we needed a keypad if the facial recognition software didn't work, or if you needed to unlock the door for other purposes. 
The picture above is the model we chose. 

## How it works

This is a matrix array keypad, which means that it works by a grid of 4 rows and 4 columns, which activate when a button is pressed. You can then figure out which button that has been pressed by matching the activated row with the activated column. In code, this was done by looping through each column, checking if it was activated, and then if it was, checking every row in that column to find the index of both the row and the column, which then can be used to retrive the corresponding character by using an array as pictured below.

![image](https://user-images.githubusercontent.com/57352823/145537888-3165a114-9a03-4b92-bc5f-cb298ca0a149.png)

## Problems

The first problem that had to be solved was how to wire the keypad. The keypad uses 8 digital pins, 4 rows on/off and 4 columns on/off. The chart below was used extensively to make sure i had the right pins. 

![MicrosoftTeams-image (2)](https://user-images.githubusercontent.com/57352823/145536715-0b5b4f8b-40fe-4257-9c18-3808bfcf48bd.png)

Once that was solved, I tested the keypad rigourously to find out how to use it in an effective way, and reached the conclusion that the signals were low when the button was pressed, which was contrary to what i believed and a giant point of frustration for me when testing and trying to figure out how to use the keypad. After that i had real trouble figuring out how arrays worked in arduino and in the end, it meant that i could not finish the keypad. The function it has now is that it can print whatever key you press, which to me meant progress no matter if i completed the system. I was also sick 1/3 of the assigned project time and did not have the time to finish this. 
