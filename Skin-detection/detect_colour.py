# Import packages
import numpy as np
import argparse
import cv2

# Construct the ArgumentParser
ap = argparse.ArgumentParser()
ap.add_argument("-i","--image", help = "path to the image")
args = vars(ap.parse_args)

# load the image
image = cv2.imread(args["image"])
