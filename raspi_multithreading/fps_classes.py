import datetime
from threading import Thread
import cv2

class FPS:
    def __init__(self):
        # Store the start time, end time and total number of frames
        # that were examined between the start and end intervals
        self._start = None
        self._end = None
        self._numFrames = 0

    def start(self):
        # Start the timer
        self._start = datetime.datetime.now()
        return self

    def stop(self):
        # Stop the timer
        self._end = datetime.datetime.now()

    def update(self):
        # increment the total number of frames examined during the start
        # and end intervals
        self._numFrames += 1

    def elapsed(self):
        # Return the total number of seconds between the start and end
        return(self._end - self._start).total_seconds()

    def fps(self):
    # compute the number of approximate frames per second
        return self._numFrames / self.elapsed()

class WebCamVideoStream:
    def __init__(self, src=0):
        # initialize the video camera stream and read the first frame from
        # the stream
        self.stream = cv2.VideoCapture(src)
        (self.grabbed, self.frame) = self.stream.read()

        # initialize the variable used to indicate if the thread should be stopped
        self.stopped = False

        def start(self):
            # Start the thread to read frames from the video stream
            Thread(target=self.update, args=()).start()
            return self

        def update(self):
            # kepp looping until the thread is stopped
            while True:
                if self.stopped:
                    return

                # Otherwise, read the next frame from the stream
                else:
                    (self.grabbed, self.frame) = self.stream.read()

        def read(self):
            # Return the frame most recently read
            return self.frame

        def stop(self):
            # Indicate that the thread should be stopped
            self.stopped = True
