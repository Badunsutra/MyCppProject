#include "docrelevance.h"

namespace docrel {

	string ReadLine() {
		string s;
		getline(cin, s);
		return s;
	}

	int ReadLineWithNumber() {
		int result;
		cin >> result;
		ReadLine();
		return result;
	}

	vector<string> SplitIntoWords(const string& text) {
		vector<string> words;
		string word;
		for (const auto& c : text) {
			if (c == ' ' && word.size()) {
				words.push_back(word);
				word.clear();
			}
			else
				word += c;
		}
		if (word.size()) 
			words.push_back(word);
		return words;
	}

	set<string> ParseStopWords(const string& text) {
		auto stopWords = SplitIntoWords(text);
		return set<string>(stopWords.begin(), stopWords.end());
	}

	vector<string> SplitIntoWordsNoStop(const string& text, const set<string>& stop_words) {
		vector<string> words;
		for (const auto& word : SplitIntoWords(text)) {
			if (!stop_words.count(word))
				words.push_back(word);
		}
		return words;
	}

	void AddDocument(
		map<string, set<int>>& word_to_documents,
		const set<string>& stop_words,
		int document_id,
		const string& document) {
		for (const auto& word : SplitIntoWordsNoStop(document, stop_words))
			word_to_documents[word].insert(document_id);
	}

	vector<pair<int, int>> FindDocuments(
		const map<string, set<int>>& word_to_documents,
		const set<string>& stop_words,
		const string& query) {
		const auto query_words = SplitIntoWordsNoStop(query, stop_words);
		map<int, int> document_to_relevance;
		for (const auto& word : query_words) {
			if (!word_to_documents.count(word))
				continue;
			for (const int document_id : word_to_documents.at(word))
				++document_to_relevance[document_id];
		}

		vector<pair<int, int>> found_documents;
		for (auto [id, rel] : document_to_relevance)
			found_documents.push_back({ id, rel });

		return found_documents;
	}
}