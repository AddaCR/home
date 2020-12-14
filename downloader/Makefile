LDFLAGS:=-lboost_system -pthread
.PHONY: clean
all: server client
server: server.cpp File.cpp File.hpp
client: client.cpp
clean:
	rm client server
