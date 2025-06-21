import numpy as np
def dft(x):
    N=len(x)
    y=np.zeros(N,dtype=complex)

    for n in range(N):
        for k in range(N):
            y[n]+=x[k]*np.e**(-2j*np.pi*k*n/N)
    return y

