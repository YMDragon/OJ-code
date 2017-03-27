f=[0 for x in range(1001)]
n=input()
f[1]=1
f[2]=5
for i in range(3,n+1):
    f[i]=3*f[i-1]-f[i-2]+2
print f[n]
