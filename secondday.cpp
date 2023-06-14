#include <iostream>
#include <string>
using namespace std;
int main()
{
	string testText[10] = { "Given$a$text$file$of$many$lines", "where$fields$within$a$line$", "are$delineated$by$a$single$<<dollar>>$character", "write$a$program", "that$aligns$each$column$of$fields", "by$ensuring$that$words$in$each$", "column$are$separated$by$at$least$one$space.","Further, $allow$for$each$word$in$a$column$to$be$either$left$","justified, $right$justified","or$center$justified$within$its$column." };
	string Text[10][12];

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			Text[i][j] = testText[i].substr(0, testText[i].find("$"));
			//cout << Text[i][j] << " ";
			testText[i].erase(0, testText[i].find("$") + 1);

			if (testText[i].rfind("$") == -1)
			{
				Text[i][j+1] = testText[i].substr(0, testText[i].length());
				testText[i].erase(0);
				//cout << Text[i][j+1];
				break;
			}
		}
		//cout << endl;
	}

	//cout << endl << endl;

	int lendth = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if (lendth <= Text[i][j].length())
				lendth = Text[i][j].length();
		}
	}

	
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			cout.width(lendth);
			cout << Text[i][j] << " ";
		}
		cout << endl;
	}
}
