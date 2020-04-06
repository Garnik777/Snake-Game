target : main.cpp draw.cpp
	g++ main.cpp draw.cpp -lglut -lGLU -lGL -o $@
	./target
clean:
	rm *.o target


