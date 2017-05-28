import pycgogn
import numpy as np
import sys

def afficher(x):
	print(x)
	if x.dart.index <= 15:
		return False
	else:
		return True

d = pycgogn.Dart(12)
d.index = 4;
print(d)

c = pycgogn.CellP1()
print(c)
print(c.is_valid())

if len(sys.argv) >= 2:
	map = pycgogn.CMap2Tri()
	mesh_path = sys.argv[1]
	pycgogn.import_surface_tri(map,mesh_path)
	print(map.nb_vertices())
	map.foreach_vertex_until(afficher)
	
	a = map.add_vertex_attribute_vec3d("des_vec3")

	def init_plongement_vec3(x):
		a[x] = np.array([1.2, 3.5, 5.1])

	map.foreach_vertex(init_plongement_vec3)
	# map.foreach_vertex(lambda x : print(a[x][1]))
	def afficher_vec3(v):
		if v.dart.index <= 15:
			print(a[x][2])
			return False
		else:
			return True
	map.foreach_vertex_until(afficher_vec3)

print(pycgogn.Orbit.__members__)