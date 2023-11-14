#include "Dictionary.h"


TEST(DictionaryTest, TranslationTest) {
	DictionaryTree dictionary;

	dictionary.Add("Table", "Стол");

	ASSERT_EQ(dictionary["Table"], "Стол");
	ASSERT_EQ(dictionary.Translate("Table"), "Стол");
}

TEST(DictionaryTest, RemoveElementTest) {
	DictionaryTree dictionary;

	dictionary.Add("BSUIR", "БГУИР");
	ASSERT_TRUE(dictionary.IsContains("BSUIR"));

	dictionary.Remove("BSUIR");
	ASSERT_FALSE(dictionary.IsContains("BSUIR"));
}

TEST(DictionaryTest, UpdateTranslationTest) {
	DictionaryTree dictionary;

	dictionary.Add("ai", "ии");
	dictionary.Add("reading", "чтение");

	dictionary.UpdateTranslation("ai", "топспецуха");
	dictionary.UpdateTranslation("reading", "хобби");

	ASSERT_EQ(dictionary["ai"], "топспецуха");
	ASSERT_EQ(dictionary["reading"], "хобби");
}

TEST(DictionaryTest, GetCountTest) {
	DictionaryTree dictionary;

	dictionary.Add("sun", "солнце");
	dictionary.Add("shiba-inu", "сиба-ину");
	dictionary.Add("mint", "мята");
	dictionary.Add("beauty", "красота");
	dictionary.Add("japan", "япония");
	dictionary.Add("clover", "клевер");
	dictionary.Add("lavender", "лаванда");
	dictionary.Add("design", "дизайн");
	dictionary.Add("headphones", "наушники");
	dictionary.Add("library", "библиотека");
	dictionary.Add("outfit", "образ");


	ASSERT_EQ(dictionary.GetWordsCount(), 11);
}


TEST(DictionaryTest, LoadFromFileTest) {
	DictionaryTree dictionary;
	ASSERT_TRUE(dictionary.GetWordsCount() == 0);

	auto file = "file.txt";
	dictionary.LoadFromFile(file);
	ASSERT_TRUE(dictionary.GetWordsCount() > 0);
}
