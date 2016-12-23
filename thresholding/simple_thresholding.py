import numpy as np
import cv2
import argparse

# Parse our arguments for the image to be passed in
ap = argparse.ArgumentParser()
ap.add_argument('-i', '--image', required=True,
               help="Path to image")
args = vars(ap.parse_args())

image = cv2.imread(args["image"])
image = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
blurred = cv2.GaussianBlur(image, (5, 5), 0)
cv2.imshow('image', image)

# Run threshold on the image based on a threshold value of 155
(T, thresh) = cv2.threshold(blurred, 155, 255, cv2.THRESH_BINARY)
cv2.imshow('Binary Threshold', thresh)

# Run a binary threshold to see the original image of the coins
(T, threshinv) = cv2.threshold(blurred, 155, 255, cv2.THRESH_BINARY_INV)
cv2.imshow('Inverse threshold', threshinv)
cv2.imshow('coins', cv2.bitwise_and(image, image, mask=threshinv))
cv2.waitKey(0)
