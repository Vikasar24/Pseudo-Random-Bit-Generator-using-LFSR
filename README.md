# LFSR Bitstream Generator (C++ and JavaScript)

This project implements a simple Linear Feedback Shift Register (LFSR) in C++ and JavaScript to generate pseudo-random bitstreams. It uses a seed, feedback taps, and stream length as inputs, and outputs the generated stream to the console and a file. Ideal for learning basic stream ciphers and randomness simulation.

## Files

- `lfsr.cpp` : C++ program to generate a bitstream using an LFSR.
- `lfsr.js`  : JavaScript version of the same logic.
- `output.txt` : Sample generated output stream.

## How to Run

### C++ version
```bash
g++ lfsr.cpp -o lfsr
./lfsr
```

### JavaScript version
```bash
node lfsr.js
```

## Parameters

- **Seed**: Initial value of the LFSR.
- **Feedback Taps**: Positions from which bits are XORed to produce the feedback bit.
- **Stream Length**: Total number of bits to generate.

## Example

Seed: `0b10101101`  
Feedback taps: `[0, 3]`  
Stream length: `20`

Generated stream:
```
11010110010110010011
```
