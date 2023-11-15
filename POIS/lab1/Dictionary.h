#pragma once
#include "gtest/gtest.h"
#include <string>
#include <fstream>
using namespace std;

class DictionaryNode {
private:
    string englishWord;
    string russianWord;
    DictionaryNode* left;
    DictionaryNode* right;

public:
DictionaryNode(string english, string russian) :englishWord(english),
        russianWord(russian), left(NULL), right(NULL) {}

friend class DictionaryTree;
};

class DictionaryTree {
private:
    DictionaryNode* node;

    DictionaryNode* DeleteNode(string key);
    int GetNodesCount(DictionaryNode* node);
    void DeleteDictionary(DictionaryNode* node);

public:
    DictionaryTree() : node(NULL) {}
    ~DictionaryTree();


    bool IsContains(string english);
    void Add(string english, string russian);
    void Remove(string english);
    string Translate(string english);
    void UpdateTranslation(string english, string russian);
    int GetWordsCount();
    void LoadFromFile(string filename);

    string operator [](string english);
};
