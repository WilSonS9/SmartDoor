import random

f = open('002_list.txt').read().split('\n')

l = []

for i in range(30):
    a = random.choice(f)
    l.append(a)
    f.remove(a)

a = open("test.txt", "a")
a.write('\n'.join(l))

b = open("train.txt", "a")
b.write('\n'.join(f))