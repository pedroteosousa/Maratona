n=list(map(int,input().split()))
v=[0]*n[1]
for i in range(n[0]):
	s=input();
	for j in range(n[1]):
		if s[j]=="Y":
			v[j]+=1
r=0
for i in range(n[1]):
	if v[i]>=n[2]:
		r+=1
print(r)
#kitten
