This is the source code of micro benchmark for read and write.

`main.c` is c source code, and `rwtest_arm64` is executable file in mobile devices.


## Usage
```
./rwtest_arm64 fileName  32 1 0
```
- file `fileName` to be opened for read or write test. Create file `fileName` before read test.
- `32` means requesting 32 pages.
- `1` means write.
- `0`: used for initializing buffer.


## Testing steps

### Write test

1. restart mobile phone
2. clean cache
3. test write `./rwtest_arm64 test.txt 131072 1 0`

### Read test
1. restart mobile phone
2. clean cache
3. test read `./rwtest_arm64 test.txt 131072 0 0`

