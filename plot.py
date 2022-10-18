import csv
import matplotlib.pyplot as plt

pointsBest = []
pointsAvg = []

# read csv file
with open('cmake-build-debug/out.csv') as csv_file:
    csv_reader = csv.reader(csv_file, delimiter='|')
    line_count = 0
    for row in csv_reader:
        pointsBest.append(float(row[0].rstrip(" faults ")))
        pointsAvg.append(float(row[1].rstrip(" avg.")))

plt.plot(pointsBest)
plt.plot(pointsBest)
fig = plt.gcf()
fig.savefig('out.png', dpi=500)
plt.clf()