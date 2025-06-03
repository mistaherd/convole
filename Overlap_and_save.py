import matplotlib.pylab as plt
import numpy as np
from convole import my_convole
chunk_size=0xF
context_window=100
assert chunk_size<context_window,"reduce chunk_size/increase contentext window"
xn=np.array(
[3,79,73,51,38,95,78,8,2,55,95,81,36,27,28,35,16,73,43,21,10,30,40,58,5,90,68,74,76,95,97,8,17,81,60,16,58,98,32,68,46,5,2,83,80,68,61,67,62,50,15,46,74,29,20,5,82,58,21,69,85,44,87,71,97,57,61,14,26,78,58,30,37,15,26,67,1,53,84,51,97,58,35,44,35,18,1,85,15,68,11,79,34,9,47,83,60,98,14,98,12])
hn=np.array([-1,3,4]) 

def overlap_and_save(xn,hn,num_of_overlap):
    xn=np.pad(xn,(num_of_overlap,num_of_overlap),"constant",constant_values=0)
    len_out=len(xn)+len(hn)-1
    buffer=[]
    for i in range(len_out):
        if i %chunk_size==0:
            output=my_convole(xn[i:i+chunk_size],hn)
            buffer.append(output[num_of_overlap:-num_of_overlap])
            #buffer.append(output)
    return np.concatenate(buffer)

output=overlap_and_save(xn,hn,3)
print(output,f"\nlen of output :{len(output)}")
#plt.plot(output)
#plt.show()


