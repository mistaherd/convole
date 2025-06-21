import numpy as np
import cv2 as cv

src=np.array(cv.imread("example_1.jpg",cv.IMREAD_GRAYSCALE))
print("image size=",src.shape)
#cv.imshow("orginal Image",src)
#cv.waitKey(0)
#cv.destroyAllWindows
Identity_Kernal=np.array([[0,0,0],[0,1,0],[0,0,0]])
height,width=src.shape

grid_size=Identity_Kernal.shape[0]
def output_shape(src,kernal,padding,stride):
    h,w=src.shape[-2],src.shape[-1]
    k_h,k_w=kernal.shape[-2],kernal.shape[-1]
    h_out=(h-k_h-2*padding)//stride[0]+1
    w_out=(w-k_w-2*padding)//stride[1]+1

    return h_out,w_out
a=output_shape(src,Identity_Kernal,padding=0,stride=(1,1))

print(a)
def convole(src):
    for i in range(0,width,round(width/grid_size)):
        for j in range(0,height,round(width/grid_size)):
            grid=src[i:i+grid_size,j:j+grid_size]
            print(grid)
convole(src)
