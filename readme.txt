Add a class called storage manager. This manager should have the following functions:

1. Be able to save and load notes to/from some devices, the device could be a local file, web service, im client, http get/post, socket, etc.

2. The manager should be able to search for a message or index the message in a reasonable performance.

3. The devices in the manage should inherit QIODevice so that they can be used in a traditional way that most Qt programmers are familar with

****
Freedom software model:

Software modelling is a procedure to reduce the freedom of the users.
How to achieve the best user experience while providing reasonable freedom, is the key problem.

****
Write a small program to generate Qt header files, modify .pro files, and generate .cpp skeleton based on the headers.
