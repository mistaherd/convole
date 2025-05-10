import matplotlib.pylab as plt
import numpy as np
from convole import my_convole
chunk_size=0xF
context_window=0xFF
assert chunk_size<context_window,"reduce chunk_size/increase contentext window"
np.random.seed(20)
xn=np.random.randint(0,100,size=context_window)
hn=np.array([-1,3,4]) 
 
def overlap_and_save(xn,hn,num_of_overlap):
    xn=np.pad(xn,(num_of_overlap,num_of_overlap),"constant",constant_values=0)
    len_out=len(xn)+len(hn)-1
    buffer=[]
    for i in range(len_out):
        if i %chunk_size==0:
            output=my_convole(xn[i:i+chunk_size],hn)
            buffer.append(output[num_of_overlap:-num_of_overlap])
    return np.concatenate(buffer)

output=overlap_and_save(xn,hn,3)
print(output)
plt.plot(output)
plt.show()


