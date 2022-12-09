import json
import matplotlib.pyplot as plt
import numpy as np

path = '../cmake-build-debug/faults.json'

title = 'Combo_Q_AI'

f = open(path)

y = json.load(f)

percent = np.around(np.mean(y), decimals=2)

y = np.array(y)
y = np.around(y, decimals=2)

plt.plot(y)
plt.title(title)
plt.ylabel(f'Faults per game (mean: {percent})')
# plt.yscale('symlog', base=2)
plt.xlabel('# Games played')

fig = plt.gcf()
fig.savefig(f'{len(y)}_{title}.png', dpi=500)
plt.clf()