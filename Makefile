# Makefile for Playground Scheme (Forked from TinyScheme)

.PHONY: tests

all: 
	$(MAKE) -C src/

clean:
	$(MAKE) -C src/ clean

tags: 
	$(MAKE) -C src/ tags

tests:
	@for i in tests/*; do \
		echo ==== Running $$i ====; \
		TINYSCHEMEINIT=collect/init.scm src/scheme $$i; \
	done
