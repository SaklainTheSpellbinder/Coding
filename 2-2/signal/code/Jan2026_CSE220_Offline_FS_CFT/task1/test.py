import numpy as np

t= np.linspace(0, 2*np.pi, 5)

wave=np.exp(1j*t)

print(wave)


for n in range(-3,4):
    print(n)



values={}

values[-1]=3.2
values[0]=8.4
values[1]=7.1

print(values)


d={
    -1:10,
    0: 20,
    1: 30
}

for key in d:
    print(key,d[key])

for key, value in d.items():
    print(key,value)



class Student:
    def __init__(self,name):
        self.name=name
    
    def introduce(self):
        print(self.name)

a=Student("Alice")
b=Student("Bob")

a.introduce()



t= np.array([0.1,0.2,0.3,0.4])

x=np.exp(1j *2 *t)
print(x)


t=np.linspace(0,2*np.pi,100)
z=2*np.exp(1j*3*t)

print(z)


t=np.linspace(0,np.pi,1000)
g=np.sin(t)
answer=np.trapezoid(g,t)
print(answer)



t=np.linspace(0,2*np.pi,1000)
z1=2*np.exp(1j*t)
z2=0.5*np.exp(1j*-3*t)

z=z1+z2

print(z)
answer=np.trapezoid(z,t)
print(answer)


