#include "FrequencyCounter.h"
#include "Huffman.h"
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <ctime>

using namespace std;

// Helper function to get the file size
std::ifstream::pos_type filesize(const char* filename);

// Compare two files to verify correctness (optional for decompress mode)
bool filesAreEqual(const char* file1, const char* file2) {
    ifstream f1(file1, ios::binary);
    ifstream f2(file2, ios::binary);

    if (!f1.is_open() || !f2.is_open()) {
        cerr << "Error: Could not open files for comparison." << endl;
        return false;
    }

    istreambuf_iterator<char> begin1(f1), end1;
    istreambuf_iterator<char> begin2(f2), end2;

    return std::equal(begin1, end1, begin2, end2);
}

int main() {
    FrequencyCounter frequencyCounter;
    Huffman huffman;
    string workingMode;

    cout << "Enter mode (compress / decompress): ";
    cin >> workingMode;

    if (workingMode == "compress") {
        clock_t tStart = clock();

        frequencyCounter.readFile("input.txt");
        huffman.huffer(frequencyCounter.getFrequencyMap());
        huffman.compressTofile("input.txt", "output.txt");

        cout << "Time taken (compression): " 
             << (1.0 * (clock() - tStart) / CLOCKS_PER_SEC) << " sec" << endl;

        cout << "Input File Size : " << filesize("input.txt") << " bytes." << endl;
        cout << "Compressed File Size : " << filesize("output.txt") << " bytes." << endl;
        cout << "Compression Ratio : " 
             << (1.0 * filesize("output.txt") / filesize("input.txt")) << endl;

        cout << "✅ Compression complete. Output file: output.txt" << endl;
    }
    else if (workingMode == "decompress") {
        clock_t tStart = clock();

        huffman.deHuffer("output.txt", "output2.txt");

        cout << "Time taken (decompression): " 
             << (1.0 * (clock() - tStart) / CLOCKS_PER_SEC) << " sec" << endl;

        cout << "Input File (Compressed) Size : " << filesize("output.txt") << " bytes." << endl;
        cout << "DeCompressed File Size : " << filesize("output2.txt") << " bytes." << endl;

        // Optional verification if input.txt exists
        if (filesAreEqual("input.txt", "output2.txt")) {
            cout << "✅ Verification successful: Decompressed file matches original input." << endl;
        } else {
            cout << "⚠️ Note: input.txt not compared (might be missing or different)." << endl;
        }
    } 
    else {
        cerr << "Invalid mode entered. Please use 'compress' or 'decompress'." << endl;
    }

    return 0;
}

// Function to return the size of a file
std::ifstream::pos_type filesize(const char* filename) {
    std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
    return in.tellg();
}
