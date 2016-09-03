import imutils
import numpy as np
import argparse
import cv2

# Construct the arguement parser
ap = argparse.ArgumentParser()
ap.add_argument("-v","--video", help = "path to the optional video file")
args = vars(ap.parse_args())

# define the upper and lower boundaries of the HSV pixel
# intensities to be considered 'skin'
lower = np.array([0, 48, 80], dtype = "uint8")
upper = np.array([20, 255, 255], dtype = "uint8")

# If a video path was not supplied, the web cam will be used
if not args.get("video", False):
    camera = cv2.VideoCapture(0)

# Otherwise, load the given video file
else:
    camera = cv2.VideoCapture(args["video"])

# Keep looping over the frames in the video
while True:
    # grab the current frame
    (grabbed, frame) = camera.read()

    # if we are viewing a video and we did not grab a frame, we have reached the end
    if args.get("video") and not grabbed:
        break
