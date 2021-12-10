# SmartDoor

Table of Contents

[TOC]

Joel Detection
The door will be unlocked when it identifies Joel. To detect Joel, we chose to use the YOLOv3 object detection algorithm. The dataset we used was quite small, around 150 images, and can be found under AI/BBox-Label-Tool/Images/002, along with the YOLOv3 labels

###Data Collection and Labeling The data was collected from an iPhone XR mobile phone by taking pictures of people, both Joel and Not Joel, and pictures with both so the model would be able to identify Joel even when standing next to a Not Joel. For a similar reason, the pictures were taken at different angles

To label the data, the BBox-Label-Tool was used. To get it to work with several classes, this guide can be followed

Under AI/BBox-LabelTool/Scripts, the generated labels can be converted to YOLO format with the convert.py script. To split the dataset into a training set and a testing set, the script split.py can be used under AI/BBox-Label-Tool

###Training the Model The model was trained on this Google Colab with darknet. How to train the model is described in the colab. I trained it for 700 iterations and extracted the tuned weights. To achieve higher accuracy, you might want to train it for longer or collecting a larger dataset

###Using the Model To detect Joel and Not Joel, the script yoloCam.py under AI can be used. Simply put your yolov3.cfg, obj.names and yolov3_last_weights.weights in AI/joel. Make sure to rename the files to yolo.cfg, yolo.names and yolo.weights, otherwise the script will not work

The script uses OpenCV to open the camera and detect Joel and Not Joel. To use the script, call it with python yoloCam.py --yolo ./joel. You can change the --yolo flag to point at your yolo folder if it is somewhere else

####Communicating with NodeMCU To communicate with the NodeMCU, the MQTT protocol is used. We set up an MQTT broker on MaQiaTTo, but any broker will do. To connect the yoloCam.py script with the MQTT broker, simply enter your own broker, port, topic, username and password at the top of the script. You can change the client_id as well if you want; what you change it to does not matter as long as all clients have unique ids, otherwise problems might appear.
