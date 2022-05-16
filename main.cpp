/*
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <string>
using namespace std;
int main() {
    fstream datafile;
    ofstream targetfile;
    char token[101];
    char name[100];
    cout << "please enter file name";
    cin >> name;
    datafile.open(name);
    targetfile.open("target.text");
    if (datafile.fail()) {
        cout << "sorry,I could't open the file" << "\n";
        cout << "please enter the name of the file you want to create";
        cin >> name;
        datafile.open(name,ios::out );
        if (datafile.is_open())
        {
            datafile << "hello" <<endl;
        }
        cout << "file is opened successfully";
    } else
    {
        cout << "file is opened successfully";
    }
 /*   while (!datafile.eof())
    {
        datafile.getline(token, 100, '\n');
        targetfile<<token<<endl;
    }   */
  /*  targetfile << datafile.rdbuf();
    datafile.close();
    targetfile.close();
    return 0;
}
*/










/*
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    fstream datafile;
    char name[100];
    cout << "please enter file name and add extension (.txt) to it";
    cin >> name;
    datafile.open(name);
    if (datafile.fail())
    {
        cout << "sorry,I could't open the file" << "\n";
        cout << "please enter the name of the file you want to create";
        cin >> name;
        datafile.open(name,ios::out );
        if (datafile.is_open())
        {
            datafile << "file is opened successfully"<<endl;
            /* datafile << "my name is shrouk"<<endl;
             datafile << "it's a pleasure to meet you"<<endl; */
         /*   datafile.close();
        }
    }
    else
    {
        cout << "file is opened successfully"<<endl;
        datafile.close();
    }
    datafile.open(name,ios::in);
    if (datafile.is_open())
    {
        {
            int n;
            char word[100];
            string line,help;
            cout<<"please enter the word  you want to count its existence in your file"<<endl;
            cin>>word;
            while (getline(datafile,line))
            {
                help+=line;

            }
        }
    }
}
*/





#include <iostream>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <string>
#include <vector>
#include <sstream>
#include <utility>
#include <cstdlib>
using namespace std;
fstream file;
int displayMenu()
{
    int choice;
    cout<<"please choose one of these options"<<endl;
    cout<<"1- Count the number of times a word is repeated in the file"<<endl;
    cout<<"2- Turn the file content to upper case"<<endl;
    cout<<"3- Turn the file content to lower case"<<endl;
    cout<<"4- Turn file content to 1st caps (1st char of each word is capital)"<<endl;
    cout<<"5- count";
    cout<<"6- save"<<endl;
    cin>>choice;
    return choice;
}
void loadfile (vector<string>& text, fstream& file)
{
   char filename[100],line[100];
   cout<<"please enter your filename"<<endl;
   cin>>filename;
   file.open(filename);
   if (file.is_open())
   {
       cout<<"file is opened successfully"<<endl;
       while (!file.eof())
       {
           file.getline(line, 200, '\n');
           text.push_back(string (line) );
       }
   }
   else
   {
       char name[100];
       cout<<"this file couldn't be opened"<<endl;
       cout<<"please enter the name of the new file you want to create"<<endl;
       cin>>name;
       cout<<"a new file will be created when saving";
    /*   file.open(name);
       if (file.is_open())
       {
           file<<"hello";
       }  */
   }
}

int countNO_of_a_repeatedword(vector<string>& text)
{
    cout<<"please enter the word you are searching about how much times it was repeated"<<endl;
    char word[0][100];
    vector<char> trial;
    for (int i=0;i<100;i++)
    {
        cin>>word[0][i];
    }
    while (!file.eof())
    {
        for (int i=0;i<text.size();i++)
        {
            for (int j = 0; j < text[i].size(); j++)
            {
                if (word[0][j] == text[i][j])
                    trial.push_back(word[0][j]);

            }
        }
        cout<<"the word "<<word<<" was repeated in your file "<<trial.size()<<" times"<<endl;
    }













//    vector<char> repeatedword;
//    int n=text.size();
//    string arr[n];
//    while (!file.eof())
//    {
//        for (int i=0;i<n;i++)
//        {
//            getline ( file,arr[i],'\n');
//
//        }
//        for (char letter:word)
//        {
//            for (int i=0;i<text.size();i++)
//            {
//                for (int j=0;j<text[i].size();j++)
//                {
//                    if (word[0][j]==text[i][j])
//                        repeatedword.push_back(word);
//
//                }
//            }
//            cout<<"the word "<<word<<" was repeated in your file "<<repeatedword.size()<<" times"<<endl;
//
//        }
//
//    }





//    cout<<"please enter the word you are searching about how much times it was repeated"<<endl;
//    char word;
//    cin>>word;
//    vector<char> repeatedword;
//    while (!file.eof())
//    {
//        int wordcount=1;
//        for (int i=0;i<text.size();i++)
//        {
//            for (int j=0;j<text[i].size();j++)
//            {
//                if (word==text[i][j])
//                    repeatedword.push_back(word);
//
//            }
//            wordcount++;
//        }
//        cout<<"the word "<<word<<" was repeated in your file "<<repeatedword.size()<<" times"<<endl;
//    }
//    cout<<"please enter the word you are searching about how much times it was repeated"<<endl;
//    string word;
//    cin>>word;
//    vector<string> REPEATEDWORD;
//    while (!file.eof())
//    {
//        while (cin>>word)
//        {
//            REPEATEDWORD.push_back(word);
//        }
//        sort (text.begin(),text.end());
//        int vsize=text.size();
//        int wordcount=1;
//        word=text[0];
//        for (int i=0;i<text.size();i++)
//        {
//            if (word!=text[i])
//            {
//                cout<<"the word "<<word<<" was repeated in your file "<<wordcount<<" times"<<endl;
//                wordcount=0;
//                word=text[i];
//            }
//            wordcount++;
//        }
//        cout<<"the word "<<word<<" was repeated in your file "<<wordcount<<" times"<<endl;
//        return 0;
//    }



//    while (cin>>word)
//    {
//        REPEATEDWORD.push_back(word);
//    }
//    vector<string> helping_vector;
//    int c;
//    for (int i=0;i<text.size();i++)
//    {
//        for (int j=0,k=0;j<text[i].size();j++,k++)
//        {
//                if (REPEATEDWORD == text[i][j])
//                {
//                    helping_vector.push_back(word);
//
//                }
//        }
//    }
//    cout<<"the word "<<word<<" was repeated in your file "<<helping_vector.size()<<" times"<<endl;






//    char repeated_word[0][200];
//    char word;
//    cout<<"please enter the word you are searching about how much times it was repeated";
//    cin>>word;
//    int length=sizeof(repeated_word)/sizeof (repeated_word[0]);
//    for (int i=0;i<length;i=0)
//    {
//        for (int k=0;k<200;k++)
//        {
//            for(int c=0;c<sizeof word;c++)
//                repeated_word[0][k]=word;
//        }
//    }
//    vector<char> REPEATEDWORD;
//    vector<char> help;
//    int n;
//    for (int i=0,c=0;i<text.size();i++)
//    {
//        for (int j=0,k=0;j<text[i].size();j++,k++)
//        {
//                if (repeated_word[c][k] == text[i][j])
//                {
//                      REPEATEDWORD.push_back(repeated_word[c][k]);
//                }
//        }
//    }
//    cout<<"the word "<<word<<" was repeated in your file "<<REPEATEDWORD.size()<<" times"<<endl;
  /*  for (int i=0;i<text.size();i++)         //looping on every line of the vector
    {
        for (int j=0;j<text[i].size();j++)                   //looping on every word in every line of the vector
        {

        }
    }
    */
}


void convertTOlower(vector<string>& text)
{
    for (int i=0;i<text.size();i++)
    {
        for (int j=0;j<text[i].size();j++)
        {
            text[i][j]= tolower(text[i][j]);
        }
    }
}

void convertTOupper(vector<string>& text)
{
    for (int i=0;i<text.size();i++)
    {
        for (int j=0;j<text[i].size();j++)
        {
            text[i][j]= toupper(text[i][j]);
        }
    }
}

void count()
{
    ifstream ifs("shrouk");
    int words=0;
    string word;
    while (ifs>>word)
    {
        words++;
    }
    cout<<"no of words is: "<<words;
}

void first_caps(vector<string>& text)
{
    for (int i=0;i<text.size();i++)
    {
        for (int j=0;j<text[i].size();j++)
        {
            if (text[i][j]==char(32) || text[i][j]==char(44) || text[i][j]==char(46) || text[i][j]==char(33) || text[i][j]==char(58))
                text[i][j+1]=toupper(text[i][j+1]);
            if ((i==0&&j==0)) {
               for (int n=0;n<text.size();n++)
                   text[i+n][j]= toupper(text[i+n][j]);
            }
        }
    }
}

int main()
{
    fstream sourcefile;
    vector<string> text;
    loadfile(text,sourcefile);
    int choice;
   // count();
    while (true)
    {
        choice=displayMenu();
        if (choice == 1)
        {
            countNO_of_a_repeatedword(text);
            break;
        }
        if (choice == 2)
        {
            convertTOupper(text);
            for (string line : text)
                cout<<line<<endl;
            break;

        }
        else if (choice == 3)
        {
            convertTOlower(text);
            for (string line : text)
                cout<<line<<endl;
            break;
        }
        else if (choice == 4)
        {
            first_caps(text);
            for (string line : text)
                cout<<line<<endl;
            break;
        }
    }


  /*  for (string line : text)
        cout<<line<<endl; */
    return 0;
}