
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ifstream inputFile("data.txt");
    ofstream outputFile("data1.txt");
    string line;
    while (getline(inputFile, line))
    {
        size_t pos = 0;
        replace(line.begin(), line.end(), '[', '{');
        replace(line.begin(), line.end(), ']', '}');
        replace(line.begin(), line.end(), '\"', '\'');
        while ((pos = line.find("},", pos)) != string::npos)
        {
            line.insert(pos + 2, "\n");
            pos += 3; // 跳过新增的换行符
        }
        outputFile << line << endl;
    }
    inputFile.close();
    outputFile.close();
    return 0;
}