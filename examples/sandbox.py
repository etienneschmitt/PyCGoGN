import pycgogn as pc
import numpy as np
import sys



d = pc.Dart(12)
d.index = 4;
print(d)

c = pc.CellP1()
print(c)
print(c.is_valid())

if len(sys.argv) >= 2:
	map = pc.CMap2()
	mesh_path = sys.argv[1]
	pc.import_surface(map,mesh_path)
	print(map.nb_vertices())

	dmarker = pc.DartMarkerStore2(map)
	vmarker = pc.VertexMarkerStore2(map)

	def afficher(c):
		def afficher_arete(e):
			print(e)
		map.foreach_incident_edge(c, afficher_arete)
		dmarker.mark(c.dart)
		# vmarker.mark(c)
		print(c)
		if c.dart.index <= 8:
			return True
		else:
			return False
	map.foreach_vertex_until(afficher)
	# dmarker.unmark_all()
	# print(dmarker.marked_darts())
	# print(vmarker.marked_cells())
	a = map.add_vertex_attribute_mat("une_matrice")

	def init_plongement_vec(x):
		a[x] = np.array([[1.2, 3.5, 5.1, 5.2, 0.8, -2.1],
			             [3.6, 5.3, 7.4, 9.5, 0.1, -5.2]])

	map.foreach_vertex(init_plongement_vec)
	# map.foreach_vertex(lambda x : print(a[x][1]))
	def afficher_vec3(c):
		if c.dart.index <= 15:
			print(c)
			print(a[c])
			return True
		else:
			return False
	map.foreach_vertex(afficher_vec3)

print(pc.Orbit.__members__)