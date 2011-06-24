# Makefile for Playground Scheme (Forked from TinyScheme)

all: 
	$(MAKE) -C src/

clean:
	$(MAKE) -C src/ clean

tags: 
	$(MAKE) -C src/ tags


