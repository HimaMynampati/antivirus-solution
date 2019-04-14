#include <iostream>
#include <vector>
#include <string>
#include <direct.h>
#include <string.h>
#include <fstream>
#include <conio.h>
#include<filesystem>
#include <cstring>
#include <stdlib.h>
#include <iostream>
#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"
#include "cgicc/HTMLClasses.h"

using namespace std;
using namespace cgicc;
#include <direct.h>
#include <string.h>
#include <fstream>
#include <conio.h>
#include <cstring>
#include <stdlib.h>
#include <iostream>
using namespace std;
int scan_this(char *file_name)
{
	ifstream fin_file, fin_db;
	char file_ch, ch;

	int val, flag;
	string dbfiles[2] = { "db1.txt", "db2.txt" };
	for (int itr1 = 0; itr1 < 2; itr1++)
	{
		fin_db.open(dbfiles[itr1]);
		char *file_name1 = new char[dbfiles[itr1].length() + 1];
		int i;
		for (i = 0; i < dbfiles[itr1].length(); i++)
		{
			file_name1[i] = dbfiles[itr1][i];
		}
		file_name1[i] = '\0';
	
		FILE *db_pointer = fopen(file_name1, "r");




		if (db_pointer == NULL)
		{
			cout << "cannot open db1.txt file";
			cout << "</br>";
			return 0;
		}


		while (!fin_db.eof())
		{
			FILE *file_pointer = fopen(file_name, "r");

			if (file_pointer == NULL)
			{
				cout << "cannot open the given file" << "\n";
				return 0;
			}

			fin_file.open(file_name);
			char temp[5], char_line;
			int k;

			for (k = 0; k < 4; k++)
			{
				fin_db >> char_line;
				temp[k] = char_line;
			}
			temp[k] = '\0';

			if (!strcmpi(temp, "LINE"))

			{

				fin_db >> val;//line number
				//cout << "line number read is :" << val;
		

				if (val == 1)
				{

				}
				else

				{

			
					while (val != 1)
					{
						ch = getc(file_pointer);
						fin_file.get();

						while (ch != '\n')
						{
							ch = getc(file_pointer);

							fin_file.get();

						}
						val--;
					}


				}


				fin_db >> val;//character position
				//cout << "Character position is  :" << val;

				
				fin_db >> file_ch;
				//cout << "CHaracter is " << file_ch;//character value in db
			
				if (val == 1)
				{
					fin_file.get(ch);
					fin_file.get();

					//cout << "character in sample file is :" << ch;
				
				}
				else
				{

					for (int j = 1; j <= val; j++)

					{

						fin_file.get(ch);
					}
					//cout << "character in sample file is :" << ch;
					
				}



				if (file_ch == ch)
				{
					flag = 1;
					fgetc(db_pointer);
					fin_db.get();
					fin_file.close();
					fclose(file_pointer);
					continue;

				}

				else
				{
					fin_file.close();
					fclose(file_pointer);
					fin_db.close();
					fclose(file_pointer);
					flag = 0;
					break;

				}
			}
			else
			{
			
				fclose(file_pointer);
				fin_file.close();

			}
			fclose(file_pointer);
			fin_file.close();


		}

		fclose(db_pointer);

		fin_db.close();

		if (flag == 1)
		{
			return flag;
		}
	}

	return flag;
}



int main(int argc, char **argv)
{
	string file_name;
	try {
		Cgicc cgi;

		// Send HTTP header
		cout << HTTPHTMLHeader() << "\n";

		// Set up the HTML document
		cout << html() << head(title("cgicc example")) << "\n";
		cout << body() << "\n";
		// Print out the submitted element
		form_iterator name = cgi.getElement("name");
		if (name != cgi.getElements().end()) {
			file_name = **name;
		}

		// Close the HTML document
		cout << body() << html();
	}
	catch (exception& e) {
		// handle any errors - omitted for brevity
	}
	int i = 0;
	char *file_name1 = new char[file_name.length() + 1];
	for (i = 0; i < file_name.length(); i++)
	{
		file_name1[i] = file_name[i];
	}
	file_name1[i] = '\0';
	int return_val;
	return_val = scan_this(file_name1);
	if (return_val == 1)
	{
		cout << "<center><font size=\"10\"<p style=\"color:red\"> Virus Detected</p></font></center>";
		//cout << file_name1;
		cout << "<br/>";
		
		
		
	/*	if (rename(file_name1, "C:/Users/Edverd hunter/Apache2.2/cgi-bin/virus/new2.txt"));
		{
			cout << "file renamed";
		}*/
		remove(file_name1);
		cout << "<center><font size=\"10\"<p style=\"color:green\"> Virus File Deleted</p></font></center>";
		cout << "</br>";
		cout << "<img src =\"detected.jpg\">";
		

	}
	else
	{
		cout << "<center><font size=\"10\"<p style=\"color:green\">no virus found</p></font></center>";
	}
}