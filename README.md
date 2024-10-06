WPI MQP Image Process Software Initial Version. This project is a basic YUV video player with OpenGL rendering. The current UI is very simple and rough (and ugly :)) and will be gradually improved over the vacations.

Basic Development Information
-
1. Language: C++
2. Application：QT creator. 
3. Version: Qt 6.7.2 (MSVC 2019, x86_64). Built on Aug 6 2024 00:17:40. (not the LST one)

Currently Implemented Features
-
1. YUV to Video Conversion: <br>The player can load YUV data and convert it into video using OpenGL for rendering.
2. Start Button: <br>Click this button to initiate video playback or replay the current video.
3. Play/Pause Button: <br>This button is used to control the playback and pause of the video.
4. Zoom In/Zoom Out Button: <br>This buttons are used to zoom in and zoom out the video (window adaption problems remaining).
5. ScreenShoot Button: <br>This button is used to save the YUV file of the current image.
6. Recording Button: <br>This button is used to save the YUV file of the recording. Clicking this button for the first time will start the recording, clicking it again or the video playback will stop the recording.
7. Video Resolution: <br>The default video resolution is 176x144, but this can be adjusted as needed.
8. Frame Rate: <br>The current frame rate is 30 FPS, which can also be modified if necessary.

Future Improvements
-
1. UI Optimization: <br>The user interface will be redesigned and optimized in future versions to enhance the overall user experience.
2. Board Testing: <br>Once the hardware board is successfully set up, we will test the data directly from the board.
3. RGB Data Support: <br>Will convert RGB data into video if needed.
4. Feature Prioritization: <br>If any key features are identified, we will work on them earlier.

Challenges
-
1. Window adaption is difficult to achieve.
2. How to configure files on different computers.
