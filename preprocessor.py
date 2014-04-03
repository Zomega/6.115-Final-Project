#!/usr/bin/python

# Usage 'python preprocessor.py [filename]'

from parse import *

import sys

base_filename = str(sys.argv[-1])

def preprocess( filename, imported = [] ):
	# Make sure we need this file...
	imported = set( imported )
	if filename in imported:
		return imported
	imported.add( filename )
	
	# Run through the file, calling preprocess
	# recursively as needed.
	with open( filename ) as f:
		for unstripped_line in f:
			line = unstripped_line.strip()
			if len( line ) == 0:
				continue
			if line[0] == ';':
				continue
			if line[0] == '~':
				fn = parse('~include {filename}', line)['filename']
				if fn in imported:
					continue
				imported = imported | preprocess( fn )
				continue
			print unstripped_line[:-1]
	return imported

print ';README: This file was created using preprocess.py an (imperfect)'
print ';script designed to help stitch together 8051 ASM libraries.'
print ';Editing this script by hand is not recommended. Please edit the'
print ';original asm files.\n'
preprocess( base_filename )
print ''
