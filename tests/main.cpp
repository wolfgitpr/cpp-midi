#include <filesystem>
#include <fstream>
#include <functional>
#include <iostream>
#include <string>

#include <wolf-midi/MidiFile.h>

size_t calculateFileHash(const std::filesystem::path &filePath) {
    std::ifstream file(filePath, std::ios::binary);
    if (!file) {
        std::cerr << "Unable to open file: " << filePath << std::endl;
        return 0;
    }

    constexpr std::hash<std::string> hashFn;
    std::string content;
    char buffer[1024];
    while (file.read(buffer, sizeof(buffer)) || file.gcount() > 0) {
        content.append(buffer, file.gcount());
    }

    return hashFn(content);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <midi_path>  <midi_out_path>" << std::endl;
        return 1;
    }

    const std::filesystem::path midiPath = argv[1];
    const std::filesystem::path outPath = argv[2];

    Midi::MidiFile midi;
    if (!midi.load(midiPath))
        std::cerr << "Midi loaded failed" << std::endl;

    if (!midi.save(outPath))
        std::cerr << "Midi saved failed" << std::endl;

    const size_t originalHash = calculateFileHash(midiPath);
    const size_t savedHash = calculateFileHash(outPath);

    if (originalHash == savedHash) {
        std::cout << "The files have the same hash." << std::endl;
    } else {
        std::cout << "The files have different hashes." << std::endl;
    }

    return 0;
}
