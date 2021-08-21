SRC = src/main.cpp src/funcs.cpp
OUT = build/main
DATA_FILES = data/*.txt
DATA_ASSOC_FILES = data/data_assoc*.txt
PLT = plot.py

CC = g++
CCFLAGS = -O0 -march=native -std=c++11 -Iinc

eval: $(OUT)
	@taskset -c 0 $(OUT)

$(OUT): $(SRC)
	@$(CC) $(SRC) -o$(OUT) $(CCFLAGS)

pdf: plots $(DATA_ASSOC_FILES)
	$(MAKE) -C doc pdf

plots: $(DATA_FILES) $(PLT)
	@python3 $(PLT)
	@cp fig/*.svg doc/
	
.PHONY: clean
clean:
	rm -rf build/*
	$(MAKE) -C doc clean
