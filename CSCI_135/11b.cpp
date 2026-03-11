// Daniel Andres Fernandez
// daniel.fernandez16@myhunter.cuny.edu
// December 5, 2022
// Lab 11B

#include <iostream>
using namespace std;

class Profile
{
private:
    string username;
    string displayname;

public:
    Profile(string usrn, string dspn); // Profile constructor for a user (initializing private variables username=usrn, displayname=dspn)
    Profile();                         // Default Profile constructor (username="", displayname="")
    string getUsername();              // Return username
    string getFullName();              // Return name in the format: "displayname (@username)"
    void setDisplayName(string dspn);  // Change display name
};

class Network
{
private:
    static const int MAX_USERS = 20; // max number of user profiles
    int numUsers;                    // number of registered users
    Profile profiles[MAX_USERS];     // user profiles array:
                                     // mapping integer ID -> Profile

    // Returns user ID (index in the 'profiles' array) by their username
    // (or -1 if username is not found)
    int findID(string usrn);

public:
    // Constructor, makes an empty network (numUsers = 0)
    Network();
    // Attempts to sign up a new user with specified username and displayname
    // return true if the operation was successful, otherwise return false
    bool addUser(string usrn, string dspn);
};

Profile::Profile(string usrn, string dspn)
{
    username = usrn;
    displayname = dspn;
}

Profile::Profile()
{
    username = "";
    displayname = "";
}

string Profile::getUsername()
{
    return username;
}

string Profile::getFullName()
{
    string name = " (@" + username + ")";
    string n = displayname + name;
    return n;
}

void Profile::setDisplayName(string dspn)
{
    displayname = dspn;
}

int Network::findID(string usrn)
{
    int id = -1;
    for (int i = 0; i <= numUsers; i++)
    {
        if (profiles[i].getUsername() == usrn)
        {
            return i;
        }
    }

    return id;
}

Network::Network()
{
    numUsers = 0;
}

bool Network::addUser(string usrn, string dspn)
{
    if (numUsers < MAX_USERS && findID(usrn) == -1)
    {
        for (int j = 0; j < usrn.length(); j++)
        {
            if (!isdigit(usrn[j]) && !isalpha(usrn[j]))
            {
                return false;
            }
        }

        Profile adding(usrn, dspn);
        profiles[numUsers] = adding;
        numUsers++;
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    Network nw;
    cout << nw.addUser("mario", "Mario") << endl;
    cout << nw.addUser("luigi", "Luigi") << endl;

    cout << nw.addUser("mario", "Mario2") << endl;
    cout << nw.addUser("mario 2", "Mario2") << endl;
    cout << nw.addUser("mario-2", "Mario2") << endl;

    for (int i = 2; i < 20; i++)
        cout << nw.addUser("mario" + to_string(i),
                           "Mario" + to_string(i))
             << endl;

    cout << nw.addUser("yoshi", "Yoshi") << endl;
}
