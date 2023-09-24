#include <string>
#include <vector>
#include <iostream>
#include <utility>
#include <fstream>

using namespace std;
vector<pair<vector<string>, vector<string>>> files;

bool isPalindrome(int left, int right, string mcode) {
    while(left <= right) {
        if(mcode[left] != mcode[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

void createStringsToRead(vector<string> &files, string extension){
  for (int i = 0; i < 7; i++){
    int temp = 1;
    while (temp <= 3){
      files.push_back(extension + to_string(i) + to_string(temp) + ".txt");
      temp++;
    }
  }
}

void createStringsToReadTransmission(vector<string> &files, string extension){
  for (int i = 0; i < 7; i++){
    int temp = 1;
    while (temp <= 2){
      files.push_back(extension + to_string(i) + to_string(temp) + ".txt");
      temp++;
    }
  }
}

vector<string> leerArchivo(vector<string> transmissions){
  vector<string> transmission;

  for(int i = 0 ; i < transmissions.size(); i++){
    string longitudArchivo;
    string archivo = transmissions[i];
    
    ifstream inFile(archivo);
    string line;
    while (getline(inFile, line)){
        longitudArchivo += line;
    }
    transmission.push_back(longitudArchivo);
  }
  return transmission;
}

void kmpApplication(vector<string> transmissions, vector<vector<int>> lpsTables, vector<string> target) {
    for (int x = 0; x < transmissions.size(); x++){ // Iterar dos veces para cada target
      for (int y = 0; y < target.size(); y++){ // Iterar tres veces para cada transmision
        int i = 0;
        int j = 0;
        string temp = transmissions[x];
        while(i < temp.length()){
            // Comparación mcode con transmision char por char
          if (target[y][j] == transmissions[x][i]){
            i++;
            j++;
          }
          // Comparación si j llegó a la longitud de la palabra de mcode
          if (j == target[y].length()){
            j = 0;
            cout << "Se encontró la palabra: " << target[y] << " en la pos " << (i - target[y].length()) + 1 << ", " << i + 1 << endl;
            cout << "En el archivo de transmisión: " << x + 1;
            cout << endl;
          }
          // j se va hacia atrás
          else if (i < temp.length() && target[y][j] != transmissions[x][i]){
            if (j != 0) {
                j = lpsTables[y][j - 1];
            }
            else {
                i++;
            }
          }
        }
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
    else {
      if (j != 0){
        j = lpsTable[j - 1];
      }
      else {
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
  createStringsToReadTransmission(transFiles, transTemp);
  makePairsVectorFiles(mcodeFiles, transFiles);
  for (int i = 0; i < files.size(); i++){
    vector<string> firstMcode = files[i].first;
    vector<string> firstTrans = files[i].second;
    vector<vector<int>> lpsTables;
    vector<string> transmissions;
    vector<string> mcodes;
    for (int j = 0; j < firstMcode.size(); j++){
      ifstream mCode(firstMcode[j]);
      if (mCode.is_open()){
        string temp;
        while (mCode.good()){
          mCode >> temp;
        }
        mcodes.push_back(temp);
        vector<int> lps(temp.size());
        makeLpsTable(temp, lps);
        lpsTables.push_back(lps);

        if (!isPalindrome(0, temp.size() - 1, temp)) {
          reverse(temp.begin(), temp.end());
          mcodes.push_back(temp);
          makeLpsTable(temp, lps);
          lpsTables.push_back(lps);
        }
        mCode.close();
      }
      else {
        cerr << "Unable to open file." << endl;
      }
    }
    transmissions = leerArchivo(firstTrans);
    kmpApplication(transmissions, lpsTables, mcodes);
    cout << endl;
  }
}