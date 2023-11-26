#include <iostream>
#include <regex>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct information 
{
    public :
        string date;
        string status;
        string C;
        string message;
};

int main(int argc, char *argv[])
{
    ifstream logFile;
    string line;
    
    string querry = "(.*?),\\s*(\\S*)\\s*(\\S*)\\s*(.*)";
    smatch querryMatchContent ;

    information infoObject ; 
    std::vector <information> objectsInformation  ;
   
    logFile.open("C:\\Users\\Ehsan\\Documents\\Visual Studio 2022\\sources\\task02\\test.txt");
    
    if (logFile.good())
    {
        while (getline(logFile,line))
        {
            regex querryRegex(querry); // the pattern
            bool querryMatch = regex_search(line, querryMatchContent , querryRegex);
            if (querryMatch) 
            {
                objectsInformation.push_back(infoObject);
                infoObject.date = querryMatchContent[1].str();
                infoObject.status = querryMatchContent[2].str();
                infoObject.C = querryMatchContent[3].str();
                infoObject.message = querryMatchContent[4].str();
               
            }
        }
    }
    
    logFile.close();
    
    return 0;
}