all: ashell toto_cmd exit_cmd

%_cmd:
	mkdir -p ./bin
	@(cd src/$@ && $(MAKE) )

ashell:
	mkdir -p ./bin
	@(cd src/ashell && $(MAKE))

clean:
	@(cd src/ashell && $(MAKE) clean)
	rm -f bin/*	

