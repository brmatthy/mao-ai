import json
import matplotlib.pyplot as plt
import numpy as np
import pylab as plb

path = '../cmake-build-debug/faults.json'

title = 'Combo_Q_AI'

f = open(path)

y = json.load(f)

percent = np.around(np.mean(y), decimals=2)

y = np.array(y)
y = np.around(y, decimals=2)

y0 = [i for i in range(0, len(y))]

y = np.transpose(y)

x0 = y[0]
x1 = y[1]
x2 = y[2]



z0 = np.poly1d(np.polyfit(y0, x0, 40))
z1 = np.poly1d(np.polyfit(y0, x1, 40))
z2 = np.poly1d(np.polyfit(y0, x2, 40))

plt.scatter(y0, x0, s=1, c="tab:blue")
plt.scatter(y0, x1, s=1, c="tab:orange")
plt.scatter(y0, x2, s=1, c="tab:green")

plt.plot(y0, z0(y0), c="b")
plt.plot(y0, z1(y0), c="r")
plt.plot(y0, z2(y0), c="g")

plt.title(title)
plt.legend(['Move', 'Play', 'Act'])
plt.ylabel(f'Relative faults')
# plt.yscale('symlog', base=2)
plt.xlabel('# Games played')

fig = plt.gcf()
fig.savefig(f'{len(y)}_{title}.png', dpi=500)
plt.clf()
