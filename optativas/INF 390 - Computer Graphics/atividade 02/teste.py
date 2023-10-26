import cv2

video = cv2.VideoCapture(2)

while True:
    conectado, frame = video.read()
    cv2.imshow('Video', frame)
    if cv2.waitKey(1) == ord('q'):
        break