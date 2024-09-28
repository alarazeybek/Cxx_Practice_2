/**
* Author : Alara Zeybek
* ID: 22102544
* Section : 3
* Homework : 3
* Description : Creatures and Foods
*/
#include <iostream>
#include <string>
#include <queue>
#include <fstream>
#include "CreatureManager.h"
#include "FoodManager.h"
#include <iomanip>
using namespace std;

void const checkTheInput(string const str,CreatureManager& cm, FoodManager& fm);
void gameLoop(CreatureManager& cm, FoodManager& fm);

int main(int argc, char *argv[]){
    setprecision(3);
    CreatureManager cm;
    FoodManager fm;
    checkTheInput(argv[1], cm, fm);
    gameLoop(cm,fm);
    return 0;
}
void gameLoop(CreatureManager& cm, FoodManager& fm){
    int time = 0;
     while(!cm.allDead()){
         cm.printCreaturesLocations();
         fm.addFoodInGame(time);
         cm.BigGame(fm);
         fm.clearFoodInGame();
         time++;
    }
}
void const checkTheInput(string const str, CreatureManager& cm, FoodManager& fm){
    string inFile = str;
    int begin1 = 0, begin2 = 0;
    int entryCount = 0;
    ifstream infile;
    infile.open(str);
    if(!infile){
        cout << str << endl;
        cout << "Input file " << inFile << " does not exist" << endl;
    }
    else{
        infile >> begin1;
        while(!infile.eof()){
            queue<double> q; //using q as a temporary stack implementation just incase data.txt doesn't have the number of creatures in the top
            string num = "";
            string temp = "";
            entryCount = 0;
            infile>>temp;
            for(int i = 0; i< static_cast<int>(temp.length()); i++){
                char c = temp[i];
                if(c != ','){
                    num.push_back(c);
                    continue;
                }
                else {
                    double result = stod(num);
                    q.push(result);
                    entryCount++;
                    num = "";
                }
            }
            int result = stoi(num);
            q.push(result);
            entryCount++;
            if(entryCount == 4){
                int id = q.front(); q.pop();
                double x = q.front(); q.pop();
                double y = q.front(); q.pop();
                int health = q.front(); q.pop();
                Creature* temp = new Creature(id,x,y,health);
                cm.addCreature(temp);
            }
            else if(entryCount == 5){
                int id = q.front(); q.pop();
                double x = q.front(); q.pop();
                double y = q.front(); q.pop();
                int quality = q.front(); q.pop();
                int spawnTime =  q.front(); q.pop();
                Food* f = new Food(id,x,y,quality,spawnTime);
                fm.createAllFoodQueue(f);
            }
        }
    }
}