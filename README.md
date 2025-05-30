WPI MQP Image Process Software Demo.

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
9. Image Enhancement
- Brightness: <br>Use the slider to control the brightness and display it on the feature properties.
- Contrast：<br>Use the slider to control the contrast and display it on the feature properties.
- Sharpness: <br>Use the slider to control the sharpness and display it on the feature properties.
- Histogram Equalization: <br>Use the slider to control the histogram equalization and display it on the feature properties.
- Noise Reduction: <br>Use the slider to control the noise reduction and display it on the feature properties.
- Gamma Correction: <br>Use the slider to control the Gamma correction and display it on the feature properties.
- Reset to Default: <br>This button is used to reset all the image enhancement features to default.
10. Region of Interest Analysis
