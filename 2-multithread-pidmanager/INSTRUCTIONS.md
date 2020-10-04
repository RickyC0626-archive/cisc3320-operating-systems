# Instructions
Write a multi-threaded program to test the PID manager.

Create several threads (e.g. 100), and each thread will:
- Request a PID
- Sleep for a random period of time (simulate typical PID usage for processes)
- Release the PID

On UNIX and Linux systems sleeping can be done with `sleep(int secs)`.