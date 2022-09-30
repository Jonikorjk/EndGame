_clang = clang -o
_object = endgame
_src = src/*.c
_flags = `sdl2-config --cflags --libs` -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lm

all: install

install:
	${_clang} ${_object} ${_src} ${_flags}

uninstall:
	rm ${_object}

clean:
	rm ${_object}

reinstall: 
	rm ${_object}
	make
