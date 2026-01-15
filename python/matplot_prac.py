import matplotlib.pyplot as plt
import numpy as np

t = np.linspace(0,10,100)
s= (np.cos(2*np.pi*t)/np.sin(2*np.pi*t))

plt.plot(t,s)

plt.xlabel("s(t)")
plt.title("Sine wave")
plt.ylabel("t")
plt.grid()
plt.legend()
plt.subplot()
plt.figure()
# plt.axis(0,6,0,10)
plt.show()

ruhaan # pyright: ignore[reportUndefinedVariable]

