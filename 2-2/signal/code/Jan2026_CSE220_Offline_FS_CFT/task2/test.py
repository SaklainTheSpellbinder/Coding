import numpy as np
import matplotlib.pyplot as plt

x=np.array([0.,1.,2.])

values=np.array([
    [0., 1., 4.],
    [0.,2.,8.]
])


values2=np.array([x**2, 2* x**2])

values3=np.vstack([x**2, 2* x**2])


coeffs=np.array([[1.0], [2.0]])
values4=coeffs*(x**2)

result=np.trapezoid(values2,x,axis=1)

print(x)

print(2*x)

print(result)

a= np.array([3,7,2])
print(a.max())


a= np.array([0,1,10])
print(np.log(1+a))


t=np.linspace(0,1,1000)
x=np.cos(2*np.pi*3*t)


x=np.linspace(0,1,100)
y=np.linspace(0,1,80)

X, Y =np.meshgrid(x,y)

G=X**2 + Y **2

plt.figure(figsize=(7,5))

contour= plt.contourf(X,Y,G,levels=30,cmap='viridis')
plt.colorbar(contour,label='$G=X^2 + Y^2$')

lines=plt.contour(X,Y,G,levels=10,colors='black',alpha=0.4,linewidth=0.7)
plt.clabel(lines,inline=True,fontsize=8)

plt.title('2D Contour Plot of $G = X^2 + Y^2$')
plt.xlabel('x')
plt.ylabel('y')
plt.tight_layout()
plt.show()




fig=plt.figure(figsize=(8,6))
ax=fig.add_subplot(111,projection='3d')

surf=ax.plot_surface(X,Y,G,cmap='viridis',edgecolor='none',alpha=0.9)
fig.colorbar(surf,ax=ax,shrink=0.5,aspect=10,label='$G=X^2 + Y^2$')

ax.set_title('#D Surface: $G=X^2 + Y^2$')
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('G')
plt.show()



