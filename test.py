import numpy as np
a=np.array([ [i*0 for i in range(8)] for _ in range(8)])
a=np.concatenate(a)
print(len(a),8*8)
