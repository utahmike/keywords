#include <iostream>
#include <fstream>
#include <string>
#include <map>

using std::cout;
using std::endl;

void outputfile(const char * filename);

/**
 * Output all of the keyword files given on the command line.
 */
int main(int argc, char const *argv[])
{

	/*
	 * There must be at least one keyword file given.
	 */
	if (argc == 1)
	{
		cout << "usage: " << argv[0] << " [keyword file]" << endl;
		cout << "At least one keyword file must be specified." << endl;
		return 1;
	}

	for (int i = 1 ; i < argc ; ++i)
		outputfile(argv[i]);

	return 0;
}

/**
 * @brief Output the entire lineage of all keywords in a file.
 *
 * Scan through all of the keywords in a file and output them all
 * one at a time, including all of the parents of the keyword up
 * to the root keyword.
 *
 * @param filename
 *	The name of the keword file to scan.
 */
void outputfile(const char * filename)
{
	using std::string;
	using std::map;
	using std::ifstream;

	map<int, string> 			parents;
	
	ifstream 					infile(filename);

	for (string line; getline( infile, line ); ) {

		int tab_count = line.find_first_not_of('\t', 0);
		string word = line.substr(tab_count, line.length() - tab_count);
		parents[tab_count] = word;

		// Output the entire lineage of the keyword.
		for (int i = tab_count ; i > 0 ; --i)
			cout << parents[i] << " < ";

		cout << parents[0] << endl;
	}

}
