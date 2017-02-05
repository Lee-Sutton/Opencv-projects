import cv2


class FaceDetector(object):
    """docstring for FaceDetector"""
    def __init__(self, faceCascadePath):
        self.faceCascade = cv2.CascadeClassifier(faceCascadePath)

    def detect(self, image, scaleFactor=1.1, minNeighbours=5, minsize=(30, 30):
        pass
