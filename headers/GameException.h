#ifndef GAMEEXCEPTION_H
#define GAMEEXCEPTION_H

#include <string>
#include <exception>

using namespace std;

class GameException : public exception {
protected:
    string message;

public:
    GameException(const string& msg) : message(msg) {}
    const char* what() const noexcept override { return message.c_str(); }
};

class SaveGameException : public GameException {
public:
    SaveGameException(const string& filename, const string& reason) : GameException("Failed to save game to '" + filename + "': " + reason) {}
};

class LoadGameException : public GameException {
public:
    LoadGameException(const string& filename, const string& reason) : GameException("Failed to load game from '" + filename + "' : " + reason) {}
};

class FileNotFoundException : public LoadGameException {
public:
    FileNotFoundException(const string& filename) : LoadGameException(filename, "File not found") {}
};

class CorruptedSaveException : public LoadGameException {
public:
    CorruptedSaveException(const string& filename, const string& details) : LoadGameException(filename, "Corrupted save file: " + details) {}
};

#endif