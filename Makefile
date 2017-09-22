EXE = ring
CFLAGS = -Wall
LDFLAGS = -pthread

$(EXE): main.o ring_buffer.o
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f *.o tags $(EXE)
