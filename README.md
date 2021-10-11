# ass3
## how to run:
    we provide a CMakeLists.txt file with 2 targets.
    the SERVER target is for running the server, and the CLIENT target is for the client.

    *make sure to run the server first.
    **there is a limmit of 4090 characters for file.
## the code structure:
### the server:
    we created a CLI with the commend pattern.
    the reciver is the classifier from ass1.
    
    after each accept the server is opening a new thread which runs the CLI for one client.
    
    we set the accept timout to 2 min's.