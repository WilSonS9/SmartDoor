# SmartDoor.md

**Table of Contents**

- [SmartDoor.md](#smartdoormd)
- [Joel Detection](#joel-detection)
- [Lock](#lock)
  * [Wiring chart](#wiring-chart)
  * [Source for lock info](#source-for-lock-info)
  * [Needed hardware:](#needed-hardware)
  * [How it works](#how-it-works)
  * [Problems](#problems)
- [Keypad](#keypad)
  * [How it works](#how-it-works-1)
  * [Problems](#problems-1)

Joel Detection
=============

The door will be unlocked when it identifies Joel. To detect Joel, we chose to use the [YOLOv3](https://viso.ai/deep-learning/yolov3-overview/) object detection algorithm. The dataset we used was quite small, around 150 images, and can be found under AI/BBox-Label-Tool/Images/002, along with the YOLOv3 labels

### Data Collection and Labeling
The data was collected from an iPhone XR mobile phone by taking pictures of people, both Joel and Not Joel, and pictures with both so the model would be able to identify Joel even when standing next to a Not Joel. For a similar reason, the pictures were taken at different angles

To label the data, the [BBox-Label-Tool](https://github.com/Texas-Aerial-Robotics/BBox-Label-Tool) was used. To get it to work with several classes, [this guide](https://texas-aerial-robotics.github.io/md_yoloTraining.html) can be followed

Under AI/BBox-LabelTool/Scripts, the generated labels can be converted to YOLO format with the convert.py script. To split the dataset into a training set and a testing set, the script split.py can be used under AI/BBox-Label-Tool

### Training the Model
The model was trained on [this Google Colab](https://colab.research.google.com/drive/13rh1AUPfrwlVx9YtxmUFXum7xB3bGX1N#scrollTo=13fRzkiQiPhW) with [darknet](https://pjreddie.com/darknet/). How to train the model is described in the colab. I trained it for 700 iterations and extracted the tuned weights. To achieve higher accuracy, you might want to train it for longer or collecting a larger dataset

### Using the Model
To detect Joel and Not Joel, the script yoloCam.py under AI can be used. Simply put your yolov3.cfg, obj.names and yolov3_last_weights.weights in AI/joel. Make sure to rename the files to yolo.cfg, yolo.names and yolo.weights, otherwise the script will not work

The script uses [OpenCV](https://opencv.org/) to open the camera and detect Joel and Not Joel. To use the script, call it with `python yoloCam.py --yolo ./joel`. You can change the `--yolo` flag to point at your yolo folder if it is somewhere else

#### Communicating with NodeMCU
To communicate with the NodeMCU, the [MQTT](https://mqtt.org/) protocol is used. We set up an MQTT broker on [MaQiaTTo](https://maqiatto.com/), but any broker will do. To connect the yoloCam.py script with the MQTT broker, simply enter your own broker, port, topic, username and password at the top of the script. You can change the client_id as well if you want; what you change it to does not matter as long as all clients have unique ids, otherwise problems might appear.

# Lock

## Wiring chart
<img width="565" alt="image" src="https://user-images.githubusercontent.com/54657589/145534193-b66ee4db-8080-4c91-923e-e4ce8aba51d6.png">

## Source for lock info
https://www.ebay.com/itm/254421303433?hash=item3b3cb10089:g:0wwAAOSww5ZdzWt5 most info needed can easily be found on this web page so it is a recommended read if you want to use the lock.

## Needed hardware
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

