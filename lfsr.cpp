#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

vector<int> generateStream(int seed, const vector<int>& feedbackTaps, int length) {
    int lfsr = seed;
    vector<int> stream;

    for (int i = 0; i < length; ++i) {
        int outputBit = lfsr & 1;
        stream.push_back(outputBit);

        int feedback = 0;
        for (int tap : feedbackTaps) {
            feedback ^= (lfsr >> tap) & 1;
        }

        lfsr = (lfsr >> 1) | (feedback << 7);
        lfsr &= 0xFF; // Keep within 8 bits
    }

    return stream;
}

int main() {
    int seed = 0b10101101;
    vector<int> feedbackTaps = {0, 3};
    int streamLength = 20;

    vector<int> stream = generateStream(seed, feedbackTaps, streamLength);

    ofstream outFile("output.txt");
    cout << "Generated stream: ";
    for (int bit : stream) {
        cout << bit;
        outFile << bit;
    }
    cout << endl;
    outFile.close();

    return 0;
}
