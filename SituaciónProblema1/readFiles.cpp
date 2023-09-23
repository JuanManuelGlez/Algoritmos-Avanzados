#include <string>
#include <vector>
#include <iostream>
#include <utility>
#include <fstream>

using namespace std;
vector<pair<vector<string>, vector<string>>> files;

void createStringsToRead(vector<string> &files, string extension){
  for (int i = 0; i < 7; i++){
    int temp = 1;
    while (temp <= 3){
      files.push_back(extension + to_string(i) + to_string(temp) + ".txt");
      temp++;
    }
  }
}

void makePairsVectorFiles(vector<string> mcodes, vector<string> transcodes){
  // Por cada 3 de mcode son 2 de transmisión
  int numPairs = mcodes.size() / 3;

  for (int i = 0; i < numPairs; i++){
    pair<vector<string>, vector<string>> temp;
    vector<string> mcodeTemp;
    vector<string> transTemp;
    for (int j = 0; j < 3 && (i + j) < mcodes.size(); j++){
      mcodeTemp.push_back(mcodes[i * 3 + j]);
    }
    temp.first = mcodeTemp;
    for (int k = 0; k < 2 && (i + k) < transcodes.size(); k++){
      transTemp.push_back(transcodes[i * 2 + k]);
    }
    temp.second = transTemp;
    files.push_back(temp);
  }
}

void makeLpsTable(string mcode, vector<int> &lpsTable){
  int j = 0; // Length of the previous longest prefix suffix

  lpsTable[0] = 0; // The longest proper prefix of the first character is always 0

  int i = 1;
  while (i < mcode.length()){
    if (mcode[i] == mcode[j]){
      j++;
      lpsTable[i] = j;
      i++;
    }
    else{
      if (j != 0){
        j = lpsTable[j - 1];
      }
      else{
        lpsTable[i] = 0;
        i++;
      }
    }
  }
}
// Lectura de archivos mcode cada 3 archivos pertenecen a
// 2 de transmisión

// string nombreArchivo = "mcode01.txt";
// ifstream archivo(nombreArchivo.c_str());

// Lectura de archivo de transmision

int main(int argc, char *argv[]){
  string mcodeTemp = "mcodes/mcode";
  string transTemp = "transmission/transmission";
  vector<string> mcodeFiles;
  vector<string> transFiles;
  createStringsToRead(mcodeFiles, mcodeTemp);
  createStringsToRead(transFiles, transTemp);
  makePairsVectorFiles(mcodeFiles, transFiles);
  for (int i = 0; i < files.size(); i++){
    vector<string> firstMcode = files[i].first;
    vector<string> firstTrans = files[i].second;
    for (int j = 0; j < firstMcode.size(); j++){
      ifstream mCode(firstMcode[j]);
      if (mCode.is_open()){
        string temp;
        while (mCode.good()){
          mCode >> temp;
          cout << temp;
        }
        vector<int> lps(temp.size());
        makeLpsTable(temp, lps);
        for (int x = 0; x < lps.size(); x++){
          cout << lps[x];
        }
        mCode.close();
        cout << endl;
      }
      else{
        std::cerr << "Unable to open file." << std::endl;
      }
    }
    cout << endl;
  }
}