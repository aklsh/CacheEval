SRC = src/main.cpp
OUT = build/main
DATA_FILES = data/*.txt
PLT = src/plot.py

CC = g++
CCFLAGS = -O0 -march=native -std=c++11

eval: $(OUT)
	@taskset -c 0 $(OUT)

$(OUT): $(SRC)
	@$(CC) $(SRC) -o$(OUT) $(CCFLAGS)

pdf: plots
	$(MAKE) -C doc pdf

plots: $(DATA_FILES) $(PLT)
	python3 src/plot.py
	cp fig/*.svg doc/
	
.PHONY: clean
clean:
	rm -rf build/*
	$(MAKE) -C doc clean
