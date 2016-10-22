
CC 		 := gcc

CFLAGS   += -g
CFLAGS   += -I$(PWD)/../lua5.2-5.2.3/src
CLDFLAGS += -L$(PWD)/../lua5.2-5.2.3/src/.libs
CLDFLAGS += -llua5.2
CLDFLAGS += -shared -fPIC

TARGETS  := libmath.so

all: $(TARGETS)

$(TARGETS):%.so:%.c
	$(CC) $(CFLAGS) $(CLDFLAGS) -o $@ $<

clean:
	-rm $(TARGETS)

install:
	sudo cp $(TARGETS) /usr/local/lib/lua/5.2/

.PHONY:
	all, $(TARGETS), clean, install
