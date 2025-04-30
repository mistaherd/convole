import numpy as np
import cv2 as cv

src=np.array(cv.imread("example_1.jpg"))
print(src)
cv.imshow("orginal Image",src)
cv.waitKey(0)
cv.destroyAllWindows()

kernal=np.ones((3,3),np.uint8)
print(kernal)
