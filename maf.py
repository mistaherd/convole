import numpy as np
import matplotlib.pyplot as plt 

window_size=10
N=2**8
t=np.linspace(0,1,N)
xn=np.sin(2*np.pi*t)
hn=np.fft.fft(np.ones(window_size)/window_size)
output=np.convolve(xn,hn,mode="same")

print(hn)
plt.plot(t,xn,label="orginal signal")
plt.plot(t,output,label="Filtered signal")
plt.legend()
plt.show()
