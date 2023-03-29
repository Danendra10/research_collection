import numpy as np
from voronoi import Delaunay2D
import matplotlib.pyplot as plt

# Create a random set of points
seeds = np.random.random((4, 2))

# Create Delaunay Triangulation and insert points one by one
dt = Delaunay2D()
for s in seeds:
    dt.addPoint(s)

# Dump points and triangles to console
print("Input points:\n", seeds)
print("Delaunay triangles:\n", dt.exportTriangles())

# Plot the triangulation
# plt.figure()
# plt.triplot(seeds[:, 0], seeds[:, 1], dt.exportTriangles())

# Plot the Voronoi diagram
plt.figure()
plt.triplot(seeds[:, 0], seeds[:, 1], dt.exportTriangles())
plt.triplot(seeds[:, 0], seeds[:, 1], dt.exportTriangles(), 'o')
plt.plot(*zip(*dt.exportCircles()), 'o')
plt.show()
