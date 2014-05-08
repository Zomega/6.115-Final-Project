# See http://burtleburtle.net/bob/rand/unitvec.html
# Need to ensure that no more than 6 vectors are within a certian mutual distance to each other.
# Angular distance is really the only sensible measure. Therefore, the dot product is used.

from math import sqrt, cos, pi
from numpy.random import normal

def dot( v1, v2 ):
	assert len( v1 ) == len( v2 )
	result = 0
	for i in range( len( v1 ) ):
		result += v1[i] * v2[i]
	return result

def length( v1 ):
	return sqrt( dot( v1, v1 ) )

def unit( v1 ):
	l = length( v1 )
	return tuple( c / l for c in v1 )

def random_unit():
	return unit( ( normal(), normal(), normal() ) )

def get_stars( threshold, max_per_screen ):
	stars = []

	tries = 10**4
	while tries > 0:
		canidate = random_unit()
		num_close = 0
		for star in stars:
			if dot( canidate, star ) > threshold:
				num_close += 1
		if num_close > max_per_screen:
			tries -= 1
			continue
		stars.append( canidate )
		#print canidate, num_close, tries
		tries = 10**4
	return stars

def print_stars( stars ):
	print "#define NUM_STARS", len(stars)

	print "vector3 stars[ NUM_STARS ] = {"
	for star in stars:
		print "\t" + str( star[0] ) + ", " + str( star[1] ) + ", " + str( star[2] ) + ","
	print "};"

best_stars = None
for i in range( 20 ):
	stars = get_stars( cos( pi/ 1.2 ), 6 )
	if best_stars == None or len( stars ) > len( best_stars ):
		best_stars = stars
print_stars( best_stars )
