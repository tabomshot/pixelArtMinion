OBJECTS = yoojion.o

all: yoojion

yoojion: $(OBJECTS)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) $(OBJECTS) -o $@

clean:
	-rm -f $(OBJECTS) yoojion

.PHONY: all clean
