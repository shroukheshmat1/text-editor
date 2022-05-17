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
    
    void loadFile2 (vector <char>& text, ifstream& file){  // ifstream ---> input (read) only file
    char fileName[100], letter;   // The file name must be in C-string style "Array of characters"
    cout << "Please Enter the Name with its Extension of the Second File: " << endl;
    cin.getline(fileName, 100, '\n');
    file.open(fileName);
    if (file.is_open()){
        cout << "The Second File Opened Successfully :)" << endl;
        while (!file.eof()){
            file.get(letter); // Get letter by letter to make sure it reads the spaces too.
            text.emplace_back(letter); // text.push_back(string(line))
        }
        file.close();
    }
    else{
        cout << "I Will Create the File for You when Saving. :)";
    }
}


void mergeFiles(vector <char>& second, fstream& file1, ifstream& file2) {
    char fileName[100];
    cout << "Please Enter the Name with its Extension of the First File, You Want to Append on it: ";
    cin.getline(fileName, 100, '\n');
    file1.open(fileName, ios::app); // Open the File in Append Mode.
    if (file1.is_open()) {
        cout << "The First File Opened Successfully :)" << endl;
        loadFile2(second, file2);  // Load the Second File's Content into a Vector.
        for (char letter: second) {
            file1 << letter;  // Append Every Character in the 'second' Vector into the first file.
        }
        file1.close();
    }
    else{
        cout << "I Will Create the File for You when Saving. :)";
    }
}

void N_characters(vector<string>& text, ifstream& file) {
    int N_char = 0;
    loadFile(text, file);
    for (int i = 0; i < text.size(); i++) {  // Loop over the lines in the vector.
        N_char += text[i].size(); // Adding the number of characters in each line of the vector.
    }
    cout << "The Number of Characters in the File = " << N_char << endl;
    cout << "\"The White Spaces and Special Characters are Considered as Characters.\"";
    file.close();
}

void N_lines(vector<string>& text, ifstream& file){
    loadFile(text, file);
    int N_lines;
    N_lines = text.size();  // The Size of the Vector Represents the Number of Lines in the File.
    cout << "The Number of the Lines in the File = " << N_lines << endl;
}

void N_words(vector<string>& text, ifstream& file) {
    char fileName[100], ch;
    int n = 1;
    stringstream temp;
    cout << "Please Enter the File Name with the Extension, You Want to Edit on: " << endl;
    cin.getline(fileName, 100, '\n');
    file.open(fileName);
    if (file.is_open()) {
        cout << "The File Opened Successfully :)" << endl;
        while (!file.eof()) {
            file.get(ch);
            if (ch == ' ' || ch == '\n' || ch == ',' || ch == ';' || ch == '!' || ch == '?'){
                n++;
            }
        }
    }
    cout << "The Number of Words in the File = " << n << endl;
}

void firstCaps(vector<string>& text, ifstream& file){
    loadFile(text, file);
    int index, index2;
    if (file.is_open()) {
        cout << "The File Opened Successfully :)" << endl;
        for (string line: text) {
            for (char letter: line) {
                line.at(0) = toupper(line.at(0));
                cout << letter;
                if (letter == ' ') {
                    index = line.find(' ');
                    line.at(index + 1) = toupper(line.at(index + 1));
                    cout << line.at(index + 1) << endl;
                }
            }
        }
        file.close();
    }
}

void display_content(vector<string>& text, ifstream& file){
    loadFile(text, file);
    for (string line: text){
        cout << line << endl;
    }
}

void search_for_word(vector<string>& text, ifstream& file){
    string searchWord;
    bool found = false;
    loadFile(text, file);
    cout << "Please Enter the Word You Want to Search for: " << endl;
    getline(cin, searchWord);
    for (int i = 0; i < searchWord.length(); i++){
        searchWord.at(i) = tolower(searchWord.at(i));
    }

    for (int i = 0; i < text.size(); i++){
        for (int j = 0; j < text[i].size(); j++){
            text[i][j] = tolower(text[i][j]);
        }
    }

    for (string line: text){
        if (line.find(searchWord) != string :: npos) { // if the return of the find function not equal to the end of the string{
                cout << "The Word Has Been Found in this File. :)" << endl;
                found = true;
                break;
        }
    }
    if (!found) {
        cout << "Unfortunately, The Word Has NOT Been Found in this File. :(" << endl;
    }
    file.close();
}

void count_repeated_word(vector<string>& text, ifstream& file){
    string searchWord;
    bool found = false;
    int count = 0;
    loadFile(text, file);
    cout << "Please Enter the Word You Want to Search for: " << endl;
    getline(cin, searchWord);
    for (string line: text){
        if (line.find(searchWord) != string :: npos) { // if the return of the find function not equal to the end of the string
            count += 1;
            found = true;
        }
    }
    cout << "The Word Has Been Found in this File." << count << " Times." << endl;
    if (!found) {
        cout << "Unfortunately, The Word Has NOT Been Found in this File. :(" << endl;
    }
    file.close();
}

int displayMenu(int choice){
    cout << "WELCOME TO SRR TEXT EDITOR :)";
    cout << "\nPlease Choose the Number of the Edit You Want to Do:\n ";
    cout << "1.Add New Text to the End of the File.\n2.Display the Content of the File.\n"
            "3.Empty the File.\n4.Encrypt the File Content.\n5.Decrypt the File Content.\n"
            "6.Merge Another File.\n7.Count the Number of Words in the File.\n"
            "8.Count the Number of the Characters in the File\n9.Count the Number of the "
            "Lines in the File\n10.Search for a Word in the File\n11.Count the Number of Times"
            "a Word Exists in the File.\n12.Turn the File Content to Upper Case.\n"
            "13.Turn the File Content to Lower Case.\n14.Turn the File Content to 1st Cast.\n"
            "15.Save\n16.Exit." << endl;

    cin >> choice;
    return choice;
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
void add(string& text,ofstream& file)
{
    char filename[100];
    cout << "please enter the name of file:";
    cin.getline(filename, 100, '\n');
    cout<<"please add new text to file";
    getline(cin,text);
    file.open(filename,ios::app);
    if (file.is_open())
    {
        file<<text;
        file.close();
    }
}
//display content of a file
void dis(vector<string>& text,ifstream& file) {
    loadFile(text,file);
    for (string line :text)
        cout<<line<<endl;
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
void EMPTY(vector<string>& text,ofstream& file)
{
  // ofstream file(file);
    ofstream myfile;
    char filename[100];
    cin.getline(filename,100,'\n');
    file.open(filename,ios::trunc);
    file.close();
}
void encrypt(vector<string>& text,fstream& myfile) {
    char filename[100],ch;
    //ifstream file;
    //loadFile(text, myfile);
    cin.getline(filename, 100, '\n');
    myfile.open(filename);
    for (int i = 0; i < text.size(); i++) {
        for (int j = 0; j < text[i].size(); j++) {
            ch=++text[i][j];
            cout << ch;//text[i][j];
            myfile.open(filename,ios::out);
            myfile << ch << endl;
        }
    }
    myfile.close();

}
void decrypt(vector<string>& text,ofstream& myfile){
    char filename[100];
    cin.getline(filename,100,'\n');
    myfile.open(filename);
    for (int i=0;i<text.size();i++){
        for (int j=0;j<text[i].size();j++){
            text[i][j]--;
            cout<<text[i][j];
        }

    }
    myfile.close();

}


int main()
{
    ifstream sourcefile;
    fstream file;
    ofstream datafile;
    vector<string> text;
    int choice;
    string txt;
    while (true)
    {
        choice=displayMenu();
        if (choice == 1)
        {

            count_no_of_repeated_words();
            break;
        }
        if (choice == 2)
        {
            convertTOupper(text);
            break;
        }
        else if (choice == 3)
        {
            //loadfile(text,sourcefile);
            convertTOlower(text);
            break;
        }
        else if (choice == 4)
        {
            first_caps(text);
            break;
        }
        else if (choice == 5)
        {
            dis(text,sourcefile);
            break;
        }
        else if (choice == 6)
        {
            EMPTY(text,datafile);
            break;
        }
        else if (choice == 7)
        {
            add(txt,datafile);
            break;
        }
        else if (choice == 8)
        {
            encrypt( text,file);
            break;
        }
        else if (choice == 9)
        {
            decrypt( text,datafile);
            break;
        }
    }

    return 0;
}
