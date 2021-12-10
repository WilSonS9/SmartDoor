# SmartDoor.md

**Table of Contents**

- [AI.md](#aimd)
- [Joel Detection](#joel-detection)
    + [Data Collection and Labeling](#data-collection-and-labeling)
    + [Training the Model](#training-the-model)
    + [Using the Model](#using-the-model)
      - [Communicating with NodeMCU](#communicating-with-nodemcu)

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
