import json
import matplotlib.pyplot as plt
import numpy as np

path = '../cmake-build-debug/faults.json'

title = 'Q-Act_test_AI'

f = open(path)

y = json.load(f)

percent = np.around(np.mean(y)*100, decimals=2)

y = np.array(y) * 100
y = np.around(y, decimals=2)

plt.plot(y)
plt.title(title)
plt.ylabel(f'Faults per game (mean: {percent})')
# plt.yscale('symlog', base=2)
plt.xlabel('# Games played')

fig = plt.gcf()
fig.savefig(f'{len(y)}_{title}.png', dpi=500)
plt.clf()