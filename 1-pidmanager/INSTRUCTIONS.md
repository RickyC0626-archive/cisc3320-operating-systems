# Instructions
Implement a simple API for a pid manager.

## Constraints
The range of possible pid values:

```cpp
#define MIN_PID 300
#define MAX_PID 5000
```

## Data Structures
Use any data structure that you see fit to represent the availability of process identifiers.

**Hint:** Linux implements a bitmap where `0` at position `i` indicates available process id, and `1` indicates process id is in use.

## API
```cpp
/**
 * Creates and initialize a data structure for representing pids
 * 
 * @return -1 if unsuccessful, 1 if successful
 */
int allocate_map();

/**
 * Allocates and returns a pid
 * 
 * @return -1 if unable to allocate a pid (all pids are in use),
 * otherwise return the allocated pid
 */
int allocate_pid();

/**
 * Releases a pid
 */
void release_pid(int pid);
``` 