import numpy as np
import matplotlib.pyplot as plt
def hanning(M):
    out=np.zeros(M)
    for n in range(M):
        res=0.5-0.5*np.cos((n*np.pi)/M-1)
        out[n]+=res
    return out
def dft(x):
    N=len(x)
    y=np.zeros(N,dtype=complex)
    for n in range(N):
        for k in range(N):
            y[n]+=x[k]*np.e**(-2j*np.pi*k*n/N)
    return y
h=[2,4,6,7,8]
window_size=0xFF
x=np.random.randint(0,100,window_size)
def FIR(M):
    y_len=M-1
    y=np.zeros(y_len)
    for n in range(M):
        for k in range(y_len):
            if n-k >=0 and n-k<y_len:
                print(k)
                y[n]+=x[n-k]*h[k]
    print(y)
    return y
FIR(window_size)
