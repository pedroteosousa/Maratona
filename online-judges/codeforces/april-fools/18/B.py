import sys

d = ["no", "no", "no", "no way", "no way", "go die in a hole", "worse", "are you serious", "terrible", "don't even"]
c = 0

resp = "normal"

for i in range(10):
	print(i)
	sys.stdout.flush()
	a = raw_input()
	if a == 'no':
		c += 1
	if a in d:
		d.remove(a)

if len(d) == 0:
	resp = "grumpy"
print(resp)
sys.stdout.flush()
