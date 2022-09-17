# About this project

<img src="https://user-images.githubusercontent.com/98110966/190860424-0cbf0355-55e9-4576-a7f0-5cc5159e1051.png" width="600" heigth="600">

# Overview

**Watch List Manager** is a desktop app that allows its user to create a local repository containing information about Youtube videos and create a watch list from it. It is written in **C++** and uses the **Qt Framework**.

FOR **VIDEO DEMONSTRATION** PLEASE REFER TO THE FOLLOWING ANCHORS:

[Adding, updating and deleting entries](#demo-1)

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

# Creating a Watch List

In order to begin creating a watch list, the user must press the `Filter by presenter` button. If the text field next to this button is left empty, all tutorials will be played one by one. Otherwise, only tutorials corresponding to the given presenter will be shown.

After the user presses the button, the first suitable video will open in the **default browser**. At this point, the user can either choose to add the video to their watch list if they like it or to skip it. Subsequently the next video will open in the browser. 

Once the user is satisfied with their watch list, they can choose to view it by clicking the `See watchlist` button. At this stage, once the user has watched the first opened video, they can delete it from the watch list. Liking it is optional. By **liking** a video, the like count **will go up within the local repository**. Pressing `Next` will loop over the watch list until all videos are deleted.

### Demo #2

Here is a video demonstrating the functionalities mentioned above. The list of videos is filtered by a presenter which has 4 video tutorials within the local repository of the user. Two of their C++ Tutorials get added to the watch list. The user then chooses to see their watch list. The first video gets deleted and the second video gets deleted and liked. Subsequently, it can be observed that its like count within the local repository went up by one.
