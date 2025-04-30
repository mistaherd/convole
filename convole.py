import numpy as np
def my_convole(xn,hn):
    len_out=len(xn)+len(hn)-1
    buffer=np.zeros(len_out)
    for n in range(0,len_out):
        for k in range(0,len(hn)):
            if n-k>=0 and n-k<len(xn):
                buffer[n]+=xn[n-k]*hn[k]
    return buffer 

