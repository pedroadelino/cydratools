all:
	make -C src

install:
	cp src/cydratools /usr/bin/cydratools

clean:
	rm src/cydratools
