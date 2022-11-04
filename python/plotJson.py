import json
import matplotlib.pyplot as plt
import numpy as np

path = '../cmake-build-debug/faults.json'

f = open(path)

y = json.load(f)

plt.plot(y)
plt.ylabel('# Faults')
# plt.yscale('symlog', base=2)
plt.xlabel('# Games played')
plt.show()