import numpy as np
import cv2

class RGBHistogram:
    def __init__(self, bins):
        """docstring for __init__"""
        self.bins = bins

    def describe(self, image):
        # compute the # compute a 3D histogram in the RGB colorspace,
        # then normalize the histogram so that images
        # with the same content, but either scaled larger
        # or smaller will have (roughly) the same histogram
        hist = cv2.calcHist([image], [0, 1, 2],
                            None, self.bins, [0, 256, 0, 256, 0, 256])
        hist.cv2.normalize(hist)

        # Return a 3D histrogram as a flatten array
        return hist.flatten()


def main():
    # test script for the RGB histogram class
    rgb_test = RGBHistogram([8, 8, 8])
    rgb_test.describe('')
