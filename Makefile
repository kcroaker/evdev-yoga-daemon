PREFIX=$(HOME)/.local
USERCONF=$(HOME)/.config
BIN_NAME = evdev-yoga-daemon

OPTS = -Wall -O2 -pipe

$(BIN_NAME): main.o evdev-backend.o tablet-switch.o
	gcc -o $@ $^ -lm `pkg-config --cflags --libs libevdev`

%.o: src/%.c
	gcc $(OPTS) -c $^

.PHONY: clean
clean:
	rm -f ./*.o
	rm -f $(BIN_NAME)

.PHONY: run
run: $(BIN_NAME)
	./$<

#.PHONY: install
#install:
#	install -m755 $(BIN_NAME) $(PREFIX)/bin/
#	install -m755 ./toggle_appfinder.sh $(PREFIX)/bin/
#	mkdir -p $(USERCONF)/$(BIN_NAME)
#	install -m644 ./config $(USERCONF)/$(BIN_NAME)/
#	install -m644 libinput-touchscreen.service $(USERCONF)/systemd/user/
#