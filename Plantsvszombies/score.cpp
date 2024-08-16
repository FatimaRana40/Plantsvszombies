#include"Plants.h"
#include "score.h"
#include "Game.h"
#include <sstream>

Score::Score()
{
	myscore = 0;
    namepassed = "";
    passwordpassed = "";

}

void Score::setnameandpass(string  c, string d)
{
    namepassed = c;
    passwordpassed = d;
}
void Score::incrementscorelevel1()
{
	myscore+=500;
    ifstream readFile("players2.txt");
    ofstream writeFile("temp.txt");
    string line;
    bool scoreUpdated = false;
    int currentScore = 0; // assume current score is 0 if not found

    while (getline(readFile, line)) {
        istringstream iss(line);
        string userName, userPassword, scoreStr;
        getline(iss, userName, ',');
        getline(iss, userPassword, ',');
        getline(iss, scoreStr);
        userName.erase(0, userName.find_first_not_of(" \t\r\n"));
        userName.erase(userName.find_last_not_of(" \t\r\n") + 1);
        userPassword.erase(0, userPassword.find_first_not_of(" \t\r\n"));
        userPassword.erase(userPassword.find_last_not_of(" \t\r\n") + 1);


        if (userName == namepassed && userPassword == passwordpassed) { // check both name and password
            int score = stoi(scoreStr);
            if (score < currentScore || currentScore == 0) {
                currentScore = score +=myscore; // update score
                writeFile << userName << "," << userPassword << "," << currentScore << endl;
                cout << "name matched";
                scoreUpdated = true;
            }
            else {
                writeFile << line << endl; // retain existing score
            }
        }
        else {
            writeFile << line << endl;
        }

    }

    readFile.close();

    if (!scoreUpdated) {
        writeFile << namepassed << "," << passwordpassed << ",1" << endl; // new user, add to file
    }

    
    writeFile.close();

    remove("players2.txt");
    rename("temp.txt", "players2.txt");




}
int Score::getscore()
{
	return myscore;
}
void Score:: sortScores() {
    std::ifstream readFile("players2.txt");
    std::ofstream writeFile("temp.txt");
    std::string line;
    int count = 0;

    // Count number of users
    while (std::getline(readFile, line)) {
        ++count;
    }
    readFile.close();

    // Re-open file to read user data
    readFile.open("players2.txt");

    // Arrays to store user data
    string* usernames = new string[count];
    string* passwords = new string[count];
    int* scores = new int[count];
   /* std::string usernames[count];
    std::string passwords[count];
    int scores[count];*/

    // Read user data
    for (int i = 0; i < count; ++i) {
        std::getline(readFile, line);
        std::istringstream iss(line);
        std::string userName, userPassword, scoreStr;
        std::getline(iss, userName, ',');
        std::getline(iss, userPassword, ',');
        std::getline(iss, scoreStr);

        scores[i] = std::stoi(scoreStr);
        usernames[i] = userName;
        passwords[i] = userPassword;
    }
    readFile.close();

    // Sort scores in descending order using manual swapping
    for (int i = 0; i < count - 1; ++i) {
        for (int j = 0; j < count - i - 1; ++j) {
            if (scores[j] < scores[j + 1]) {
                // Swap usernames
                std::string temp = usernames[j];
                usernames[j] = usernames[j + 1];
                usernames[j + 1] = temp;

                // Swap passwords
                temp = passwords[j];
                passwords[j] = passwords[j + 1];
                passwords[j + 1] = temp;

                // Swap scores
                int tempScore = scores[j];
                scores[j] = scores[j + 1];
                scores[j + 1] = tempScore;
            }
        }
    }

    // Write sorted scores back to the file
    for (int i = 0; i < count; ++i) {
        writeFile << usernames[i] << "," << passwords[i] << "," << scores[i] << std::endl;
    }

    writeFile.close();
    std::remove("players2.txt");
    std::rename("temp.txt", "players2.txt");
}
