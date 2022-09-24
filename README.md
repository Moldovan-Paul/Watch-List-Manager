# About this project

<p align="center">
<img src="https://user-images.githubusercontent.com/98110966/190877141-b0c40e76-982c-4907-a3b8-24127fcc6cbe.png" width="700" heigth="600">
</p>
  
# Overview

**Watch List Manager** is a desktop application that allows its user to create a local repository containing information about YouTube videos and create a watch list from it. It is written in **C++** and uses the **Qt** framework. This project was done as an assignment for university and should be treated as a display of the ability to juggle with **object-oriented programming concepts**, rather than as a tool that is innovative. I implemented a custom **dynamic vector** using the logic behind the *STL Vector* to better my knowledge of **data structures and algorithms**. **Unit tests** are performed for repository and service layers and for the custom dynamic vector.

FOR **VIDEO DEMONSTRATION** PLEASE REFER TO THE FOLLOWING ANCHORS:

[Adding, updating and deleting entries](#demo-1)

[Creating and viewing a watch list](#demo-2)

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

https://user-images.githubusercontent.com/98110966/190877257-4ec779be-f6da-41ae-a5bb-ef53c9953a66.mp4

# Creating a Watch List

In order to begin creating a watch list, the user must press the `Filter by presenter` button. If the text field next to this button is left empty, all tutorials will be played one by one. Otherwise, only tutorials corresponding to the given presenter will be shown.

After the user presses the button, the first suitable video will open in the **default browser**. At this point, the user can either choose to add the video to their watch list if they like it or to skip it. Subsequently the next video will open in the browser. 

Once the user is satisfied with their watch list, they can choose to view it by clicking the `See watchlist` button. At this stage, once the user has watched the first opened video, they can delete it from the watch list. Liking it is optional. By **liking** a video, the like count **will go up within the local repository**. Pressing `Next` will loop over the watch list until all videos are deleted.

### Demo #2

Here is a video demonstrating the functionalities mentioned above. The list of videos is filtered by a presenter; 4 of their videos are present in the local repository. Two of their C++ tutorials get added to the watch list. The user then chooses to view their watch list. The first video gets deleted and the second video gets deleted and liked. Subsequently, it can be observed that the second video's like count within the local repository went up by one.

https://user-images.githubusercontent.com/98110966/190877455-c4c487e6-2e84-4999-8e97-f1deced7af51.mp4

# Saving the Watch List

A watch list can be saved by pressing the `Save Watch List` button. A **csv/html** file will open containing information about the videos. Due to the nature of the implementation, the file type can only be chosen in code before starting the program (in `main.cpp` alternating between lines 15-19 and 20-24).

<img src="https://user-images.githubusercontent.com/98110966/190888568-8428efb0-f1f5-411b-ab3d-40bf797997e1.png" width="700" heigth="200">
<img src="https://user-images.githubusercontent.com/98110966/190888493-adb064d9-0a7e-4a72-9022-480277c59d73.png" width="700" heigth="200">
