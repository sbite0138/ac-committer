n,m=map(int,input().split())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
a.sort()
b.sort()
i=0
j=0
while(i<n and j<m):
  if (a[i]>=b[j]):
    i+=1
    j+=1
  else:
    i+=1
if (j==n):
  print('Yes')
else:
  print('No')