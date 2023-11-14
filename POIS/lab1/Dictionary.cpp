#include<iostream>
#include<string.h>
#include<fstream>

/*!
    \brief Implementation of the Dictionary(eng-rus) class
    \author Dasha
    \version 1
    \date October 2023
    \details Contains a default constructor, which creates empty binary tree;
     operator [] for obtaining translation; methods for working with dictionary and
     reading a dictionary from a file.

*/
#include "Dictionary.h"

/*!
    \brief Helper method for checking if a dictionary contains required word (with parameter)
    \param english english word of the dictionary
    \return True if yes, False if no
*/
bool DictionaryTree::IsContains(const string& english)
{
    DictionaryNode* currentNode = node;
    while (currentNode != NULL) {
        if (english == currentNode->englishWord) {
            return true;
        }
        else if (english < currentNode->englishWord) {
            currentNode = currentNode->left;
        }
        else {
            currentNode = currentNode->right;
        }
    }

    return false;
}


/*!
  \brief Method Adding a couple of words to dictionary (with parameters)
  \param english, russian couple of words of the dictionary
*/
void DictionaryTree::Add(const string& english, const string& russian) {
    if (!node) {
        node = new DictionaryNode(english, russian);
        return;
    }

    DictionaryNode* currentNode = node;
    while (node) {
        if (english < currentNode->englishWord) {
            if (currentNode->left == NULL) {
                currentNode->left = new DictionaryNode(english, russian);
                return;
            }
            else {
                currentNode = currentNode->left;
            }
        }
        else {
            if (currentNode->right == NULL) {
                currentNode->right = new DictionaryNode(english, russian);
                return;
            }
            else {
                currentNode = currentNode->right;
            }
        }
    }
}



/*!
    \brief Helper method for Deleting node from binary tree (with parameter)
    \param english english word of the dictionary
    \return binary tree without deleted node
*/
DictionaryNode* DictionaryTree::DeleteNode(const string& english)
{
    DictionaryNode* removableNode, * previosNode, * subTreeElement, * previosSubTreeElement;

    removableNode = node;
    previosNode = NULL;

    //поиск узла по ключу
    while (removableNode != NULL && removableNode->englishWord != english) {
        previosNode = removableNode;
        removableNode = (english < removableNode->englishWord) ? removableNode->left : removableNode->right;
    }

    if (!removableNode)
    {
        cout << "\nNo such word was found" << endl;
        return node;
    }

    //поиск узла на замену удаляемому
    if (!removableNode->right)
    {
        subTreeElement = removableNode->left;
    }
    else
    {
        if (!removableNode->left)
        {
            subTreeElement = removableNode->right;
        }
        else
        {
            previosSubTreeElement = removableNode;
            subTreeElement = removableNode->left;

            while (subTreeElement->right)
            {
                previosSubTreeElement = subTreeElement;
                subTreeElement = subTreeElement->right;
            }
            if (previosSubTreeElement == removableNode)
                subTreeElement->right = removableNode->right;
            else {
                subTreeElement->right = removableNode->right;
                previosSubTreeElement->right = subTreeElement->left;
                subTreeElement->left = previosSubTreeElement;
            }
        }
    }

    if (removableNode == node)
        node = subTreeElement;
    else
        if (removableNode->englishWord < previosNode->englishWord)
            previosNode->left = subTreeElement;
        else
            previosNode->right = subTreeElement;

    cout << "\nWords are deleted!" << endl;

    delete  removableNode;
    return node;
}

/*!
  \brief Method Removing a couple of words (with parameter)
  \param english english word of the dictionary
*/
void DictionaryTree::Remove(const string& english) {
    if (IsContains(english) == 0) return;
    node = DeleteNode(english);
}

/*!
    \brief Method for obtaining translation (with parameter)
    \param english english word of the dictionary
    \return russian translation
*/
string DictionaryTree::Translate(const string& english) {
    DictionaryNode* currentNode = node;
    while (currentNode != NULL) {
        if (english == currentNode->englishWord) {
            return currentNode->russianWord;
        }
        else if (english < currentNode->englishWord) {
            currentNode = currentNode->left;
        }
        else {
            currentNode = currentNode->right;
        }
    }

    throw exception();
}

/*!
  \brief Method Changing a couple of words in dictionary (with parameters)
  \param english, russian couple of words of the dictionary
*/
void DictionaryTree::UpdateTranslation(const string& english, const string& russian) {
    DictionaryNode* currentNode = node;
    while (currentNode != NULL) {
        if (english == currentNode->englishWord) {
            currentNode->russianWord = russian;
            return;
        }
        else if (english < currentNode->englishWord) {
            currentNode = currentNode->left;
        }
        else {
            currentNode = currentNode->right;
        }
    }
    cout << "No such word was found.\n";
}


/*!
    \brief Helper method for calculation node's count(with parameter)
    \param node node of a binary tree
    \return node's count
*/
int DictionaryTree::GetNodesCount(DictionaryNode* node) {
    if (node->left == NULL && node->right == NULL) return 1;

    int left, right;

    if (node->left != NULL)
        left = GetNodesCount(node->left); //считаем количество узлов в левом поддереве
    else left = 0;

    if (node->right != NULL)
        right = GetNodesCount(node->right); //считаем количество узлов в правом поддереве
    else right = 0;

    return left + right + 1;
}


/*!
    \brief Method which calculate count of word's couples
    \return node's count
*/
int DictionaryTree::GetWordsCount() {
    return GetNodesCount(node);
}

/*!
  \brief Method Loading dictionary data from file (with parameter)
  \param filename file from which the dictionary is read
*/
void DictionaryTree::LoadFromFile(const string& filename) {
    ifstream in(filename.c_str());

    if (!in)
        cout << "Cannot open the File : " << filename << endl;

    string line, english, russian;
    bool isEnglish = true;

    while (getline(in, line))
    {
        for (int i = 0; i < line.size(); i++)
        {
            if (line[i] == ' ')
            {
                isEnglish = false;
            }
            else
            {
                if (isEnglish)
                    english.push_back(line[i]);
                else
                    russian.push_back(line[i]);
            }
        }

        Add(english, russian);
    }

    in.close();
}

/*!
  \brief Overloading indexer operator (with parameter)
  \param english english word of the dictionary
  \return russian translation
*/
string DictionaryTree::operator[](const string& english) {
    if (IsContains(english) == 0) return "";
    return Translate(english);
}

/*!
  \brief Class destructor
*/
DictionaryTree::~DictionaryTree() {
    DeleteDictionary(node);
}

/*!
  \brief Helper Method deleting binary tree (with parameter)
  \param node node of the binary tree
*/
void DictionaryTree::DeleteDictionary(DictionaryNode* node) {
    if (node) {
        DeleteDictionary(node->left);
        DeleteDictionary(node->right);
        delete node;
    }
}
