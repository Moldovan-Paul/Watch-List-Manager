# About this project

<img src="https://user-images.githubusercontent.com/98110966/190860424-0cbf0355-55e9-4576-a7f0-5cc5159e1051.png" width="600" heigth="600">

# Overview

**Watch List Manager** is a desktop app that allows its user to create a local repository containing information about Youtube videos and create a watch list from it. It is written in **C++** and uses the **Qt Framework**.

# Adding Videos

The user should provide the following information for each video:
* **Title**
* **Presenter** - the name of the content creator that made the video
* **Duration** - in minutes
* **Number of likes** - this can be left at 0 to create a local rating system if multiple users watch the video from the device
* **Link**

There are 2 ways of adding video information:

**1. Directly from the application**

Upon filling the fields with the aforementioned information, pressing the `Add` button will attach the video to the list.

**2. Adding them in the in.txt file**

Video information can be added directly to said file. These videos will be loaded upon opening the application.

Video information can also be **updated** by filling the fields and pressing the `Update` button. Entries can also be **deleted** by providing a title and pressing the `Delete` button.

**All changes made** will remain valid after the application is closed.

### Demo #1

Here is a video demonstrating the functionalities mentioned above. It shows a C++ Tutorial getting **added**, **updated** and then **deleted** from the list. All other videos were added through the `in.txt` file.




https://user-images.githubusercontent.com/98110966/190869491-f676e87b-2586-4271-a19b-792ec9d6ad36.mp4


