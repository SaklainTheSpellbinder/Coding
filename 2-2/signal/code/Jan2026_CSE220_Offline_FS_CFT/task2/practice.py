import numpy as np


x=np.linspace(0,1,100)
y=np.linspace(0,1,80)

X, Y =np.meshgrid(x,y)

G=X**2 + Y **2
first=np.trapezoid(G,x,axis=1)

second=np.trapezoid(first,y)

print(first.shape)
print(first)


print(second.shape)
print(second)



x=np.array([0., 0.5, 1.0])
u=np.array([-1., 0., 1.])

product=np.outer(u,x)

angle=2*np.pi*product

cos_table=np.cos(angle)
sin_table=np.sin(angle)

print(cos_table)
print(sin_table)


print(G[:,None,:].shape)

print(G.shape)