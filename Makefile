SRC = src/main.cpp
OUT = build/main
DATA_FILES = data/*.txt
DATA_ASSOC_FILES = data/data_assoc*.txt
PLT = src/plot.py

CC = g++
CCFLAGS = -O0 -march=native -std=c++11

eval: $(OUT)
	@taskset -c 0 $(OUT)

$(OUT): $(SRC)
	@$(CC) $(SRC) -o$(OUT) $(CCFLAGS)

pdf: plots $(DATA_ASSOC_FILES)
	@cp data/data_assoc*.txt doc/
	$(MAKE) -C doc pdf

plots: $(DATA_FILES) $(PLT)
	@python3 src/plot.py
	@cp fig/*.svg doc/
	
.PHONY: clean
clean:
	rm -rf build/*
	$(MAKE) -C doc clean
