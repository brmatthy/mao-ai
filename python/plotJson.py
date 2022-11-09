import json
import matplotlib.pyplot as plt
import numpy as np

path = '../cmake-build-debug/faults.json'

f = open(path)

y = json.load(f)

print(np.mean(y))

plt.plot(y)
plt.title('Link-Learn AI')
plt.ylabel('# Faults')
# plt.yscale('symlog', base=2)
plt.xlabel('# Games played')

plt.show()

#fig = plt.gcf()
#fig.savefig('600_ql_smart_state_play_ai' + '.png', dpi=500)
#plt.clf()