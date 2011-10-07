# Makefile for Playground Scheme (Forked from TinyScheme)

.PHONY: tests

all: 
	$(MAKE) -C src/

clean:
	$(MAKE) -C src/ clean

tags: 
	$(MAKE) -C src/ tags

tests:
	@cp src/init.scm .
	@for i in tests/*; do \
		echo ==== Running $$i ====; \
		src/scheme $$i; \
	done
	@rm init.scm
