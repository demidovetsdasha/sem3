#pragma once
#include "gtest/gtest.h"
#include <string>
#include <fstream>
using namespace std;

class DictionaryNode {
public:
    string englishWord;
    string russianWord;
    DictionaryNode* left;
    DictionaryNode* right;

    DictionaryNode(const string& english, const string& russian) :englishWord(english),
        russianWord(russian), left(NULL), right(NULL) {}
};

class DictionaryTree {
private:
    DictionaryNode* node;

    DictionaryNode* DeleteNode(const string& key);
    int GetNodesCount(DictionaryNode* node);
    void DeleteDictionary(DictionaryNode* node);

public:
    DictionaryTree() : node(NULL) {}
    ~DictionaryTree();


    bool IsContains(const string& english);
    void Add(const string& english, const string& russian);
    void Remove(const string& english);
    string Translate(const string& english);
    void UpdateTranslation(const string& english, const string& russian);
    int GetWordsCount();
    void LoadFromFile(const string& filename);

    string operator [](const string& english);
};
