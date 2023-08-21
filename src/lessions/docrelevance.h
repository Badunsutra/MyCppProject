#pragma once

#ifndef _DOCRELEVANCE_H_
#define _DOCRELEVANCE_H_

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

namespace docrel {

	string ReadLine();

	int ReadLineWithNumber();

	vector<string> SplitIntoWords(const string& text);

	set<string> ParseStopWords(const string& text);

	vector<string> SplitIntoWordsNoStop(const string& text, const set<string>& stop_words);

	void AddDocument(
		map<string, set<int>>& word_to_documents,
		const set<string>& stop_words,
		int document_id,
		const string& document);

	vector<pair<int, int>> FindDocuments(
		const map<string, set<int>>& word_to_documents,
		const set<string>& stop_words,
		const string& query);
}

#endif // !_DOCRELEVANCE_H_

