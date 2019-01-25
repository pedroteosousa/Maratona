resp = ""

for i in range(80):
	a = input();
	if (i % 2 == 1):
		continue
	a = a.split(' (')[0]
	a = a.split(' ')[-1]
	#a = a.split(b + ' ')[1]
	resp = resp + "\"" + a + "\","

print(resp)
