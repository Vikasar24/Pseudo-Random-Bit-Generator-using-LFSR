const fs = require('fs');

function generateStream(seed, feedbackTaps, length) {
    let lfsr = seed;
    const stream = [];

    for (let i = 0; i < length; i++) {
        let outputBit = lfsr & 1;
        stream.push(outputBit);

        let feedback = 0;
        for (let tap of feedbackTaps) {
            feedback ^= (lfsr >> tap) & 1;
        }

        lfsr = (lfsr >> 1) | (feedback << 7);
        lfsr &= 0xFF;
    }

    return stream;
}

const seed = 0b10101101;
const feedbackTaps = [0, 3];
const streamLength = 20;

const stream = generateStream(seed, feedbackTaps, streamLength);

console.log('Generated stream:', stream.join(''));
fs.writeFileSync('output.txt', stream.join(''));
