# Lock

## Wiring chart
<img width="565" alt="image" src="https://user-images.githubusercontent.com/54657589/145534193-b66ee4db-8080-4c91-923e-e4ce8aba51d6.png">

## Source for lock info
https://www.ebay.com/itm/254421303433?hash=item3b3cb10089:g:0wwAAOSww5ZdzWt5

## Needed hardware:
* node mcu * 1
* electric solenoid lock * 1
* transistor * 1
* Diode * 1
* 12 V 2 A source * 1
* 3.3 V source

## How it works
The lock works by producing magnetism by electricity which then causes the lock to attract/unlock when electricity is supplied and lock when it is not. The lock needs
12V and 2A to work properly and if the lock is unlocked for more than 5 seconds it will be damaged.

## Problems
Figuring what the different wires of the lock did until I found the source above in the source subchapter. Replacing the relay with a diode and transistor and lastly connecting 
the right pins to what was written in the code since the code had different pin numbers than the node mcu for the same pin.


