import random
import sys

lower = 3
upper = 8

for i in range(7):
    for j in range(random.randint(lower, upper)):
        sys.stdout.write(str(random.randint(0, 1)))
    sys.stdout.write('\n')
