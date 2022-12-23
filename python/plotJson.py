import json
import matplotlib.pyplot as plt
import numpy as np

path = '../cmake-build-debug/faults.json'

title = 'Combined_QPlay'

f = open(path)

y = json.load(f)

mean = np.around(np.mean(y), decimals=2)

y = np.array(y)
y = np.around(y, decimals=2)

plt.scatter([i for i in range(len(y))], y , s=1)
plt.title(title)
plt.ylabel(f'Faults per game (mean: {mean})')
# plt.yscale('symlog', base=2)
plt.xlabel('# Games played')

fig = plt.gcf()
fig.savefig(f'{len(y)}_{title}.png', dpi=500)
plt.clf()